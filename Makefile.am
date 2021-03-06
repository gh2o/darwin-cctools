########################################
# flags                                #
########################################

CORE_CPPFLAGS = \
	-I$(top_srcdir)/emu/include \
	-DNeXT_MOD \
	-D_GNU_SOURCE \
	-D_DARWIN_C_SOURCE \
	-D__DARWIN_UNIX03 \
	-DLTO_SUPPORT

if !HAVE_PRIVATE_EXTERN
  CORE_CPPFLAGS += -D__private_extern__=extern
endif

if IS_BIG_ENDIAN
  CORE_CPPFLAGS += -D__BIG_ENDIAN__
else
  CORE_CPPFLAGS += -D__LITTLE_ENDIAN__
endif

AM_CPPFLAGS = \
	-I$(top_srcdir)/cctools/include \
	$(CORE_CPPFLAGS)

AM_CFLAGS = -Wall -Wno-enum-compare -Wno-unused-but-set-variable
AM_CXXFLAGS = -Wall -Wno-deprecated -Wno-unused-but-set-variable

########################################
# manpages                             #
########################################

man_MANS = \
	cctools/man/as.1 \
	cctools/man/check_dylib.1 \
	cctools/man/checksyms.1 \
	cctools/man/cmpdylib.1 \
	cctools/man/codesign_allocate.1 \
	cctools/man/ctf_insert.1 \
	cctools/man/dyld.1 \
	cctools/man/gprof.1 \
	cctools/man/indr.1 \
	cctools/man/install_name_tool.1 \
	cctools/man/libtool.1 \
	cctools/man/lipo.1 \
	cctools/man/mtoc.1 \
	cctools/man/nm.1 \
	cctools/man/nmedit.1 \
	cctools/man/otool.1 \
	cctools/man/pagestuff.1 \
	cctools/man/ranlib.1 \
	cctools/man/redo_prebinding.1 \
	cctools/man/seg_addr_table.1 \
	cctools/man/segedit.1 \
	cctools/man/size.1 \
	cctools/man/strings.1 \
	cctools/man/strip.1 \
	\
	cctools/ar/ar.1 \
	ld64/doc/man/man1/ld.1

########################################
# programs and libraries               #
########################################

noinst_LIBRARIES = libs/libstuff.a libs/libemu.a
bin_PROGRAMS = \
	tools/ar \
	tools/as \
	tools/ld \
	tools/otool \
	\
	tools/ranlib \
	tools/nmedit \
	\
	tools/check_dylib \
	tools/checksyms \
	tools/cmpdylib \
	tools/codesign_allocate \
	tools/ctf_insert \
	tools/indr \
	tools/inout \
	tools/install_name_tool \
	tools/libtool \
	tools/lipo \
	tools/nm \
	tools/pagestuff \
	tools/redo_prebinding \
	tools/seg_addr_table \
	tools/segedit \
	tools/seg_hack \
	tools/size \
	tools/strings \
	tools/strip

LDADD = $(noinst_LIBRARIES)

########################################
# libemu                               #
########################################

libs_libemu_a_SOURCES = \
	emu/log.c \
	emu/host.c \
	emu/mach.c \
	emu/ns.c \
	emu/version.c \
	emu/vm.c \
	emu/strmode.c \
	emu/strlcc.c \
	emu/qsort.c

########################################
# libstuff                             #
########################################

libs_libstuff_a_SOURCES = \
	cctools/libstuff/allocate.c \
	cctools/libstuff/arch.c \
	cctools/libstuff/arch_usage.c \
	cctools/libstuff/best_arch.c \
	cctools/libstuff/breakout.c \
	cctools/libstuff/bytesex.c \
	cctools/libstuff/checkout.c \
	cctools/libstuff/coff_bytesex.c \
	cctools/libstuff/crc32.c \
	cctools/libstuff/dylib_roots.c \
	cctools/libstuff/dylib_table.c \
	cctools/libstuff/errors.c \
	cctools/libstuff/execute.c \
	cctools/libstuff/fatal_arch.c \
	cctools/libstuff/fatals.c \
	cctools/libstuff/get_arch_from_host.c \
	cctools/libstuff/get_toc_byte_sex.c \
	cctools/libstuff/guess_short_name.c \
	cctools/libstuff/hash_string.c \
	cctools/libstuff/hppa.c \
	cctools/libstuff/lto.c \
	cctools/libstuff/llvm.c \
	cctools/libstuff/macosx_deployment_target.c \
	cctools/libstuff/ofile.c \
	cctools/libstuff/ofile_error.c \
	cctools/libstuff/ofile_get_word.c \
	cctools/libstuff/print.c \
	cctools/libstuff/reloc.c \
	cctools/libstuff/rnd.c \
	cctools/libstuff/seg_addr_table.c \
	cctools/libstuff/set_arch_flag_name.c \
	cctools/libstuff/swap_headers.c \
	cctools/libstuff/symbol_list.c \
	cctools/libstuff/SymLoc.c \
	cctools/libstuff/unix_standard_mode.c \
	cctools/libstuff/version_number.c \
	cctools/libstuff/writeout.c

########################################
# as                                   #
########################################

tools_as_SOURCES = \
	cctools/as/as.c \
	cctools/as/messages.c \
	cctools/as/xmalloc.c \
	cctools/as/symbols.c \
	cctools/as/sections.c \
	cctools/as/read.c \
	cctools/as/input-scrub.c \
	cctools/as/dwarf2dbg.c \
	cctools/as/layout.c \
	cctools/as/write_object.c \
	cctools/as/hash.c \
	cctools/as/frags.c \
	cctools/as/expr.c \
	cctools/as/app.c \
	cctools/as/fixes.c \
	cctools/as/input-file.c \
	cctools/as/hex-value.c \
	cctools/as/atof-generic.c \
	cctools/as/flonum-const.c \
	cctools/as/flonum-copy.c \
	cctools/as/flonum-mult.c \
	cctools/as/atof-ieee.c \
	cctools/as/obstack.c

