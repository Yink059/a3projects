// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102

// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C
#define ST_GROUP_BOX       96
#define ST_GROUP_BOX2      112
#define ST_ROUNDED_CORNER  ST_GROUP_BOX + ST_CENTER
#define ST_ROUNDED_CORNER2 ST_GROUP_BOX2 + ST_CENTER

#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar 
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4

#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)

///////////////////////
//Yink's Base Classes//
///////////////////////

class YinkRscListBox
{
 access = 0;
 type = 5;
 style = 0;
 w = 0.4;
 h = 0.4;
 font = "TahomaB";
 sizeEx = 0.02021;
 rowHeight = 0;
 colorText[] = {1,1,1,1};
 colorScrollbar[] = {1,1,1,1};
 colorSelect[] = {1,1,1,1};
 colorSelect2[] = {1,0.5,0,1};
 colorSelectBackground[] = {0.6,0.6,0.6,0};
 colorSelectBackground2[] = {0.2,0.2,0.2,.5};
 colorDisabled[] = {0,0,0,1};
 colorBackground[] = {0.5,0.5,0.5,0};
 maxHistoryDelay = 1.0;
 soundSelect[] = {"",0.1,1};
 period = 1;
 autoScrollSpeed = -1;
 autoScrollDelay = 5;
 autoScrollRewind = 0;
 arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
 arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
 shadow = 0;
 class YinkScrollBar
 {
  color[] = {1,1,1,0.6};
  colorActive[] = {1,1,1,1};
  colorDisabled[] = {1,1,1,0.3};
  thumb = "#(argb,8,8,3)color(1,1,1,1)";
  arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
  arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
  border = "#(argb,8,8,3)color(1,1,1,1)";
  shadow = 0;

 };
 class YinkListScrollBar : YinkScrollBar
 {
  color[] = {1,1,1,0.6};
  colorActive[] = {1,1,1,1};
  colorDisabled[] = {1,1,1,0.3};
  thumb = "#(argb,8,8,3)color(1,1,1,1)";
  arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
  arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
  border = "#(argb,8,8,3)color(1,1,1,1)";
  shadow = 0;
 };
};

class YinkRscEdit
{
 access = 0;
 type = CT_EDIT;
 style = ST_LEFT+ST_FRAME;
 x = 0;
 y = 0;
 h = 0.04;
 w = 0.2;
 colorBackground[] = {0,0,0,0};
 colorText[] = {1,1,1,1};
 colorSelection[] = {1,1,1,0.25};
 colorDisabled[] = {0,0,0,1};
 font = "puristaLight";
 sizeEx = 0.0300;
 autocomplete = "";
 text = "";
 size = 0.2;
 shadow = 0;
};

class YinkRscText
{
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_MULTI;
    linespacing = 1;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    text = "";
    shadow = 2;
    font = "puristaLight";
    SizeEx = 0.0300;
    fixedWidth = 0;
    x = 0;
    y = 0;
    h = 0;
    w = 0;
   
};

class YinkRscPicture
{
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_PICTURE;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "puristaLight";
    sizeEx = 0;
    lineSpacing = 0;
    text = "";
    fixedWidth = 0;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.15;
};

class YinkRscButton
{
    
   access = 0;
    type = CT_BUTTON;
    text = "";
    colorText[] = {1,1,1,1};
    colorDisabled[] = {0,0,0,1};
    colorBackground[] = {0,0,0,1};
    colorBackgroundDisabled[] = {0,0,0,0};
    colorBackgroundActive[] = {1,0.64,0,1};
    colorFocused[] = {1,0.64,0,1};
    colorShadow[] = {0.023529,0,0.0313725,1};
    colorBorder[] = {0.023529,0,0.0313725,1};
    soundEnter[] = {"\ca\ui\data\sound\onover",0.09,1};
    soundPush[] = {"\ca\ui\data\sound\new1",0,0};
    soundClick[] = {"\ca\ui\data\sound\onclick",0.07,1};
    soundEscape[] = {"\ca\ui\data\sound\onescape",0.09,1};
    style = 2;
    x = 0;
    y = 0;
    w = 0.055589;
    h = 0.039216;
    shadow = 0;
    font = "puristaLight";
    sizeEx = 0.03000;
    offsetX = 0.003;
    offsetY = 0.003;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    borderSize = 0;
};

class YinkRscFrame
{
    type = CT_STATIC;
    idc = -1;
    style = ST_BACKGROUND;
    shadow = 1;
    colorBackground[] = {0.12,0.12,0.12,0.9};
    colorText[] = {1,1,1,0.9};
    font = "puristaLight";
    sizeEx = 0.03;
    text = "";
};

class YinkBOX
{ 
   type = CT_STATIC;
    idc = -1;
    style = ST_CENTER;
    shadow = 2;
    colorText[] = {1,1,1,1};
    font = "puristaLight";
    sizeEx = 0.02;
    colorBackground[] = { 0.2,0.2,0.2, 0.7}; 
    text = ""; 

};

