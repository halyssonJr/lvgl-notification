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
#define LVGL_NOTIFICTION_MAX (10)

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

typedef struct
{
    char title[20];
    char time[10];
    char status[25];
    char message[150];
} lvgl_notification_t;

typedef struct
{
    lv_obj_t *obj;
    int id;
}lvgl_card_t;

typedef struct {
    lvgl_card_t card [LVGL_NOTIFICTION_MAX];
    int total_card;
} lvgl_notification_card_t;

static const lvgl_notification_t notification_sim[] = {
    { "Wi-Fi",  "1 min",  "Disconnected",     "Please check your connection." },
    { "Sensor", "10 min", "High temperature", "Turn on the fan." },
    { "Update", "1h",     "New FW",            "Firmware available for download" }
};

static lvgl_card_t lvgl_card [LVGL_NOTIFICTION_MAX];
static lvgl_notification_card_t notification_center;

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
    // main_create()
    lv_subject_set_int(&notifications_counter, 3);
    lv_screen_load(main_create());

    memset(&notification_center, 0, sizeof(notification_center));
    for (int i = 0; i < LVGL_NOTIFICTION_MAX; i++)
    {
        notification_center.card[i].id = -1;
    }

    // ui_load_screen(main_create());
}

#if (LV_EDITOR_PREVIEW == 0)    

void card_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    int id = (int)(intptr_t)lv_event_get_user_data(e);

    if (id < LVGL_NOTIFICTION_MAX)
    {
        if (notification_center.card[id].id >= 0)
        {
            lv_obj_delete(notification_center.card[id].obj);
            notification_center.card[id].obj = NULL;
            notification_center.card[id].id = -1;
            notification_center.total_card = notification_center.total_card - 1;
            printf("Total cards = %d\n", notification_center.total_card);
            lv_subject_set_int(&notifications_counter, notification_center.total_card);
        }
    }

}

void list_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code  == LV_EVENT_CLICKED)
    {
        char *user_data =  (char*)lv_event_get_user_data(e);
        if (user_data)
        {
            if (lv_strcmp(user_data, "outside") == 0)
            {
                if (list_obj)
                {
                    lv_obj_delete(list_obj);
                    list_obj = NULL;
                    card_container = NULL;
                }
            }
            else
            {
                if (lv_strcmp(user_data, "clear_all") == 0)
                {
                    uint32_t child_count = lv_obj_get_child_count(card_container);
                    if (child_count > 1)
                    {
                        int i;
                        do
                        {
                            for ( i = 1; i <= child_count; i++)
                            {
                                lv_obj_t* child = lv_obj_get_child(card_container, i);
                                if (child)
                                {
                                    lv_obj_delete(child);
                                }
                                else 
                                {
                                    break;
                                }
                            }
                            child_count = lv_obj_get_child_count(card_container);
                        } while (child_count > 1);

                        notification_center.total_card = 0;
                        lv_subject_set_int(&notifications_counter, notification_center.total_card);
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
        int32_t notifications = lv_subject_get_int(&notifications_counter);
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
                int i;
                printf("Notifications = %d\n", notification_center.total_card);
                if (notification_center.total_card)
                {
                    int notification_list_id = 0;
                    for (i = 0; i < LVGL_NOTIFICTION_MAX; i++)
                    {
                        printf("Card id = %d\n", notification_center.card[i].id);
                        if (notification_center.card[i].id >= 0)
                        {
                            notification_center.card[i].obj = card_create(card_container,
                            300,
                            200,
                            notification_sim[i].title,
                            notification_sim[i].time,
                            notification_sim[i].status,
                            notification_sim[i].message, (void *)(intptr_t)notification_center.card[i].id);
                        }
                    }
                }
                else
                {
                    for (i = 0; i < notifications; i++)
                    {
                        notification_center.card[i].id = i;
                        notification_center.card[i].obj = card_create(card_container,
                            300,
                            200,
                            notification_sim[i].title,
                            notification_sim[i].time,
                            notification_sim[i].status,
                            notification_sim[i].message, (void *)(intptr_t)notification_center.card[i].id);
                        notification_center.total_card ++;
                    }
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