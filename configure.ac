AC_INIT([gtkglcanvasmm], [0.1])
AM_INIT_AUTOMAKE([1.11 subdir-objects])
AC_CONFIG_MACRO_DIRS([m4])

AM_SILENT_RULES([yes])
AC_CONFIG_HEADERS([gtkglcanvasmm-config.h])
AC_CONFIG_FILES([Makefile src/example/Makefile src/libgtkglcanvasmm/Makefile
        src/libgtkglcanvasmm/gtkglcanvasmm.pc])

AM_PROG_AR
LT_INIT([])
AC_PROG_CXX

AX_CXX_COMPILE_STDCXX_11([], [mandatory])

AC_CANONICAL_HOST
case $host_os in
  *mingw*)
    platform_win32=yes
    native_win32=yes
    ;;
  pw32* | *cygwin*)
    platform_win32=yes
    native_win32=no
    ;;
  *)
    platform_win32=no
    native_win32=no
    ;;
esac

srcdir=`readlink -f "$srcdir"`
builddir=`readlink -f "$top_builddir"`

cppflags="-I$srcdir/include -I$srcdir/src -I$builddir"
cppflags+=" -Wall -Wextra -Wconversion -Wsign-conversion"
cflags="-Wno-unused-parameter"
cxxflags="-Wsuggest-override -Wuninitialized -Winit-self "
cxxflags+="-Wsuggest-final-types -Wsuggest-final-methods -Wold-style-cast"

PKG_CHECK_MODULES([GLIBMM], [glibmm-2.4], [],
    [AC_MSG_ERROR([Missing dependency: glibmm 2.4])])
PKG_CHECK_MODULES([GTKMM3], [gtkmm-3.0], [],
    [AC_MSG_ERROR([Missing dependency: gtkmm 3.0])])
PKG_CHECK_MODULES([GtkGLCanvas], [gtkglcanvas], [],
    [AC_MSG_ERROR([Missing dependency: GtkGLCanvas (Download from http://github.com/fknorr/gtkglcanvas)])])

AC_SUBST([AM_CPPFLAGS], [$cppflags])
AC_SUBST([AM_CFLAGS], [$cflags])
AC_SUBST([AM_CXXFLAGS], [$cxxflags])

if test "x$prefix" = "xNONE" ; then
    prefix="/usr/local"
fi
if test "x$exec_prefix" = "xNONE" ; then
    exec_prefix=$prefix
fi

AM_CONDITIONAL(PLATFORM_WIN32, test x"$platform_win32" = "xyes")
AM_CONDITIONAL(NATIVE_WIN32, test x"$native_win32" = "xyes")

AC_OUTPUT([])
