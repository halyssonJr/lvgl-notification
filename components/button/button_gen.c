/**
 * @file button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_gen.h"
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

lv_obj_t * button_create(lv_obj_t * parent, int32_t btn_width, int32_t btn_height)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_local;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_local);
        lv_style_set_bg_opa(&style_local, (255 * 0 / 100));
        lv_style_set_border_width(&style_local, 0);
        lv_style_set_shadow_opa(&style_local, (255 * 0 / 100));
        lv_style_set_pad_all(&style_local, 0);
        lv_style_set_radius(&style_local, 0);

        style_inited = true;
    }

    lv_obj_t * lv_button_0 = lv_button_create(parent);
    lv_obj_set_name_static(lv_button_0, "button_#");
    lv_obj_set_height(lv_button_0, btn_height);
    lv_obj_set_width(lv_button_0, btn_width);
    lv_obj_set_flag(lv_button_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(lv_button_0, LV_ALIGN_CENTER);
    lv_obj_set_style_border_width(lv_button_0, 1, 0);
    lv_obj_set_style_radius(lv_button_0, 10, 0);
    lv_obj_set_style_pad_all(lv_button_0, 3, 0);
    lv_obj_set_style_border_color(lv_button_0, lv_color_hex(0x000000), 0);
    lv_obj_set_style_bg_color(lv_button_0, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_shadow_width(lv_button_0, 30, 0);

    lv_obj_t * lv_image_0 = lv_image_create(lv_button_0);
    lv_image_set_src(lv_image_0, notification_icon);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_0 = lv_obj_create(lv_button_0);
    lv_obj_set_width(lv_obj_0, lv_pct(45));
    lv_obj_set_height(lv_obj_0, lv_pct(45));
    lv_obj_set_style_radius(lv_obj_0, lv_pct(50), 0);
    lv_obj_set_align(lv_obj_0, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_style_border_width(lv_obj_0, 0, 0);
    lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xff003a), 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_bind_text(lv_label_0, &notifications_counter, "%d");
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(lv_label_0, roboto_black_12, 0);
    
    lv_obj_bind_flag_if_eq(lv_obj_0, &notifications_counter, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_add_event_cb(lv_button_0, notification_cb, LV_EVENT_CLICKED, NULL);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_button_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

