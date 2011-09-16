# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([cctools], [806], [cctools@localhost])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

CCTOOLS_VERSION=cctools-806
LD64_VERSION=ld64-123.2.1

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

AM_CONDITIONAL([TARGET_ARM], [test $target_cpu = arm])

# Automake
AM_INIT_AUTOMAKE([1.11 foreign subdir-objects silent-rules])
AM_MAINTAINER_MODE

# Options
AC_ARG_WITH(
	[llvm],
	[AS_HELP_STRING([[--with-llvm[=/usr]]], [location of LLVM installation])],
	[],
	[with_llvm="/usr"]
)

AC_ARG_WITH(
	[sysroot],
	[AS_HELP_STRING([--with-sysroot=PATH], [location of target system root])],
	[],
	[with_sysroot=""]
)

# Add options
if test -n "$with_sysroot"; then
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

AC_PATH_PROG([llvm_config], [llvm-config], [], [$with_llvm/bin])
if test "x$llvm_config" = "x"; then
	AC_MSG_ERROR([llvm-config not found.])
fi

CPPFLAGS="${CPPFLAGS} `$llvm_config --cppflags`"

AC_SUBST([LLVM_LDFLAGS], [`$llvm_config --ldflags`])
AC_SUBST([LLVM_LIBS], [`$llvm_config --libfiles`])
AC_SUBST([LLVM_LIBDIR], [`$llvm_config --libdir`])
AC_SUBST([LLVM_INCLUDEDIR], [`$llvm_config --includedir`])

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

# Checks for header files.
AC_CHECK_HEADER(
	[llvm-c/lto.h],
	[true],
	[AC_MSG_ERROR([LLVM headers not found.])]
)
AC_CHECK_HEADER(
	[uuid/uuid.h],
	[true],
	[AC_MSG_ERROR([UUID headers not found.])]
)

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_C_BIGENDIAN
AM_CONDITIONAL([IS_BIG_ENDIAN], [test x$ac_cv_c_bigendian = xyes])

# Checks for library functions.
AC_CHECK_FUNCS([strmode])
AM_CONDITIONAL([HAVE_STRMODE], [test x$ac_cv_func_strmode = xyes])

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
