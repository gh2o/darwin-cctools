/*
 * The assembler driver as and runs the assembler for the "-arch <arch_flag>"
 * (if given) in ../libexec/as/<arch_flag>/as or
 * ../local/libexec/as/<arch_flag>/as.  Or runs the assembler for the host
 * architecture as returned by get_arch_from_host().  The driver only checks to
 * make sure their are not multiple arch_flags and then passes all flags to the
 * assembler it will run.
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "libc.h"
#include <sys/file.h>
#include <mach/mach.h>
#include "stuff/arch.h"
#include "stuff/errors.h"
#include "stuff/execute.h"
#include "stuff/allocate.h"
#include <mach-o/dyld.h>

/* used by error calls (exported) */
char *progname = NULL;

int
main(
int argc,
char **argv,
char **envp)
{
    const char *LIB = "../libexec/as/";
    const char *LOCALLIB = "../local/libexec/as/";
    const char *AS = "/as";
    const char *LLVM_MC = "llvm-mc";

    int i, j;
    uint32_t count, verbose, run_llvm_mc;
    char *p, c, *arch_name, *as, *as_local;
    char **llvm_mc_argv;
    char *prefix, buf[MAXPATHLEN], resolved_name[PATH_MAX];
    unsigned long bufsize;
    struct arch_flag arch_flag;
    const struct arch_flag *arch_flags, *family_arch_flag;
    enum bool oflag_specified;

	progname = argv[0];
	arch_name = NULL;
	verbose = 0;
	run_llvm_mc = 0;
	oflag_specified = FALSE;
	/*
	 * Construct the prefix to the assembler driver.
	 */
	bufsize = MAXPATHLEN;
	p = buf;
	i = _NSGetExecutablePath(p, &bufsize);
	if(i == -1){
	    p = allocate(bufsize);
	    _NSGetExecutablePath(p, &bufsize);
	}
	prefix = realpath(p, resolved_name);
	if(realpath == NULL)
	    system_fatal("realpath(3) for %s failed", p);
	p = rindex(prefix, '/');
	if(p != NULL)
	    p[1] = '\0';
	/*
	 * Process the assembler flags exactly like the assembler would (except
	 * let the assembler complain about multiple flags, bad combinations of
	 * flags, unknown single letter flags and the like).  The main thing
	 * here is to parse out the "-arch <arch_flag>" and to do so the
	 * multiple argument and multiple character flags need to be known how
	 * to be stepped over correctly.
	 */
	for(i = 1; i < argc; i++){
	    /*
	     * The assembler flags start with '-' except that "--" is recognized
	     * as assemble from stdin and that flag "--" is not allowed to be
	     * grouped with other flags (so "-a-" is not the same as "-a --").
	     */
	    if(argv[i][0] == '-' &&
	       !(argv[i][1] == '-' && argv[i][2] == '0')){
		/*
		 * the assembler allows single letter flags to be grouped
		 * together so "-abc" is the same as "-a -b -c".  So that
		 * logic must be followed here.
		 */
		for(p = &(argv[i][1]); (c = *p); p++){
		    /*
		     * The assembler simply ignores the high bit of flag
		     * characters and not treat them as different characters
		     * as they are (but the argument following the flag
		     * character is not treated this way).  So it's done
		     * here as well to match it.
		     */
		    c &= 0x7F;
		    switch(c){
		    /*
		     * Flags that take a single argument.  The argument is the
		     * rest of the current argument if there is any or the it is
		     * the next argument.  Again errors like missing arguments
		     * are not handled here but left to the assembler.
		     */
		    case 'o':	/* -o name */
			oflag_specified = TRUE;
		    case 'I':	/* -I directory */
		    case 'm':	/* -mc68000, -mc68010 and mc68020 */
		    case 'N':	/* -NEXTSTEP-deployment-target */
			if(p[1] == '\0')
			    i++;
			break;

		    case 'a':
			if(strcmp(p, "arch") == 0){
			    if(i + 1 >= argc)
				fatal("missing argument to %s option", argv[i]);
			    if(arch_name != NULL)
				fatal("more than one %s option (not allowed, "
				      "use cc(1) instead)", argv[i]);
			    arch_name = argv[i+1];
			    break;
			}
			/* fall through for non "-arch" */
		    case 'f':
		    case 'k':
		    case 'g':
		    case 'v':
		    case 'W':
		    case 'L':
		    default:
			/* just recognize it, do nothing */
			break;
		    case 'l':
			if(strcmp(p, "llvm-mc") == 0)
			    run_llvm_mc = i;
			/* also just recognize 'l' and do nothing */
			break;
		    case 'V':
			verbose = 1;
			break;
		    }
		}
	    }
	}

	/*
	 * If the -llvm-mc flag was specified then run llvm-mc from the same
	 * directory as the driver.
	 */
	if(run_llvm_mc != 0){
	    as = makestr(prefix, LLVM_MC, NULL);
	    if(access(as, F_OK) != 0){
		printf("%s: assembler (%s) not installed\n", progname, as);
		exit(1);
	    }
	    llvm_mc_argv = allocate(argc + 3);
	    llvm_mc_argv[0] = as;
	    j = 1;
	    for(i = 1; i < argc; i++){
		/*
		 * Do not pass -llvm-mc
		 */
		if(i != run_llvm_mc){
		    /*
		     * Do not pass command line argument that are Unknown to
		     * to llvm-mc.
		     */
		    if(strcmp(argv[i], "-v") != 0 &&
		       strcmp(argv[i], "-V") != 0 &&
		       strcmp(argv[i], "-force_cpusubtype_ALL") != 0){
			llvm_mc_argv[j] = argv[i];
			j++;
		    }
		}
	    }
	    /*
	     * Add -filetype=obj or llvm-mc will write to stdout.
	     */
	    llvm_mc_argv[j] = "-filetype=obj";
	    j++;
	    /*
	     * llvm-mc requires a "-o a.out" if not -o is specified.
	     */
	    if(oflag_specified == FALSE){
		llvm_mc_argv[j] = "-o";
		j++;
		llvm_mc_argv[j] = "a.out";
		j++;
	    }
	    llvm_mc_argv[j] = NULL;
	    if(execute(llvm_mc_argv, verbose))
		exit(0);
	    else
		exit(1);
	}

	/*
	 * Construct the name of the assembler to run from the given -arch
	 * <arch_flag> or if none then from the value returned from
	 * get_arch_from_host().
	 */
	if(arch_name == NULL){
	    if(get_arch_from_host(&arch_flag, NULL)){
#if __LP64__
		/*
		 * If runing as a 64-bit binary and on an Intel x86 host
		 * default to the 64-bit assember.
		 */
		if(arch_flag.cputype == CPU_TYPE_I386)
		    arch_flag = *get_arch_family_from_cputype(CPU_TYPE_X86_64);
#endif /* __LP64__ */
		arch_name = arch_flag.name;
	    }
	    else
		fatal("unknown host architecture (can't determine which "
		      "assembler to run)");
	}
	else{
	    /*
	     * Convert a possible machine specific architecture name to a
	     * family name to base the name of the assembler to run.
	     */
	    if(get_arch_from_flag(arch_name, &arch_flag) != 0){
		family_arch_flag =
			get_arch_family_from_cputype(arch_flag.cputype);
		if(family_arch_flag != NULL)
		    arch_name = (char *)(family_arch_flag->name);
	    }

	}
	/*
	 * If this assembler exist try to run it else print an error message.
	 */
	as = makestr(prefix, LIB, arch_name, AS, NULL);
	if(access(as, F_OK) == 0){
	    argv[0] = as;
	    if(execute(argv, verbose))
		exit(0);
	    else
		exit(1);
	}
	as_local = makestr(prefix, LOCALLIB, arch_name, AS, NULL);
	if(access(as_local, F_OK) == 0){
	    argv[0] = as_local;
	    if(execute(argv, verbose))
		exit(0);
	    else
		exit(1);
	}
	printf("%s: assembler (%s or %s) for architecture %s not installed\n",
	       progname, as, as_local, arch_name);
	arch_flags = get_arch_flags();
	count = 0;
	for(i = 0; arch_flags[i].name != NULL; i++){
	    as = makestr(prefix, LIB, arch_flags[i].name, AS, NULL);
	    if(access(as, F_OK) == 0){
		if(count == 0)
		    printf("Installed assemblers are:\n");
		printf("%s for architecture %s\n", as, arch_flags[i].name);
		count++;
	    }
	    else{
		as_local = makestr(prefix, LOCALLIB, arch_flags[i].name, AS,
				   NULL);
		if(access(as_local, F_OK) == 0){
		    if(count == 0)
			printf("Installed assemblers are:\n");
		    printf("%s for architecture %s\n", as_local,
			   arch_flags[i].name);
		    count++;
		}
	    }
	}
	if(count == 0)
	    printf("%s: no assemblers installed\n", progname);
	exit(1);
}
