// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void glow_anim_Animation(lv_obj_t * TargetObject, int delay);
void glow_off_Animation(lv_obj_t * TargetObject, int delay);
void MOVE_Animation(lv_obj_t * TargetObject, int delay);
void bounce_Animation(lv_obj_t * TargetObject, int delay);
void logo_move_Animation(lv_obj_t * TargetObject, int delay);
void logo_move2_Animation(lv_obj_t * TargetObject, int delay);
void bolb_fadeoff_Animation(lv_obj_t * TargetObject, int delay);
void bolb_fadeon_Animation(lv_obj_t * TargetObject, int delay);
void nav_bar_open_Animation(lv_obj_t * TargetObject, int delay);
void nav_bar_close_Animation(lv_obj_t * TargetObject, int delay);
void navbar_out_Animation(lv_obj_t * TargetObject, int delay);
void navbar_in_Animation(lv_obj_t * TargetObject, int delay);
void panel_fade_Animation(lv_obj_t * TargetObject, int delay);
void rightPanel_in_Animation(lv_obj_t * TargetObject, int delay);
void rightPanel_out_Animation(lv_obj_t * TargetObject, int delay);
void spin_Animation(lv_obj_t * TargetObject, int delay);
void ui_event_Screen2(lv_event_t * e);
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Panel6;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_bulb1;
lv_obj_t * ui_glow1;
lv_obj_t * ui_off1;
lv_obj_t * ui_on1;
void ui_event_bulb_Button1(lv_event_t * e);
lv_obj_t * ui_bulb_Button1;
lv_obj_t * ui_bulb2;
lv_obj_t * ui_glow2;
lv_obj_t * ui_off2;
lv_obj_t * ui_on2;
void ui_event_bulb_Button2(lv_event_t * e);
lv_obj_t * ui_bulb_Button2;
lv_obj_t * ui_bulb3;
lv_obj_t * ui_glow3;
lv_obj_t * ui_off3;
lv_obj_t * ui_on3;
void ui_event_bulb_Button3(lv_event_t * e);
lv_obj_t * ui_bulb_Button3;
lv_obj_t * ui_bulb4;
lv_obj_t * ui_glow4;
lv_obj_t * ui_off4;
lv_obj_t * ui_on4;
void ui_event_bulb_Button4(lv_event_t * e);
lv_obj_t * ui_bulb_Button4;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Panel8;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Image8;
//////////////////////////////
void ui_event_btnm(lv_event_t * e);
const char* btnm_map[] = { "1", "2", "\n", "3", "4","" };
lv_obj_t* btnm1;
lv_style_t style_bg;
lv_obj_t* ui_Panel2;
lv_obj_t* ui_Panel9;
//////////////////////////
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_Image5;
void ui_event_rightPanel(lv_event_t * e);
lv_obj_t * ui_rightPanel;
lv_obj_t * ui_Image7;
void ui_event_Image10(lv_event_t * e);
lv_obj_t * ui_Image10;
lv_obj_t * ui_Panel7;
void ui_event_Image6(lv_event_t * e);
lv_obj_t * ui_Image6;
lv_obj_t * ui_Screen3;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Screen4;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
struct screenButton states={0,0,0,0,0,0};
void get_states();
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void glow_anim_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 300);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 100, 256);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 200);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 300);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_1, 0, 300);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 550);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_start(&PropertyAnimation_1);
    lv_anim_t PropertyAnimation_2;
    lv_anim_init(&PropertyAnimation_2);
    lv_anim_set_time(&PropertyAnimation_2, 200);
    lv_anim_set_user_data(&PropertyAnimation_2, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_2, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_2, 300, 0);
    lv_anim_set_path_cb(&PropertyAnimation_2, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_2, delay + 250);
    lv_anim_set_playback_time(&PropertyAnimation_2, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_2, 0);
    lv_anim_set_early_apply(&PropertyAnimation_2, false);
    lv_anim_start(&PropertyAnimation_2);

}
void glow_off_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 180);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 256, 100);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void MOVE_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, 100);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}
void bounce_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -100);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 4);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 500);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_1, 0, 100);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 500);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 3);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 500);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_1);
    lv_anim_t PropertyAnimation_2;
    lv_anim_init(&PropertyAnimation_2);
    lv_anim_set_time(&PropertyAnimation_2, 630);
    lv_anim_set_user_data(&PropertyAnimation_2, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_2, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_2, 0, 139);
    lv_anim_set_path_cb(&PropertyAnimation_2, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_2, delay + 3500);
    lv_anim_set_playback_time(&PropertyAnimation_2, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_2, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_2, 0);
    lv_anim_set_early_apply(&PropertyAnimation_2, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_2, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_2);
    lv_anim_t PropertyAnimation_3;
    lv_anim_init(&PropertyAnimation_3);
    lv_anim_set_time(&PropertyAnimation_3, 500);
    lv_anim_set_user_data(&PropertyAnimation_3, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_3, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_3, 0, 75);
    lv_anim_set_path_cb(&PropertyAnimation_3, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_3, delay + 3000);
    lv_anim_set_playback_time(&PropertyAnimation_3, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_3, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_3, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_3, 0);
    lv_anim_set_early_apply(&PropertyAnimation_3, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_3, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_3);
    lv_anim_t PropertyAnimation_4;
    lv_anim_init(&PropertyAnimation_4);
    lv_anim_set_time(&PropertyAnimation_4, 630);
    lv_anim_set_user_data(&PropertyAnimation_4, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_4, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_4, 0, 75);
    lv_anim_set_path_cb(&PropertyAnimation_4, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_4, delay + 3500);
    lv_anim_set_playback_time(&PropertyAnimation_4, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_4, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_4, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_4, 500);
    lv_anim_set_early_apply(&PropertyAnimation_4, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_4, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_4);

}
void logo_move_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 40);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);

}
void logo_move2_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, -150);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}
void bolb_fadeoff_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void bolb_fadeon_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 255, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void nav_bar_open_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 400);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, -900, 900);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void nav_bar_close_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 400);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 900, -900);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void navbar_out_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, -307, -150);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void navbar_in_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, -150, -307);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void panel_fade_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void rightPanel_in_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 127, 310);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void rightPanel_out_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 310, 127);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void spin_Animation(lv_obj_t * TargetObject, int delay){
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 2000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////

void ui_event_Screen2(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        bounce_Animation(ui_Image1, 500);
        logo_move2_Animation(ui_Image2, 5000);
        logo_move2_Animation(ui_Image1, 5000);
        logo_move_Animation(ui_Image3, 5000);
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 7000);
    }
}
void ui_event_bulb_Button1(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_anim_Animation(ui_glow1, 0);
        bolb_fadeoff_Animation(ui_on1, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_off_Animation(ui_glow1, 0);
        bolb_fadeon_Animation(ui_on1, 0);
    }
}
void ui_event_btnm(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
   // states.fan_speed =lv_btnmatrix_get_selected_btn(target)+1;
    if(event_code == LV_EVENT_VALUE_CHANGED ) {
        
}
}
void ui_event_bulb_Button2(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_anim_Animation(ui_glow2, 0);
        bolb_fadeoff_Animation(ui_on2, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_off_Animation(ui_glow2, 0);
        bolb_fadeon_Animation(ui_on2, 0);
    }
}
void ui_event_bulb_Button3(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_anim_Animation(ui_glow3, 0);
        bolb_fadeoff_Animation(ui_on3, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_off_Animation(ui_glow3, 0);
        bolb_fadeon_Animation(ui_on3, 0);
    }
}
void ui_event_bulb_Button4(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_anim_Animation(ui_glow4, 0);
        bolb_fadeoff_Animation(ui_on4, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        glow_off_Animation(ui_glow4, 0);
        bolb_fadeon_Animation(ui_on4, 0);
    }
}
void ui_event_Button4(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        spin_Animation(ui_Image8, 0);
        lv_obj_clear_flag(ui_Panel9,LV_OBJ_FLAG_HIDDEN);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        lv_obj_add_flag(ui_Panel9,LV_OBJ_FLAG_HIDDEN);
        lv_anim_del_all();
    }
}
void ui_event_rightPanel(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED)) {
        rightPanel_in_Animation(ui_Panel5, 0);
        nav_bar_close_Animation(ui_Image5, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        rightPanel_out_Animation(ui_Panel5, 0);
        nav_bar_open_Animation(ui_Image5, 0);
    }
}
void ui_event_Image10(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Image6(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button1(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Button2(lv_event_t * e){
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void get_states(){
  states.led1 =lv_obj_has_state(ui_bulb_Button1, LV_STATE_CHECKED);
  states.led2 =lv_obj_has_state(ui_bulb_Button2, LV_STATE_CHECKED);
  states.led3 =lv_obj_has_state(ui_bulb_Button3, LV_STATE_CHECKED);
  states.led4 =lv_obj_has_state(ui_bulb_Button4, LV_STATE_CHECKED);
  states.fan =lv_obj_has_state(ui_Button4, LV_STATE_CHECKED);
  states.fan_speed =lv_btnmatrix_get_selected_btn(btnm1)+1;

}
///////////////////// SCREENS ////////////////////
void ui_Screen2_screen_init(void){
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel6 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_Panel6, 309);
    lv_obj_set_height(ui_Panel6, 42);
    lv_obj_set_x(ui_Panel6, -72);
    lv_obj_set_y(ui_Panel6, 11);
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Panel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image3 = lv_img_create(ui_Panel6);
    lv_img_set_src(ui_Image3, &ui_img_488449546);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 317
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image2 = lv_img_create(ui_Screen2);
    lv_img_set_src(ui_Image2, &ui_img_oie_552325lzwjvdft_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 112
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(ui_Image2, 156);
    lv_obj_set_y(ui_Image2, 12);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image1 = lv_img_create(ui_Screen2);
    lv_img_set_src(ui_Image1, &ui_img_oie_55240fpthker1_png);
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 112
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 100
    lv_obj_set_x(ui_Image1, 9);
    lv_obj_set_y(ui_Image1, -29);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_Screen2, ui_event_Screen2, LV_EVENT_ALL, NULL);

}
void ui_Screen1_screen_init(void){
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 480);
    lv_obj_set_height(ui_Panel1, 47);
    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, -137);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x006E60), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -2);
    lv_obj_set_y(ui_Label2, -2);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "04 : 12 am                                   SAT, April 15");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Label2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Label2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel3 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel3, 480);
    lv_obj_set_height(ui_Panel3, 284);
    lv_obj_set_x(ui_Panel3, 0);
    lv_obj_set_y(ui_Panel3, 16);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Panel3, &ui_img_images_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb1 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_bulb1, 75);
    lv_obj_set_height(ui_bulb1, 75);
    lv_obj_set_x(ui_bulb1, -160);
    lv_obj_set_y(ui_bulb1, -90);
    lv_obj_set_align(ui_bulb1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bulb1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_bulb1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_bulb1, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_bulb1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_glow1 = lv_img_create(ui_bulb1);
    lv_img_set_src(ui_glow1, &ui_img_1479671303);
    lv_obj_set_width(ui_glow1, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_glow1, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_align(ui_glow1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_glow1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_glow1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_glow1, 100);

    ui_off1 = lv_obj_create(ui_bulb1);
    lv_obj_set_width(ui_off1, 47);
    lv_obj_set_height(ui_off1, 47);
    lv_obj_set_align(ui_off1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_off1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_off1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_off1, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_off1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_off1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_off1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_off1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_off1, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_on1 = lv_img_create(ui_bulb1);
    lv_img_set_src(ui_on1, &ui_img_1398601068);
    lv_obj_set_width(ui_on1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_on1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_on1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_on1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_on1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_on1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb_Button1 = lv_btn_create(ui_bulb1);
    lv_obj_set_width(ui_bulb_Button1, 62);
    lv_obj_set_height(ui_bulb_Button1, 62);
    lv_obj_set_align(ui_bulb_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bulb_Button1, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bulb_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_bulb_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb2 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_bulb2, 75);
    lv_obj_set_height(ui_bulb2, 75);
    lv_obj_set_x(ui_bulb2, -30);
    lv_obj_set_y(ui_bulb2, -90);
    lv_obj_set_align(ui_bulb2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bulb2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_bulb2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_bulb2, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_glow2 = lv_img_create(ui_bulb2);
    lv_img_set_src(ui_glow2, &ui_img_1479671303);
    lv_obj_set_width(ui_glow2, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_glow2, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_align(ui_glow2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_glow2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_glow2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_glow2, 100);

    ui_off2 = lv_obj_create(ui_bulb2);
    lv_obj_set_width(ui_off2, 47);
    lv_obj_set_height(ui_off2, 47);
    lv_obj_set_align(ui_off2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_off2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_off2, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_off2, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_off2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_off2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_off2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_off2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_off2, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_on2 = lv_img_create(ui_bulb2);
    lv_img_set_src(ui_on2, &ui_img_1398601068);
    lv_obj_set_width(ui_on2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_on2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_on2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_on2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_on2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_on2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb_Button2 = lv_btn_create(ui_bulb2);
    lv_obj_set_width(ui_bulb_Button2, 62);
    lv_obj_set_height(ui_bulb_Button2, 62);
    lv_obj_set_align(ui_bulb_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bulb_Button2, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bulb_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_bulb_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb3 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_bulb3, 75);
    lv_obj_set_height(ui_bulb3, 75);
    lv_obj_set_x(ui_bulb3, -160);
    lv_obj_set_y(ui_bulb3, 0);
    lv_obj_set_align(ui_bulb3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bulb3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_bulb3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_bulb3, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_glow3 = lv_img_create(ui_bulb3);
    lv_img_set_src(ui_glow3, &ui_img_1479671303);
    lv_obj_set_width(ui_glow3, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_glow3, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_align(ui_glow3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_glow3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_glow3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_glow3, 100);

    ui_off3 = lv_obj_create(ui_bulb3);
    lv_obj_set_width(ui_off3, 47);
    lv_obj_set_height(ui_off3, 47);
    lv_obj_set_align(ui_off3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_off3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_off3, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_off3, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_off3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_off3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_off3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_off3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_off3, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_on3 = lv_img_create(ui_bulb3);
    lv_img_set_src(ui_on3, &ui_img_1398601068);
    lv_obj_set_width(ui_on3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_on3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_on3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_on3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_on3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_on3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb_Button3 = lv_btn_create(ui_bulb3);
    lv_obj_set_width(ui_bulb_Button3, 62);
    lv_obj_set_height(ui_bulb_Button3, 62);
    lv_obj_set_align(ui_bulb_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bulb_Button3, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bulb_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_bulb_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb4 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_bulb4, 75);
    lv_obj_set_height(ui_bulb4, 75);
    lv_obj_set_x(ui_bulb4, -30);
    lv_obj_set_y(ui_bulb4, 0);
    lv_obj_set_align(ui_bulb4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bulb4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_bulb4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_bulb4, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_glow4 = lv_img_create(ui_bulb4);
    lv_img_set_src(ui_glow4, &ui_img_1479671303);
    lv_obj_set_width(ui_glow4, LV_SIZE_CONTENT);   /// 60
    lv_obj_set_height(ui_glow4, LV_SIZE_CONTENT);    /// 60
    lv_obj_set_align(ui_glow4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_glow4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_glow4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_glow4, 100);

    ui_off4 = lv_obj_create(ui_bulb4);
    lv_obj_set_width(ui_off4, 47);
    lv_obj_set_height(ui_off4, 47);
    lv_obj_set_align(ui_off4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_off4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_off4, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_off4, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_off4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_off4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_off4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_off4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_off4, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_on4 = lv_img_create(ui_bulb4);
    lv_img_set_src(ui_on4, &ui_img_1398601068);
    lv_obj_set_width(ui_on4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_on4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_on4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_on4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_on4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_on4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bulb_Button4 = lv_btn_create(ui_bulb4);
    lv_obj_set_width(ui_bulb_Button4, 63);
    lv_obj_set_height(ui_bulb_Button4, 62);
    lv_obj_set_align(ui_bulb_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bulb_Button4, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bulb_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_bulb_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel4 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_Panel4, 194);
    lv_obj_set_height(ui_Panel4, 209);
    lv_obj_set_x(ui_Panel4, 132);
    lv_obj_set_y(ui_Panel4, -27);
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0xF1F2F3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel4, lv_color_hex(0xB9B9B9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel4, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Panel4, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Panel4, 150, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel8 = lv_obj_create(ui_Panel4);
    lv_obj_set_width(ui_Panel8, 194);
    lv_obj_set_height(ui_Panel8, 209);
    lv_obj_set_align(ui_Panel8, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_blend_mode(ui_Panel8, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Panel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image8 = lv_img_create(ui_Panel8);
    lv_img_set_src(ui_Image8, &ui_img_ffann_png);
    lv_obj_set_width(ui_Image8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image8, 4);
    lv_obj_set_y(ui_Image8, -44);
    lv_obj_set_align(ui_Image8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button4 = lv_btn_create(ui_Panel8);
    lv_obj_set_width(ui_Button4, 73);
    lv_obj_set_height(ui_Button4, 93);
    lv_obj_set_x(ui_Button4, 1);
    lv_obj_set_y(ui_Button4, -43);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_blend_mode(ui_Button4, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ////////////////////////////////////////////
    
    lv_style_init(&style_bg);
    lv_style_set_pad_all(&style_bg,7); 

    btnm1 = lv_btnmatrix_create(ui_Panel8);
    lv_btnmatrix_set_map(btnm1, btnm_map);
    lv_obj_add_style(btnm1,&style_bg,0);
    lv_obj_set_size(btnm1, 180, 100);
    lv_obj_set_style_blend_mode(btnm1, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_btnmatrix_set_btn_ctrl_all(btnm1, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_one_checked(btnm1, true);
    lv_btnmatrix_set_btn_ctrl(btnm1, 0, LV_BTNMATRIX_CTRL_CHECKED);
    lv_obj_align(btnm1, LV_ALIGN_CENTER, 0, 50);

    ui_Panel2 = lv_obj_create(ui_Panel8);
    lv_obj_set_width(ui_Panel2, 15);
    lv_obj_set_height(ui_Panel2, 15);
    lv_obj_set_x(ui_Panel2, -80);
    lv_obj_set_y(ui_Panel2, -88);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x9E9E9E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel9 = lv_obj_create(ui_Panel8);
    lv_obj_set_width(ui_Panel9, 15);
    lv_obj_set_height(ui_Panel9, 15);
    lv_obj_set_x(ui_Panel9, -80);
    lv_obj_set_y(ui_Panel9, -88);
    lv_obj_set_align(ui_Panel9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Panel9, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_Panel9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel9, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel9, lv_color_hex(0x00FF02), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel9, lv_color_hex(0x47FF49), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel9, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel9, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    /////////////////////////////////////////////


    ui_Panel5 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_Panel5, 270);
    lv_obj_set_height(ui_Panel5, 54);
    lv_obj_set_x(ui_Panel5, 310);
    lv_obj_set_y(ui_Panel5, 110);
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel5, 27, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image5 = lv_img_create(ui_Panel5);
    lv_img_set_src(ui_Image5, &ui_img_934653470);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 50
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_Image5, -108);
    lv_obj_set_y(ui_Image5, 0);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_Image5, -900);

    ui_rightPanel = lv_btn_create(ui_Panel5);
    lv_obj_set_width(ui_rightPanel, 50);
    lv_obj_set_height(ui_rightPanel, 50);
    lv_obj_set_x(ui_rightPanel, -106);
    lv_obj_set_y(ui_rightPanel, -2);
    lv_obj_set_align(ui_rightPanel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_rightPanel, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_rightPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_rightPanel, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_rightPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image7 = lv_img_create(ui_Panel5);
    lv_img_set_src(ui_Image7, &ui_img_oie_148732xscze6qq_png);
    lv_obj_set_width(ui_Image7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image7, -43);
    lv_obj_set_y(ui_Image7, 0);
    lv_obj_set_align(ui_Image7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image10 = lv_img_create(ui_Panel5);
    lv_img_set_src(ui_Image10, &ui_img_oie_14882ghc33bll_png);
    lv_obj_set_width(ui_Image10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image10, 28);
    lv_obj_set_y(ui_Image10, 0);
    lv_obj_set_align(ui_Image10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image10, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel7 = lv_obj_create(ui_Panel3);
    lv_obj_set_width(ui_Panel7, 93);
    lv_obj_set_height(ui_Panel7, 54);
    lv_obj_set_x(ui_Panel7, -213);
    lv_obj_set_y(ui_Panel7, 110);
    lv_obj_set_align(ui_Panel7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel7, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image6 = lv_img_create(ui_Panel7);
    lv_img_set_src(ui_Image6, &ui_img_1237411081);
    lv_obj_set_width(ui_Image6, LV_SIZE_CONTENT);   /// 50
    lv_obj_set_height(ui_Image6, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_x(ui_Image6, 7);
    lv_obj_set_y(ui_Image6, -1);
    lv_obj_set_align(ui_Image6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Image6, 300);

    lv_obj_add_event_cb(ui_bulb_Button1, ui_event_bulb_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bulb_Button2, ui_event_bulb_Button2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bulb_Button3, ui_event_bulb_Button3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bulb_Button4, ui_event_bulb_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(btnm1,ui_event_btnm, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_rightPanel, ui_event_rightPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Image10, ui_event_Image10, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Image6, ui_event_Image6, LV_EVENT_ALL, NULL);

}
void ui_Screen3_screen_init(void){
    ui_Screen3 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen3, &ui_img_fc872835a0134e57f19bff035bc065ce_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen3);
    lv_obj_set_width(ui_Button1, 423);
    lv_obj_set_height(ui_Button1, 263);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_blend_mode(ui_Button1, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);

}
void ui_Screen4_screen_init(void){
    ui_Screen4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Screen4, &ui_img_aa_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Screen4);
    lv_obj_set_width(ui_Button2, 423);
    lv_obj_set_height(ui_Button2, 263);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_blend_mode(ui_Button2, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen2_screen_init();
    ui_Screen1_screen_init();
    ui_Screen3_screen_init();
    ui_Screen4_screen_init();
    lv_disp_load_scr(ui_Screen2);
}
