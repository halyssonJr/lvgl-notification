/**
 * @file lvgl_notification_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_notification_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_button;
lv_style_t style_dark;
lv_style_t style_light;
lv_style_t style_text;
lv_style_t style_text_light;
lv_style_t style_text_dark;
lv_style_t style_container;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * roboto_black_12;
extern lv_font_t roboto_black_12_data;
lv_font_t * roboto_medium_25;
extern lv_font_t roboto_medium_25_data;
lv_font_t * roboto_medium_20;
extern lv_font_t roboto_medium_20_data;
lv_font_t * roboto_medium_12;
extern lv_font_t roboto_medium_12_data;
lv_font_t * roboto_medium_15;
extern lv_font_t roboto_medium_15_data;
lv_font_t * roboto_medium_13;
extern lv_font_t roboto_medium_13_data;

/*----------------
 * Images
 *----------------*/

const void * notification_icon;
extern const void * notification_icon_data;
const void * card_icon;
extern const void * card_icon_data;
const void * notification_arrow_up;
extern const void * notification_arrow_up_data;
const void * notification_arrrow_down;
extern const void * notification_arrrow_down_data;
const void * notification_delete;
extern const void * notification_delete_data;
const void * list_clear_all_30dp;
extern const void * list_clear_all_30dp_data;
const void * list_clear_all;
extern const void * list_clear_all_data;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t notifications_counter;
lv_subject_t dark_theme;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_notification_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_button);
        lv_style_set_bg_opa(&style_button, (255 * 0 / 100));
        lv_style_set_border_width(&style_button, 0);
        lv_style_set_shadow_opa(&style_button, (255 * 0 / 100));
        lv_style_set_pad_all(&style_button, 0);

        lv_style_init(&style_dark);
        lv_style_set_bg_color(&style_dark, lv_color_hex(0xbbbaba));
        lv_style_set_bg_opa(&style_dark, (255 * 88 / 100));
        lv_style_set_border_width(&style_dark, 0);
        lv_style_set_radius(&style_dark, 20);
        lv_style_set_pad_all(&style_dark, 0);
        lv_style_set_pad_hor(&style_dark, 16);
        lv_style_set_pad_ver(&style_dark, 14);
        lv_style_set_shadow_color(&style_dark, lv_color_hex(0xffffff));
        lv_style_set_shadow_opa(&style_dark, 125);
        lv_style_set_shadow_width(&style_dark, 20);

        lv_style_init(&style_light);
        lv_style_set_bg_color(&style_light, lv_color_hex(0xFFFFFF));
        lv_style_set_bg_opa(&style_light, (255 * 88 / 100));
        lv_style_set_border_width(&style_light, 0);
        lv_style_set_radius(&style_light, 20);
        lv_style_set_pad_hor(&style_light, 16);
        lv_style_set_pad_ver(&style_light, 14);
        lv_style_set_shadow_color(&style_light, lv_color_hex(0x434141));
        lv_style_set_shadow_opa(&style_light, 125);
        lv_style_set_shadow_width(&style_light, 20);

        lv_style_init(&style_text);
        lv_style_set_text_color(&style_text, lv_color_hex(0x665BEB));

        lv_style_init(&style_text_light);
        lv_style_set_text_color(&style_text_light, lv_color_hex(0x595959));

        lv_style_init(&style_text_dark);
        lv_style_set_text_color(&style_text_dark, lv_color_hex(0xffffff));

        lv_style_init(&style_container);
        lv_style_set_border_width(&style_container, 0);
        lv_style_set_pad_all(&style_container, 0);
        lv_style_set_bg_opa(&style_container, (255 * 0 / 100));

        style_inited = true;
    }

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'roboto_black_12' from a C array */
    roboto_black_12 = &roboto_black_12_data;
    /* get font 'roboto_medium_25' from a C array */
    roboto_medium_25 = &roboto_medium_25_data;
    /* get font 'roboto_medium_20' from a C array */
    roboto_medium_20 = &roboto_medium_20_data;
    /* get font 'roboto_medium_12' from a C array */
    roboto_medium_12 = &roboto_medium_12_data;
    /* get font 'roboto_medium_15' from a C array */
    roboto_medium_15 = &roboto_medium_15_data;
    /* get font 'roboto_medium_13' from a C array */
    roboto_medium_13 = &roboto_medium_13_data;


    /*----------------
     * Images
     *----------------*/
    notification_icon = &notification_icon_data;
    card_icon = &card_icon_data;
    notification_arrow_up = &notification_arrow_up_data;
    notification_arrrow_down = &notification_arrrow_down_data;
    notification_delete = &notification_delete_data;
    list_clear_all_30dp = &list_clear_all_30dp_data;
    list_clear_all = &list_clear_all_data;

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&notifications_counter, 0);
    lv_subject_init_int(&dark_theme, 0);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "roboto_black_12", roboto_black_12);
    lv_xml_register_font(NULL, "roboto_medium_25", roboto_medium_25);
    lv_xml_register_font(NULL, "roboto_medium_20", roboto_medium_20);
    lv_xml_register_font(NULL, "roboto_medium_12", roboto_medium_12);
    lv_xml_register_font(NULL, "roboto_medium_15", roboto_medium_15);
    lv_xml_register_font(NULL, "roboto_medium_13", roboto_medium_13);

    /* Register subjects */
    lv_xml_register_subject(NULL, "notifications_counter", &notifications_counter);
    lv_xml_register_subject(NULL, "dark_theme", &dark_theme);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "card_event_cb", card_event_cb);
    lv_xml_register_event_cb(NULL, "list_event_cb", list_event_cb);
    lv_xml_register_event_cb(NULL, "notification_cb", notification_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "notification_icon", notification_icon);
    lv_xml_register_image(NULL, "card_icon", card_icon);
    lv_xml_register_image(NULL, "notification_arrow_up", notification_arrow_up);
    lv_xml_register_image(NULL, "notification_arrrow_down", notification_arrrow_down);
    lv_xml_register_image(NULL, "notification_delete", notification_delete);
    lv_xml_register_image(NULL, "list_clear_all_30dp", list_clear_all_30dp);
    lv_xml_register_image(NULL, "list_clear_all", list_clear_all);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) card_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("card_event_cb was called\n");
}
void __attribute__((weak)) list_event_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("list_event_cb was called\n");
}
void __attribute__((weak)) notification_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("notification_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/