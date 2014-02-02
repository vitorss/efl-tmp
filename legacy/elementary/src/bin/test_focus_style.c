#ifdef HAVE_CONFIG_H
# include "elementary_config.h"
#endif
#include <Elementary.h>

static void
glow_effect_on_cb(void *data, Evas_Object *obj, void *event_info EINA_UNUSED)
{
   Evas_Object *chk = evas_object_data_get(obj, "glow_is_enable");

   if (elm_check_state_get(chk)) elm_win_focus_highlight_style_set(data, "glow_effect");
}

static void
glow_effect_off_cb(void *data, Evas_Object *obj, void *event_info EINA_UNUSED)
{
   Evas_Object *chk = evas_object_data_get(obj, "glow_is_enable");

   if (elm_check_state_get(chk)) elm_win_focus_highlight_style_set(data, "glow");
}

void
test_focus_style(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *win, *fr, *bx, *bx2, *bt, *spinner, *sp, *chk;
   char win_focus_theme[PATH_MAX] = { 0 };

   sprintf(win_focus_theme, "%s/objects/test_focus_style.edj", elm_app_data_dir_get());

   elm_theme_overlay_add(NULL, win_focus_theme);

   win = elm_win_util_standard_add("focus-style", "Focus Style");
   elm_win_autodel_set(win, EINA_TRUE);
   elm_win_focus_highlight_enabled_set(win, EINA_TRUE);
   elm_win_focus_highlight_animate_set(win, EINA_TRUE);
   elm_win_focus_highlight_style_set(win, "glow");

   fr = elm_frame_add(win);
   evas_object_size_hint_weight_set(fr, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_win_resize_object_add(win, fr);
   elm_object_style_set(fr, "pad_large");
   evas_object_show(fr);

   bx = elm_box_add(fr);
   elm_object_content_set(fr, bx);
   evas_object_show(bx);

   chk = elm_check_add(bx);
   evas_object_size_hint_weight_set(chk, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(chk, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_object_text_set(chk, "Enable glow effect on \"Glow\" Button");
   elm_check_state_set(chk, EINA_TRUE);
   elm_box_pack_end(bx, chk);
   evas_object_show(chk);

   spinner = elm_spinner_add(bx);
   evas_object_size_hint_weight_set(spinner, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(spinner, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx, spinner);
   evas_object_show(spinner);

   bt = elm_button_add(bx);
   elm_object_text_set(bt, "Glow Button");
   evas_object_size_hint_weight_set(bt, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(bt, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx, bt);
   evas_object_smart_callback_add(bt, "focused", glow_effect_on_cb, win);
   evas_object_smart_callback_add(bt, "unfocused", glow_effect_off_cb, win);
   evas_object_data_set(bt, "glow_is_enable", chk);
   evas_object_show(bt);

   sp = elm_separator_add(bx);
   elm_separator_horizontal_set(sp, EINA_TRUE);
   evas_object_size_hint_weight_set(sp, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(sp, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx, sp);
   evas_object_show(sp);

   bx2 = elm_box_add(bx);
   elm_box_horizontal_set(bx2, EINA_TRUE);
   evas_object_size_hint_weight_set(bx2, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bx2, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx, bx2);
   evas_object_show(bx2);

   bt = elm_button_add(bx2);
   elm_object_text_set(bt, "Button 1");
   evas_object_size_hint_weight_set(bt, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bt, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx2, bt);
   evas_object_show(bt);

   bt = elm_button_add(bx2);
   elm_object_text_set(bt, "Button 2");
   evas_object_size_hint_weight_set(bt, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bt, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx2, bt);
   evas_object_show(bt);

   bt = elm_button_add(bx2);
   elm_object_text_set(bt, "Button 3");
   evas_object_size_hint_weight_set(bt, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bt, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx2, bt);
   evas_object_show(bt);

   bt = elm_button_add(bx2);
   elm_object_text_set(bt, "Button 4");
   evas_object_size_hint_weight_set(bt, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(bt, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_box_pack_end(bx2, bt);
   evas_object_show(bt);

   evas_object_resize(win, 320, 320);
   evas_object_show(win);
}
