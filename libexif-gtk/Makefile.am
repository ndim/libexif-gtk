EXTRA_LTLIBRARIES =
lib_LTLIBRARIES =

libexif_gtkincludedir = $(includedir)/libexif-gtk
libexif_gtkinclude_HEADERS = \
	gtk-exif-browser.h			\
	gtk-exif-content-list.h		\
	gtk-exif-entry.h			\
	gtk-exif-entry-ascii.h		\
	gtk-exif-entry-copyright.h	\
	gtk-exif-entry-date.h		\
	gtk-exif-entry-generic.h	\
	gtk-exif-entry-flash.h		\
	gtk-exif-entry-number.h		\
	gtk-exif-entry-option.h		\
	gtk-exif-entry-rational.h	\
	gtk-exif-entry-resolution.h	\
	gtk-exif-entry-user-comment.h	\
	gtk-exif-entry-version.h

libexif_gtk_sources =
libexif_gtk_sources += gtk-exif-browser.c
libexif_gtk_sources += gtk-exif-content-list.c
libexif_gtk_sources += gtk-exif-entry.c
libexif_gtk_sources += gtk-exif-entry-ascii.c
libexif_gtk_sources += gtk-exif-entry-copyright.c
libexif_gtk_sources += gtk-exif-entry-date.c
libexif_gtk_sources += gtk-exif-entry-generic.c
libexif_gtk_sources += gtk-exif-entry-flash.c
libexif_gtk_sources += gtk-exif-entry-number.c
libexif_gtk_sources += gtk-exif-entry-option.c
libexif_gtk_sources += gtk-exif-entry-rational.c
libexif_gtk_sources += gtk-exif-entry-resolution.c
libexif_gtk_sources += gtk-exif-entry-user-comment.c
libexif_gtk_sources += gtk-exif-entry-version.c
libexif_gtk_sources += gtk-exif-util.h

libexif_gtk_cflags =
libexif_gtk_cflags += $(AM_CPPFLAGS)
libexif_gtk_cflags += $(CPPFLAGS)
libexif_gtk_cflags += -I$(top_srcdir)
libexif_gtk_cflags += -I$(top_srcdir)/gtk-extensions
libexif_gtk_cflags += $(LIBEXIF_CFLAGS)
libexif_gtk_cflags += -DG_LOG_DOMAIN=\"libexif\"
libexif_gtk_cflags += -Wno-deprecated

libexif_gtk_ldflags =
libexif_gtk_ldflags += $(AM_LDFLAGS)
libexif_gtk_ldflags += $(LDFLAGS)
libexif_gtk_ldflags += -version-info @LIBEXIF_GTK_VERSION_INFO@

libexif_gtk_libadd =
libexif_gtk_libadd += $(LIBEXIF_LIBS)


if HAVE_GTK2
lib_LTLIBRARIES   += libexif-gtk.la
else
EXTRA_LTLIBRARIES += libexif-gtk.la
endif

libexif_gtk_la_SOURCES = $(libexif_gtk_sources)
libexif_gtk_la_CFLAGS  = $(libexif_gtk_cflags)
libexif_gtk_la_LDFLAGS = $(libexif_gtk_ldflags)
libexif_gtk_la_LIBADD  = $(libexif_gtk_libadd)

libexif_gtk_la_CFLAGS += $(GTK2_CFLAGS)
libexif_gtk_la_LIBADD += $(GTK2_LIBS)
libexif_gtk_la_LIBADD += $(top_builddir)/gtk-extensions/libgtk-extensions-gtk2.la

# dependency workaround for this recursive make build
EXTRA_libexif_gtk_la_DEPENDENCIES = $(top_builddir)/gtk-extensions/libgtk-extensions-gtk2.la-stamp
$(top_builddir)/gtk-extensions/libgtk-extensions-gtk2.la-stamp:
	cd $(top_builddir)/gtk-extensions && $(MAKE) libgtk-extensions-gtk2.la


if HAVE_GTK3
lib_LTLIBRARIES   += libexif-gtk3.la
else
EXTRA_LTLIBRARIES += libexif-gtk3.la
endif

libexif_gtk3_la_SOURCES = $(libexif_gtk_sources)
libexif_gtk3_la_CFLAGS  = $(libexif_gtk_cflags)
libexif_gtk3_la_LDFLAGS = $(libexif_gtk_ldflags)
libexif_gtk3_la_LIBADD  = $(libexif_gtk_libadd)

libexif_gtk3_la_CFLAGS += $(GTK3_CFLAGS)
libexif_gtk3_la_LIBADD += $(GTK3_LIBS)
libexif_gtk3_la_LIBADD += $(top_builddir)/gtk-extensions/libgtk-extensions-gtk3.la

# dependency workaround for this recursive make build
EXTRA_libexif_gtk3_la_DEPENDENCIES = $(top_builddir)/gtk-extensions/libgtk-extensions-gtk3.la-stamp
$(top_builddir)/gtk-extensions/libgtk-extensions-gtk3.la-stamp:
	cd $(top_builddir)/gtk-extensions && $(MAKE) libgtk-extensions-gtk3.la
