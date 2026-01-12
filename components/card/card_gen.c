/**
 * @file card_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "card_gen.h"
#include "lvgl_notification.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * card_create(lv_obj_t * parent, int32_t card_width, int32_t card_height, const char * card_title, const char * card_timestamp, const char * card_subtitle, const char * card_content, void * card_id)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "card_#");
    lv_obj_set_height(lv_obj_0, card_height);
    lv_obj_set_width(lv_obj_0, card_width);

    lv_obj_bind_style(lv_obj_0, &style_light, 0, &dark_theme, 0);
    lv_obj_bind_style(lv_obj_0, &style_dark, 0, &dark_theme, 1);
    lv_obj_add_style(lv_obj_0, &style_light, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_height(lv_obj_1, lv_pct(25));
    lv_obj_set_width(lv_obj_1, lv_pct(100));
    lv_obj_set_align(lv_obj_1, LV_ALIGN_TOP_LEFT);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_add_style(lv_obj_1, &style_container, 0);
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_set_height(lv_obj_2, lv_pct(100));
    lv_obj_set_width(lv_obj_2, lv_pct(85));
    lv_obj_set_align(lv_obj_2, LV_ALIGN_TOP_LEFT);
    lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_ROW);
    lv_obj_add_style(lv_obj_2, &style_container, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_2);
    lv_image_set_src(lv_image_0, card_icon);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_0, card_title);
    lv_obj_set_style_text_font(lv_label_0, roboto_medium_20, 0);
    lv_obj_add_style(lv_label_0, &style_text, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_1, card_timestamp);
    lv_obj_set_style_text_font(lv_label_1, roboto_medium_20, 0);
    lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
    lv_obj_bind_style(lv_label_1, &style_text_light, 0, &dark_theme, 0);
    lv_obj_bind_style(lv_label_1, &style_text_dark, 0, &dark_theme, 1);
    
    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_1);
    lv_obj_set_height(lv_button_0, 30);
    lv_obj_set_width(lv_button_0, 30);
    lv_obj_set_style_bg_image_src(lv_button_0, notification_delete, 0);
    lv_obj_add_style(lv_button_0, &style_button, 0);
    lv_obj_add_event_cb(lv_button_0, card_event_cb, LV_EVENT_CLICKED, card_id);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_0);
    lv_obj_set_height(lv_obj_3, lv_pct(70));
    lv_obj_set_width(lv_obj_3, lv_pct(100));
    lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_flex_flow(lv_obj_3, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(lv_obj_3, &style_container, 0);
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_3);
    lv_obj_set_height(lv_obj_4, lv_pct(20));
    lv_obj_set_width(lv_obj_4, lv_pct(100));
    lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_4);
    lv_label_set_text(lv_label_2, card_subtitle);
    lv_obj_set_style_text_font(lv_label_2, roboto_medium_15, 0);
    
    lv_obj_add_style(lv_obj_4, &style_container, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_3);
    lv_obj_set_width(lv_label_3, lv_pct(100));
    lv_obj_set_height(lv_label_3, lv_pct(80));
    lv_label_set_text(lv_label_3, card_content);
    lv_label_set_long_mode(lv_label_3, LV_LABEL_LONG_MODE_WRAP);
    lv_obj_set_style_text_align(lv_label_3, LV_TEXT_ALIGN_AUTO, 0);
    lv_obj_set_style_text_font(lv_label_3, roboto_medium_15, 0);
    lv_obj_bind_style(lv_label_3, &style_text_light, 0, &dark_theme, 0);
    lv_obj_bind_style(lv_label_3, &style_text_dark, 0, &dark_theme, 1);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

