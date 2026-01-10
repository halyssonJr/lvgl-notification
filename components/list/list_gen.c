/**
 * @file list_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_gen.h"
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

static lv_anim_timeline_t * timeline_list_drop_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * list_create(lv_obj_t * parent, int32_t list_width, int32_t list_height, int32_t list_card_width, int32_t list_card_height, const char * list_title)
{
    LV_TRACE_OBJ_CREATE("begin");

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "list_#");
    lv_obj_set_height(lv_obj_0, list_card_height);
    lv_obj_set_width(lv_obj_0, list_card_width);
    lv_obj_set_style_bg_opa(lv_obj_0, 10, 0);
    lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x242323), 0);
    lv_obj_set_style_border_width(lv_obj_0, 0, 0);
    lv_obj_set_style_radius(lv_obj_0, 0, 0);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_t * list_contatiner = lv_obj_create(lv_obj_0);
    lv_obj_set_name(list_contatiner, "list_contatiner");
    lv_obj_set_height(list_contatiner, list_height);
    lv_obj_set_width(list_contatiner, list_width);
    lv_obj_set_align(list_contatiner, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(list_contatiner, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_flex_main_place(list_contatiner, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_add_style(list_contatiner, &style_light, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(list_contatiner);
    lv_obj_set_width(lv_obj_1, lv_pct(100));
    lv_obj_set_height(lv_obj_1, lv_pct(10));
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_add_style(lv_obj_1, &style_container, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_obj_set_width(lv_label_0, lv_pct(80));
    lv_label_set_text(lv_label_0, list_title);
    lv_obj_set_style_text_font(lv_label_0, roboto_medium_25, 0);
    lv_obj_add_style(lv_label_0, &style_text, 0);
    
    lv_obj_add_style(lv_obj_1, &style_container, 0);
    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_1);
    lv_obj_set_height(lv_button_0, lv_pct(90));
    lv_obj_set_width(lv_button_0, 30);
    lv_obj_add_style(lv_button_0, &style_button, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_button_0);
    lv_image_set_src(lv_image_0, list_clear_all_30dp);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    
    lv_obj_add_event_cb(lv_button_0, list_event_cb, LV_EVENT_CLICKED, "clear_all");
    
    lv_obj_t * card_container = lv_obj_create(list_contatiner);
    lv_obj_set_name(card_container, "card_container");
    lv_obj_set_width(card_container, lv_pct(100));
    lv_obj_set_height(card_container, lv_pct(80));
    lv_obj_set_flex_flow(card_container, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_flex_main_place(card_container, LV_FLEX_ALIGN_START, 0);
    lv_obj_set_style_flex_cross_place(card_container, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_left(card_container, 34, 0);
    lv_obj_set_style_pad_right(card_container, 0, 0);
    lv_obj_set_style_pad_top(card_container, 10, 0);
    lv_obj_set_style_pad_bottom(card_container, 10, 0);
    lv_obj_set_style_pad_row(card_container, 20, 0);
    lv_obj_add_style(card_container, &style_container, 0);
    
    lv_obj_add_event_cb(lv_obj_0, list_event_cb, LV_EVENT_CLICKED, "outside");
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _LIST_TIMELINE_CNT);
    at_array[LIST_TIMELINE_LIST_DROP] = timeline_list_drop_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * list_get_timeline(lv_obj_t * obj, list_timeline_t timeline_id)
{
    if (timeline_id >= _LIST_TIMELINE_CNT) {
        LV_LOG_WARN("list has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_list_drop_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);
    lv_anim_set_early_apply(&a, true);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _LIST_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

