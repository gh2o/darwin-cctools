# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cctools], [822], [cctools@localhost])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

CCTOOLS_VERSION=cctools-822
LD64_VERSION=ld64-128.2

AC_DEFINE_UNQUOTED([CCTOOLS_VERSION], ["$CCTOOLS_VERSION"], [cctools version])
AC_DEFINE_UNQUOTED([LD64_VERSION], ["$LD64_VERSION"], [ld64 version])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AC_ARG_PROGRAM

AC_DEFUN([AC_TARGET_FAILURE], [
	AC_MSG_WARN([$1])
	AC_MSG_FAILURE([For an IOS toolchain, add --target=arm-apple-darwin10 to your command-line options.])
])

# Check target options
if test "x$target_os" != "xdarwin10"; then
	AC_TARGET_FAILURE([Target OS must be "darwin10".])
fi
if test "x$target_vendor" != "xapple"; then
	AC_TARGET_FAILURE([Target vendor must be "apple".])
fi

case "$target_cpu" in
	arm)
		;;
	*)
		AC_TARGET_FAILURE([Target CPU not supported.])
		;;
esac

AC_DEFINE_UNQUOTED([TARGET_TRIPLET], ["$target"], [Triplet for target host.])
AM_CONDITIONAL([TARGET_ARM], [test $target_cpu = arm])

# Automake
AM_INIT_AUTOMAKE([1.11 foreign subdir-objects silent-rules])
AM_MAINTAINER_MODE

# Options
AC_ARG_ENABLE(
	[llvm],
	[AS_HELP_STRING([[--enable-llvm[=/usr]]], [location of LLVM installation])],
	[],
	[enable_llvm=no]
)

AC_ARG_WITH(
	[sysroot],
	[AS_HELP_STRING([--with-sysroot=PATH], [location of target system root])],
	[],
	[with_sysroot=no]
)

# Add options
if test "x$with_sysroot" != "xno"; then
	if test "x$with_sysroot" = "xyes"; then
		AC_MSG_FAILURE([--with-sysroot= requires a path.])
	fi
	AC_DEFINE_UNQUOTED([DC_SYSROOT], ["$with_sysroot"], [target system root])
fi

# Defaults
: ${CFLAGS=""}
: ${CXXFLAGS=""}
: ${CPPFLAGS=""}

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

AM_PROG_CC_C_O

# Check for LLVM.
if test "x$enable_llvm" != "xno"; then
	if test "x$enable_llvm" = "xyes"; then
		enable_llvm="/usr"
	fi
	
	AC_PATH_PROG([llvm_config], [llvm-config], [], [$enable_llvm/bin])
	if test "x$llvm_config" = "x"; then
		AC_MSG_ERROR([llvm-config not found.])
	fi

	CPPFLAGS="${CPPFLAGS} `$llvm_config --cppflags`"

	AC_SUBST([LLVM_LDFLAGS], [`$llvm_config --ldflags`])
	AC_SUBST([LLVM_LIBS], [`$llvm_config --libfiles`])
	AC_SUBST([LLVM_LIBDIR], [`$llvm_config --libdir`])
	AC_SUBST([LLVM_INCLUDEDIR], [`$llvm_config --includedir`])
	
	AC_DEFINE([HAVE_LLVM], [1], [Define if using LLVM.])
	AM_CONDITIONAL([HAVE_LLVM], [true])
else
	AM_CONDITIONAL([HAVE_LLVM], [false])
fi

# Checks for libraries.
AC_SEARCH_LIBS(
	[MD5_Init], [ssl crypto],
	[true],
	[AC_MSG_FAILURE([Library for MD5 not found.])]
)
AC_SEARCH_LIBS(
	[uuid_generate_random], [uuid],
	[true],
	[AC_MSG_FAILURE([UUID library not found.])]
)
AC_SEARCH_LIBS(
	[dlsym], [dl],
	[true],
	[AC_MSG_FAILURE([dlsym not found.])]
)
AC_SEARCH_LIBS(
	[clock_gettime], [rt],
	[true],
	[AC_MSG_FAILURE([clock_gettime not found.])]
)

# Checks for header files.
AC_CHECK_HEADER(
	[uuid/uuid.h],
	[true],
	[AC_MSG_FAILURE([UUID headers not found.])]
)

if test "x$enable_llvm" != "xno"; then
	AC_CHECK_HEADER(
		[llvm-c/lto.h],
		[true],
		[AC_MSG_FAILURE([LLVM headers not found.])]
	)
fi

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_C_BIGENDIAN
AM_CONDITIONAL([IS_BIG_ENDIAN], [test x$ac_cv_c_bigendian = xyes])

# Checks for library functions.
AC_CHECK_FUNCS([strmode])
AC_CHECK_FUNC(
	[qsort_r],
	[
		AC_LANG_PUSH([C])
		
		AC_CACHE_CHECK([if qsort_r is GNU-style], [my_cv_func_qsort_r_gnu], [
			AC_RUN_IFELSE(
				[AC_LANG_SOURCE([
					#include <stdlib.h>
					int comp (const void *l, const void *r, void *x) { return 0; }
					int arr[[]] = { 1, 0 };
					int main ()
					{
						qsort_r (arr, 2, sizeof (int), comp, NULL);
						return 0;
					}
				])],
				[my_cv_func_qsort_r_gnu=yes],
				[my_cv_func_qsort_r_gnu=no]
			)
		])
		
		AC_CACHE_CHECK([if qsort_r is BSD-style], [my_cv_func_qsort_r_bsd], [
			AC_RUN_IFELSE(
				[AC_LANG_SOURCE([
					#include <stdlib.h>
					int comp (void *x, const void *l, const void *r) { return 0; }
					int arr[[]] = { 1, 0 };
					int main ()
					{
						qsort_r (arr, 2, sizeof (int), NULL, comp);
						return 0;
					}
				])],
				[my_cv_func_qsort_r_bsd=yes],
				[my_cv_func_qsort_r_bsd=no]
			)
		])
		
		AC_LANG_POP([C])
		
		if test "x$my_cv_func_qsort_r_gnu" = "x$my_cv_func_qsort_r_bsd"; then
			AC_MSG_FAILURE([qsort_r has unknown semantics.])
		fi
		
		if test "x$my_cv_func_qsort_r_gnu" = "xyes"; then
			AC_DEFINE([QSORT_R_IS_GNU], [1], [Define if qsort_r is GNU-style.])
		fi
		
		if test "x$my_cv_func_qsort_r_bsd" = "xyes"; then
			AC_DEFINE([QSORT_R_IS_BSD], [1], [Define if qsort_r is BSD-style.])
		fi
	],
	[AC_MSG_FAILURE([qsort_r not found.])]
)

# Other checks.
AC_CACHE_CHECK([whether the compiler supports __private_extern__], [my_cv_cc_private_extern_supports], [
	AC_LANG_PUSH([C])
	AC_COMPILE_IFELSE(
		[AC_LANG_SOURCE([ __private_extern__ int test; ])],
		[my_cv_cc_private_extern_supports=yes],
		[my_cv_cc_private_extern_supports=no]
	)
	AC_LANG_POP([C])
])
AM_CONDITIONAL([HAVE_PRIVATE_EXTERN], [test x$my_cv_cc_private_extern_supports = xyes])

AC_OUTPUT
