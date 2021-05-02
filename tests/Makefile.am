EXTRA_PROGRAMS =
noinst_PROGRAMS =

common_sources =
common_sources += test-libexif-gtk.c

common_cflags =
common_cflags += $(AM_CFLAGS)
common_cflags += $(CFLAGS)
common_cflags += -I$(top_srcdir)
common_cflags += $(LIBEXIF_CFLAGS)
common_cflags += -Wno-deprecated

common_ldflags =
common_ldflags += $(AM_LDFLAGS)
common_ldflags += $(LDFLAGS)

common_libadd =
common_libadd += $(LIBEXIF_LIBS)				\
common_libadd += $(INTLLIBS)


if HAVE_GTK2
noinst_PROGRAMS += test-libexif-gtk2
else
EXTRA_PROGRAMS  += test-libexif-gtk2
endif

test_libexif_gtk2_SOURCES = $(common_sources)
test_libexif_gtk2_CFLAGS  = $(common_cflags)
test_libexif_gtk2_LDFLAGS = $(common_ldflags)
test_libexif_gtk2_LDADD   = $(common_ldadd)

test_libexif_gtk2_CFLAGS += $(GTK2_CFLAGS)
test_libexif_gtk2_LDADD  += $(top_builddir)/libexif-gtk/libexif-gtk.la

# dependency workaround for this recursive make build
EXTRA_test_libexif_gtk2_DEPENDENCIES = \
	$(top_builddir)/libexif-gtk/libexif-gtk.la-stamp
$(top_builddir)/libexif-gtk/libexif-gtk.la-stamp:
	cd $(top_builddir)/libexif-gtk && $(MAKE) libexif-gtk.la


if HAVE_GTK3
noinst_PROGRAMS += test-libexif-gtk3
else
EXTRA_PROGRAMS  += test-libexif-gtk3
endif

test_libexif_gtk3_SOURCES = $(common_sources)
test_libexif_gtk3_CFLAGS  = $(common_cflags)
test_libexif_gtk3_LDFLAGS = $(common_ldflags)
test_libexif_gtk3_LDADD   = $(common_ldadd)

test_libexif_gtk3_CFLAGS += $(GTK3_CFLAGS)
test_libexif_gtk3_LDADD  += $(top_builddir)/libexif-gtk/libexif-gtk3.la

# dependency workaround for this recursive make build
EXTRA_test_libexif_gtk3_DEPENDENCIES = \
	$(top_builddir)/libexif-gtk/libexif-gtk3.la-stamp
$(top_builddir)/libexif-gtk/libexif-gtk3.la-stamp:
	cd $(top_builddir)/libexif-gtk && $(MAKE) libexif-gtk3.la
