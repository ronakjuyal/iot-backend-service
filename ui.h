// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

struct screenButton{
    bool led1;
    bool led2;
    bool led3;
    bool led4;
    bool fan;
    int fan_speed;
 };
extern struct screenButton states;
extern struct screenButton states;
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
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_bulb1;
extern lv_obj_t * ui_glow1;
extern lv_obj_t * ui_off1;
extern lv_obj_t * ui_on1;
void ui_event_bulb_Button1(lv_event_t * e);
extern lv_obj_t * ui_bulb_Button1;
extern lv_obj_t * ui_bulb2;
extern lv_obj_t * ui_glow2;
extern lv_obj_t * ui_off2;
extern lv_obj_t * ui_on2;
void ui_event_bulb_Button2(lv_event_t * e);
extern lv_obj_t * ui_bulb_Button2;
extern lv_obj_t * ui_bulb3;
extern lv_obj_t * ui_glow3;
extern lv_obj_t * ui_off3;
extern lv_obj_t * ui_on3;
void ui_event_bulb_Button3(lv_event_t * e);
extern lv_obj_t * ui_bulb_Button3;
extern lv_obj_t * ui_bulb4;
extern lv_obj_t * ui_glow4;
extern lv_obj_t * ui_off4;
extern lv_obj_t * ui_on4;
void ui_event_bulb_Button4(lv_event_t * e);
extern lv_obj_t * ui_bulb_Button4;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Panel8;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Image8;
  ////////////////////////////////
 void ui_event_btnm(lv_event_t * e);
  extern const char* btnm_map[];
  extern lv_obj_t* btnm1;
  extern lv_style_t style_bg;
  extern lv_obj_t* ui_Panel2;
  extern lv_obj_t* ui_Panel9;
  ////////////////////////
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Panel5;
extern lv_obj_t * ui_Image5;
void ui_event_rightPanel(lv_event_t * e);
extern lv_obj_t * ui_rightPanel;
extern lv_obj_t * ui_Image7;
void ui_event_Image10(lv_event_t * e);
extern lv_obj_t * ui_Image10;
extern lv_obj_t * ui_Panel7;
void ui_event_Image6(lv_event_t * e);
extern lv_obj_t * ui_Image6;
extern lv_obj_t * ui_Screen3;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Screen4;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern void get_states();

LV_IMG_DECLARE(ui_img_488449546);    // assets\oie_TqOKCx1krI2O (1).png
LV_IMG_DECLARE(ui_img_oie_552325lzwjvdft_png);    // assets\oie_552325LzwjvdFt.png
LV_IMG_DECLARE(ui_img_oie_55240fpthker1_png);    // assets\oie_55240fPThkER1.png
LV_IMG_DECLARE(ui_img_images_png);    // assets\images.png
LV_IMG_DECLARE(ui_img_1479671303);    // assets\oie_transparent (13).png
LV_IMG_DECLARE(ui_img_1398601068);    // assets\oie_transparent (12).png
LV_IMG_DECLARE(ui_img_796806710);    // assets\oie_transparent (14).png
LV_IMG_DECLARE(ui_img_oie_06z1ggoapdj4_png);    // assets\oie_06z1ggoApDJ4.png
LV_IMG_DECLARE(ui_img_934653470);    // assets\icons8-slide-up-50.png
LV_IMG_DECLARE(ui_img_oie_148732xscze6qq_png);    // assets\oie_148732XsczE6QQ.png
LV_IMG_DECLARE(ui_img_oie_14882ghc33bll_png);    // assets\oie_14882GHC33BlL.png
LV_IMG_DECLARE(ui_img_1237411081);    // assets\icons8-partly-cloudy-day-50 (1).png
LV_IMG_DECLARE(ui_img_fc872835a0134e57f19bff035bc065ce_png);    // assets\fc872835a0134e57f19bff035bc065ce.png
LV_IMG_DECLARE(ui_img_aa_png);    // assets\aa.png
LV_IMG_DECLARE(ui_img_ffann_png);




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