tools_as_CPPFLAGS = $(AM_CPPFLAGS)

if TARGET_ARM
  tools_as_SOURCES += cctools/as/arm.c
  tools_as_CPPFLAGS += -DARM
endif

########################################
# ld                                   #
########################################

tools_ld_SOURCES = \
	ld64/src/ld/ld.cpp \
	ld64/src/ld/Options.cpp \
	ld64/src/ld/InputFiles.cpp \
	ld64/src/ld/Resolver.cpp \
	ld64/src/ld/OutputFile.cpp \
	ld64/src/ld/SymbolTable.cpp \
	ld64/src/ld/debugline.c \
	\
	ld64/src/ld/passes/objc.cpp \
	ld64/src/ld/passes/huge.cpp \
	ld64/src/ld/passes/got.cpp \
	ld64/src/ld/passes/tlvp.cpp \
	ld64/src/ld/passes/order.cpp \
	ld64/src/ld/passes/branch_shim.cpp \
	ld64/src/ld/passes/branch_island.cpp \
	ld64/src/ld/passes/dtrace_dof.cpp \
	ld64/src/ld/passes/compact_unwind.cpp \
	ld64/src/ld/passes/dylibs.cpp \
	ld64/src/ld/passes/stubs/stubs.cpp \
	\
	ld64/src/ld/parsers/archive_file.cpp \
	ld64/src/ld/parsers/macho_dylib_file.cpp \
	ld64/src/ld/parsers/macho_relocatable_file.cpp \
	ld64/src/ld/parsers/opaque_section_file.cpp

tools_ld_CPPFLAGS = $(CORE_CPPFLAGS) \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/abstraction
	
tools_ld_LDFLAGS = $(AM_LDFLAGS) 
tools_ld_LDADD = $(LDADD)

if HAVE_LLVM
tools_ld_CPPFLAGS += $(LLVM_CPPFLAGS)
tools_ld_LDFLAGS += $(LLVM_LDFLAGS)
tools_ld_LDADD += $(LLVM_LIBDIR)/libLTO.a $(LLVM_LIBFILES)
tools_ld_SOURCES += ld64/src/ld/parsers/lto_file.cpp
else
tools_ld_SOURCES += ld64/src/ld/parsers/lto_file_stub.cpp
endif

########################################
# ar                                   #
########################################

tools_ar_SOURCES = \
	cctools/ar/ar.c \
	cctools/ar/archive.c \
	cctools/ar/misc.c \
	cctools/ar/append.c \
	cctools/ar/contents.c \
	cctools/ar/delete.c \
	cctools/ar/extract.c \
	cctools/ar/move.c \
	cctools/ar/print.c \
	cctools/ar/replace.c

########################################
# otool                                #
########################################

tools_otool_SOURCES = \
	cctools/otool/arm_disasm.c \
	cctools/otool/coff_print.c \
	cctools/otool/hppa_disasm.c \
	cctools/otool/i386_disasm.c \
	cctools/otool/i860_disasm.c \
	cctools/otool/m68k_disasm.c \
	cctools/otool/m88k_disasm.c \
	cctools/otool/main.c \
	cctools/otool/ofile_print.c \
	cctools/otool/ppc_disasm.c \
	cctools/otool/print_objc2_32bit.c \
	cctools/otool/print_objc2_64bit.c \
	cctools/otool/print_objc.c \
	cctools/otool/sparc_disasm.c

########################################
# misc                                 #
########################################
tools_ranlib_SOURCES            = cctools/misc/libtool.c
tools_ranlib_CPPFLAGS           = $(AM_CPPFLAGS) -DLIBTOOL_AS_RANLIB

tools_nmedit_SOURCES            = cctools/misc/strip.c
tools_nmedit_CPPFLAGS           = $(AM_CPPFLAGS) -DNMEDIT

tools_check_dylib_SOURCES       = cctools/misc/check_dylib.c
tools_checksyms_SOURCES         = cctools/misc/checksyms.c
tools_cmpdylib_SOURCES          = cctools/misc/cmpdylib.c
tools_codesign_allocate_SOURCES = cctools/misc/codesign_allocate.c
tools_ctf_insert_SOURCES        = cctools/misc/ctf_insert.c
tools_indr_SOURCES              = cctools/misc/indr.c
tools_inout_SOURCES             = cctools/misc/inout.c
tools_install_name_tool_SOURCES = cctools/misc/install_name_tool.c
tools_libtool_SOURCES           = cctools/misc/libtool.c
tools_lipo_SOURCES              = cctools/misc/lipo.c
tools_nm_SOURCES                = cctools/misc/nm.c
tools_pagestuff_SOURCES         = cctools/misc/pagestuff.c
tools_redo_prebinding_SOURCES   = cctools/misc/redo_prebinding.c
tools_seg_addr_table_SOURCES    = cctools/misc/seg_addr_table.c
tools_segedit_SOURCES           = cctools/misc/segedit.c
tools_seg_hack_SOURCES          = cctools/misc/seg_hack.c
tools_size_SOURCES              = cctools/misc/size.c 
tools_strings_SOURCES           = cctools/misc/strings.c
tools_strip_SOURCES             = cctools/misc/strip.c
