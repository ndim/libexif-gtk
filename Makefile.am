SUBDIRS = m4m po gtk-extensions libexif-gtk tests

pkgconfig_DATA =
noinst_DATA    =

pkgconfigdir = $(libdir)/pkgconfig

if HAVE_GTK2
pkgconfig_DATA += libexif-gtk.pc
noinst_DATA    += libexif-gtk-uninstalled.pc
endif

if HAVE_GTK3
pkgconfig_DATA += libexif-gtk3.pc
noinst_DATA    += libexif-gtk3-uninstalled.pc
endif

ACLOCAL_AMFLAGS = -I auto-m4 -I m4m
