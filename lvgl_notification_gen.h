/**
 * @file lvgl_notification_gen.h
 */

#ifndef LVGL_NOTIFICATION_GEN_H
#define LVGL_NOTIFICATION_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_button;
extern lv_style_t style_dark;
extern lv_style_t style_light;
extern lv_style_t style_text;
extern lv_style_t style_text_light;
extern lv_style_t style_text_dark;
extern lv_style_t style_container;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * roboto_black_12;

extern lv_font_t * roboto_medium_25;

extern lv_font_t * roboto_medium_20;

extern lv_font_t * roboto_medium_12;

extern lv_font_t * roboto_medium_15;

extern lv_font_t * roboto_medium_13;

/*----------------
 * Images
 *----------------*/

extern const void * notification_icon;
extern const void * card_icon;
extern const void * notification_arrow_up;
extern const void * notification_arrrow_down;
extern const void * notification_delete;
extern const void * list_clear_all_30dp;
extern const void * list_clear_all;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t notifications_counter;
extern lv_subject_t dark_theme;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void card_event_cb(lv_event_t * e);
void list_event_cb(lv_event_t * e);
void notification_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void lvgl_notification_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "components/button/button_gen.h"
#include "components/card/card_gen.h"
#include "components/list/list_gen.h"
#include "screens/main/main_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_NOTIFICATION_GEN_H*/