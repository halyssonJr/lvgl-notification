/**
 * @file list_gen.h
 */

#ifndef LIST_H
#define LIST_H

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

typedef enum {
    LIST_TIMELINE_LIST_DROP = 0,
    _LIST_TIMELINE_CNT = 1
}list_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * list_create(lv_obj_t * parent, int32_t list_width, int32_t list_height, int32_t list_card_width, int32_t list_card_height, const char * list_title);

/**
 * Get a timeline of a list
 * @param obj          pointer to a list component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * list_get_timeline(lv_obj_t * obj, list_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LIST_H*/