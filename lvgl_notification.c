/**
 * @file lvgl_notification.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_notification.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

 typedef lv_obj_t* (*screen_creator_fn)(void);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static lv_obj_t *ui_load_screen(screen_creator_fn screen_fn);
static lv_obj_t *list_obj = NULL;
static lv_obj_t *card_container = NULL;

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_notification_init(const char * asset_path)
{
    lvgl_notification_init_gen(asset_path);

    /* Add your own custom code here if needed */
    // ui_load_screen(main_create());
}

#if (LV_EDITOR_PREVIEW == 0)    

void card_event_cb(lv_event_t * e);
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code  == LV_EVENT_CLICKED)
    {
        printf("Delete card");
    }
}

void list_event_cb(lv_event_t * e);
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code  == LV_EVENT_CLICKED)
    {
        char *user_data =  (char*)lv_event_get_user_data(e);
        if (user_data)
        {
            if (!lv_strcmp(user_data) == "outside")
            {
                if (list_obj)
                {
                    lv_obj_delete(list_obj);

                    list_obj = NULL;
                    card_container = NULL;
                }

            }
            else if (!lv_strcmp(user_data) == "clear_all")
            {
                uint32_t child_count = lv_obj_get_child_count(card_container)
                if (child_count)
                {
                    for (int i = 0; i < child_count; i++)
                    {
                        lv_obj_t* child = lv_obj_get_child(card_container, i);
                        if (child)
                        {
                            lv_obj_delete(child);
                        }
                    }
                }
            }
        }
    }
}

void notification_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *list_container = NULL;

    if (code  == LV_EVENT_CLICKED) 
    {
        int32_t notifications = lv_get_subject_int(&notifications_counter);
        lv_obj_t *src_act = lv_screen_active();

        list_obj = list_create(src_act,
            400,
            450,
            800,
            480,
            "Notifications");

        if (list_obj)
        {
            list_container = lv_obj_get_child_by_name(list_obj, "list_contatiner");
            if (list_container)
            {
                card_container = lv_obj_get_child_by_name(list_container, "card_container");
            }
            
            if (card_container)
            {
                if (notifications_counter)
                {
                    for (int i = 0; i < notifications_counter; i++)
                    {
                        card_create(card_container,
                            300,
                            200,
                            "Wi-Fi",
                            "1 min",
                            "Disconnected",
                            "Please check your connection.")
                    }
                }
                else
                {
                    printf("Not Notifications ...\n");
                }
            
            }
        }
    }
}

#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/

static lv_obj_t* ui_load_screen(screen_creator_fn screen_fn)
{
    lv_obj_t *screen = NULL;
    screen = screen_fn();
    lv_screen_load_anim(screen, 
                        LV_SCR_LOAD_ANIM_FADE_OUT,
                        100,
                        0,
                        true);
    return screen;
}