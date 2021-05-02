EXTRA_LTLIBRARIES =
noinst_LTLIBRARIES =

libgtk_extensions_sources =
libgtk_extensions_sources += gtk-menu-option.c
libgtk_extensions_sources += gtk-menu-option.h
libgtk_extensions_sources += gtk-options.c
libgtk_extensions_sources += gtk-options.h

libgtk_extensions_cflags =
libgtk_extensions_cflags += $(AM_CFLAGS)
libgtk_extensions_cflags += $(CFLAGS)
libgtk_extensions_cflags += -I$(top_srcdir)

libgtk_extensions_libadd =


if HAVE_GTK2
noinst_LTLIBRARIES += libgtk-extensions-gtk2.la
else
EXTRA_LTLIBRARIES  += libgtk-extensions-gtk2.la
endif

libgtk_extensions_gtk2_la_SOURCES = $(libgtk_extensions_sources)
libgtk_extensions_gtk2_la_CFLAGS  = $(libgtk_extensions_cflags)
libgtk_extensions_gtk2_la_LIBADD  = $(libgtk_extensions_libadd)

libgtk_extensions_gtk2_la_CFLAGS += $(GTK2_CFLAGS)
libgtk_extensions_gtk2_la_LIBADD += $(GTK2_LIBS)


if HAVE_GTK3
noinst_LTLIBRARIES += libgtk-extensions-gtk3.la
else
EXTRA_LTLIBRARIES  += libgtk-extensions-gtk3.la
endif

libgtk_extensions_gtk3_la_SOURCES = $(libgtk_extensions_sources)
libgtk_extensions_gtk3_la_CFLAGS  = $(libgtk_extensions_cflags)
libgtk_extensions_gtk3_la_LIBADD  = $(libgtk_extensions_libadd)

libgtk_extensions_gtk3_la_CFLAGS += $(GTK3_CFLAGS)
libgtk_extensions_gtk3_la_LIBADD += $(GTK3_LIBS)
