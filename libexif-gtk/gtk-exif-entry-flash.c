/* gtk-exif-entry-flash.c
 *
 * Copyright © 2001 Lutz Müller <lutz@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include "gtk-exif-entry-flash.h"
#include "gtk-exif-util.h"

#include <string.h>
#include <gtk/gtk.h>

struct _GtkExifEntryFlashPrivate {
	ExifEntry *entry;

	GtkToggleButton *c;
	GtkToggleButton *r1, *r2, *r3;
};

#define PARENT_TYPE GTK_EXIF_TYPE_ENTRY
static GtkExifEntryClass *parent_class;

static void
#if GTK_CHECK_VERSION(3,0,0)
gtk_exif_entry_flash_destroy (GtkWidget *widget)
#else
gtk_exif_entry_flash_destroy (GtkObject *object)
#endif
{
#if GTK_CHECK_VERSION(3,0,0)
	GtkExifEntryFlash *entry = GTK_EXIF_ENTRY_FLASH (widget);
#else
	GtkExifEntryFlash *entry = GTK_EXIF_ENTRY_FLASH (object);
#endif

	if (entry->priv->entry) {
		exif_entry_unref (entry->priv->entry);
		entry->priv->entry = NULL;
	}

#if GTK_CHECK_VERSION(3,0,0)
	GTK_WIDGET_CLASS (parent_class)->destroy (widget);
#else
	GTK_OBJECT_CLASS (parent_class)->destroy (object);
#endif
}

GTK_EXIF_FINALIZE (entry_flash, EntryFlash)

static void
gtk_exif_entry_flash_class_init (gpointer g_class, gpointer class_data)
{
#if GTK_CHECK_VERSION(3,0,0)
	GtkWidgetClass *widget_class;
	GObjectClass *gobject_class;

	widget_class = GTK_WIDGET_CLASS (g_class);
	widget_class->destroy = gtk_exif_entry_flash_destroy;
#else
	GtkObjectClass *object_class;
	GObjectClass *gobject_class;

	object_class = GTK_OBJECT_CLASS (g_class);
	object_class->destroy  = gtk_exif_entry_flash_destroy;
#endif

	gobject_class = G_OBJECT_CLASS (g_class);
	gobject_class->finalize = gtk_exif_entry_flash_finalize;

	parent_class = g_type_class_peek_parent (g_class);
}

static void
gtk_exif_entry_flash_init (GTypeInstance *instance, gpointer g_class)
{
	GtkExifEntryFlash *entry = GTK_EXIF_ENTRY_FLASH (instance);

	entry->priv = g_new0 (GtkExifEntryFlashPrivate, 1);
}

GTK_EXIF_CLASS (entry_flash, EntryFlash, "EntryFlash")

static void
on_value_changed (GtkToggleButton *toggle, GtkExifEntryFlash *entry)
{
	g_return_if_fail (GTK_EXIF_IS_ENTRY_FLASH (entry));

	entry->priv->entry->data[0] &= 0xfe;
	if (gtk_toggle_button_get_active (entry->priv->c))
		entry->priv->entry->data[0] |= 0x01;

	entry->priv->entry->data[0] &= 0xf9;
	if (gtk_toggle_button_get_active (entry->priv->r2))
		entry->priv->entry->data[0] |= 0x04;
	else if (gtk_toggle_button_get_active (entry->priv->r3))
		entry->priv->entry->data[0] |= 0x06;
	g_signal_emit_by_name (G_OBJECT (entry), "entry_changed",
				 entry->priv->entry);
}

GtkWidget *
gtk_exif_entry_flash_new (ExifEntry *e)
{
	GtkExifEntryFlash *entry;
	GtkWidget *check, *frame, *vbox, *radio;
	GSList *group;

	g_return_val_if_fail (e != NULL, NULL);
	g_return_val_if_fail (e->tag == EXIF_TAG_FLASH, NULL);

	entry = g_object_new (GTK_EXIF_TYPE_ENTRY_FLASH, NULL);
	entry->priv->entry = e;
	exif_entry_ref (e);
	gtk_exif_entry_construct (GTK_EXIF_ENTRY (entry),
		exif_tag_get_title_in_ifd (e->tag, exif_content_get_ifd(e->parent)),
		exif_tag_get_description_in_ifd (e->tag, exif_content_get_ifd(e->parent)));

	check = gtk_check_button_new_with_label ("Flash fired");
	gtk_widget_show (check);
	gtk_box_pack_start (GTK_BOX (entry), check, FALSE, FALSE, 0);
	if (e->data[0] & (1 << 0))
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check), TRUE);
	g_signal_connect (G_OBJECT (check), "toggled",
			    G_CALLBACK (on_value_changed), entry);
	entry->priv->c = GTK_TOGGLE_BUTTON (check);

	frame = gtk_frame_new ("Return light");
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (entry), frame, FALSE, FALSE, 0);
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox);
	gtk_container_add (GTK_CONTAINER (frame), vbox);

	/* No strobe return detection function */
	radio = gtk_radio_button_new_with_label (NULL, "No strobe return "
						 "detection function");
	gtk_widget_show (radio);
	gtk_box_pack_start (GTK_BOX (vbox), radio, FALSE, FALSE, 0);
	if (!(e->data[0] & (1 << 1)) && !(e->data[0] & (1 << 2)))
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radio), TRUE);
	g_signal_connect (G_OBJECT (radio), "toggled",
			    G_CALLBACK (on_value_changed), entry);
	entry->priv->r1 = GTK_TOGGLE_BUTTON (radio);

	/* Stobe return light not detected */
	group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radio));
	radio = gtk_radio_button_new_with_label (group,
				"Strobe return light not detected");
	gtk_widget_show (radio);
	gtk_box_pack_start (GTK_BOX (vbox), radio, FALSE, FALSE, 0);
	if (!(e->data[0] & (1 << 1)) && (e->data[0] & (1 << 2)))
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radio), TRUE);
	g_signal_connect (G_OBJECT (radio), "toggled",
			    G_CALLBACK (on_value_changed), entry);
	entry->priv->r2 = GTK_TOGGLE_BUTTON (radio);

	/* Strobe return light detected */
	group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radio));
	radio = gtk_radio_button_new_with_label (group,
					"Strobe return light detected");
	gtk_widget_show (radio);
	gtk_box_pack_start (GTK_BOX (vbox), radio, FALSE, FALSE, 0);
	if ((e->data[0] & (1 << 1)) && (e->data[0] & (1 << 2)))
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radio), TRUE);
	g_signal_connect (G_OBJECT (radio), "toggled",
			    G_CALLBACK (on_value_changed), entry);
	entry->priv->r3 = GTK_TOGGLE_BUTTON (radio);

	return (GTK_WIDGET (entry));
}
