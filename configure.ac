AC_INIT(ceferino, 0.97.9)
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AC_PREREQ([2.61])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADER([config.h])

AM_MAINTAINER_MODE

AC_PROG_CXX

dnl gettext, soporte para idiomas
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION(0.16.1)
AC_SUBST(localedir)
ALL_LINGUAS="es fr ca"

GETTEXT_PACKAGE=$PACKAGE
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["${GETTEXT_PACKAGE}"], [gettext domain])

dnl Busca las bibliotecas SDL
AC_CHECK_LIB(SDL, SDL_Init, , \
	AC_MSG_ERROR([* Can't find SDL library: http://www.libsdl.org]))

AC_CHECK_LIB(SDL_image, IMG_Load, , \
	AC_MSG_ERROR([* Can't find SDL_image library: http://www.libsdl.org]))

AC_CHECK_LIB(SDL_mixer, Mix_OpenAudio, , \
	AC_MSG_ERROR([* Can't find SDL_mixer library: http://www.libsdl.org]))


AC_SUBST(DEPS_CFLAGS)
AC_SUBST(DEPS_LIBS)

AC_OUTPUT([
	Makefile
	src/Makefile
	data/Makefile
	po/Makefile.in
	data/ima/Makefile
	data/levels/Makefile
	data/music/Makefile
	data/sounds/Makefile
])
