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


////////////////
//Base Classes//
////////////////

class RscListBox
{
 access = 0;
 type = 5;
 style = 0;
 w = 0.4;
 h = 0.4;
 font = "TahomaB";
 sizeEx = 0.02021;
 rowHeight = 0;
 colorText[] = {0,0,0,1};
 colorScrollbar[] = {1,1,1,1};
 colorSelect[] = {0,0,0,1};
 colorSelect2[] = {1,0.5,0,1};
 colorSelectBackground[] = {0.6,0.6,0.6,0};
 colorSelectBackground2[] = {0.2,0.2,0.2,.5};
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
 class ScrollBar
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

class RscText
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
    font = "Bitstream";
    SizeEx = 0.0300;
    fixedWidth = 0;
    x = 0;
    y = 0;
    h = 0;
    w = 0;
   
};

class RscPicture
{
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_PICTURE;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "Bitstream";
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

class RscButton
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
    font = "Bitstream";
    sizeEx = 0.03000;
    offsetX = 0.003;
    offsetY = 0.003;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    borderSize = 0;
};

class RscFrame
{
    type = CT_STATIC;
    idc = -1;
    style = ST_BACKGROUND;
    shadow = 2;
    colorBackground[] = {0.12,0.12,0.12,0.9};
    colorText[] = {1,1,1,0.9};
    font = "Bitstream";
    sizeEx = 0.03;
    text = "";
};

class BOX
{ 
   type = CT_STATIC;
    idc = -1;
    style = ST_CENTER;
    shadow = 2;
    colorText[] = {1,1,1,1};
    font = "Bitstream";
    sizeEx = 0.02;
    colorBackground[] = { 0.2,0.2,0.2, 0.7}; 
    text = ""; 

};

class	RscMapControl
{
  type = CT_MAP_MAIN;
  idc = -1;
  style = ST_PICTURE;
  
  x = 0.1;
  y = 0.1;
  w = 0.3;
  h = 0.3;

  colorSea[] = {0.56, 0.8, 0.98, 0.5};
	colorForest[] = {0.6, 0.8, 0.2, 0.5};
	colorRocks[] = {0.6, 0.45, 0.27, 0.4};
	colorCountlines[] = {0.5, 0.33, 0.1, 1};
  colorCountlinesWater[] = {0, 0.53, 1, 1};
  colorMainCountlines[] = {0.55, 0.45, 0.27, 1};
  colorMainCountlinesWater[] = {0, 0.53, 1, 1};
  colorPowerLines[] = {Dlg_Color_Black, 1};
  colorLevels[] = {Dlg_Color_Black, 1};
	colorForestBorder[] = {0.4, 0.8, 0, 1};
	colorRocksBorder[] = {0.6, 0.45, 0.27, 0.4};
	colorNames[] = {Dlg_Color_Black, 1};
	colorInactive[] = {Dlg_Color_White, 0.5};
  colorBackground[] = {Dlg_Color_White, 1};
  colorText[] = {Dlg_Color_White, 1};
  
  font = "Zeppelin32";
  sizeEx = 0.05;
  
  fontLabel = "Zeppelin32";
	sizeExLabel = 0.0286458;
	fontGrid = "Zeppelin32";
	sizeExGrid = 0.0286458;
	fontUnits = "Zeppelin32";
	sizeExUnits = 0.0286458;
	fontNames = "Zeppelin32";
	sizeExNames = 0.0286458;
	fontInfo = "Zeppelin32";
	sizeExInfo = 0.0286458;
	fontLevel = "Zeppelin32";
	sizeExLevel = 0.0286458;
  
  ptsPerSquareSea	= 6;
  ptsPerSquareTxt	= 8;
  ptsPerSquareCLn	= 8;
  ptsPerSquareExp	= 8;
  ptsPerSquareCost = 8;
  ptsPerSquareFor = "4.0f";
  ptsPerSquareForEdge = "10.0f";
  ptsPerSquareRoad = 2;
  ptsPerSquareObj = 10;
	
	text = "\ca\ui\data\map_background2_co.paa";
  ShowCountourInterval = 0;
  scaleDefault = 0.1;
  onMouseButtonClick = "";
  onMouseButtonDblClick = "";
		class Task {
		icon = "\ca\ui\data\map_cross_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
		
		//icon = "\ca\ui\data\map_waypoint_ca.paa";
        iconCreated = "#(argb,8,8,3)color(1,1,1,1)";
        iconCanceled = "#(argb,8,8,3)color(0,0,1,1)";
        iconDone = "#(argb,8,8,3)color(0,0,0,1)";
        iconFailed = "#(argb,8,8,3)color(1,0,0,1)";
        colorCreated[] = {1,1,1,1};
        colorCanceled[] = {1,1,1,1};
        colorDone[] = {1,1,1,1};
        colorFailed[] = {1,1,1,1};
        // size = 20;
        // color[] = {0, 0.900000, 0, 1};
        // importance = "1.2 * 16 * 0.05";
        // coefMin = 0.900000;
        // coefMax = 4; 
	};

	class CustomMark {
		icon = "\ca\ui\data\map_cross_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};

  class ActiveMarker {
    color[] = {0.3, 0.1, 0.9, 1};
    size	= 50;
  };

	class Legend {
		x = 0.729;
		y = 0.05;
		w = 0.237;
		h = 0.127;
		font = "Zeppelin32";
		sizeEx = 0.0208333;
		colorBackground[] = {0.906, 0.901, 0.88, 0.8};
		color[] = {Dlg_Color_Black, 1};
	};
	
	class Bunker {
    color[] = {0, 0.35, 0.7, 1};
		icon = "\ca\ui\data\map_bunker_ca.paa";
		size = 14;
		importance = 1.5 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Bush {
		icon = "\ca\ui\data\map_bush_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 14;
		importance = 0.2 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class BusStop {
		icon = "\ca\ui\data\map_busstop_ca.paa";
		color[] = {0, 0, 1, 1};
		size = 10;
		importance = 1 * 10 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Command {
		icon = "#(argb,8,8,3)color(1,1,1,1)";
		color[] = {0, 0.9, 0, 1};
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	
	class Cross {
	color[] = {0, 0.35, 0.7, 1};
		icon = "\ca\ui\data\map_cross_ca.paa";
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fortress {
		icon = "\ca\ui\data\map_bunker_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fuelstation {
		icon = "\ca\ui\data\map_fuelstation_ca.paa";
	color[] = {1.0, 0.35, 0.35, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.75;
		coefMax = 4;
	};
	
	class Fountain {
		icon = "\ca\ui\data\map_fountain_ca.paa";
		color[] = {0, 0.35, 0.7, 1};
		size = 12;
		importance = 1 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Hospital {
		icon = "\ca\ui\data\map_hospital_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Chapel {
		icon = "\ca\ui\data\map_chapel_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Church {
		icon = "\ca\ui\data\map_church_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Lighthouse {
		icon = "\ca\ui\data\map_lighthouse_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 20;
		importance = 3 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Quay {
		icon = "\ca\ui\data\map_quay_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Rock {
	color[] = {0.35, 0.35, 0.35, 1};
		icon = "\ca\ui\data\map_rock_ca.paa";
		size = 12;
		importance = 0.5 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Ruin {
		icon = "\ca\ui\data\map_ruin_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 1.2 * 16 * 0.05;
		coefMin = 1;
		coefMax = 4;
	};
	
	class SmallTree {
		icon = "\ca\ui\data\map_smalltree_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 12;
		importance = 0.6 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Stack {
		icon = "\ca\ui\data\map_stack_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 20;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Tree {
		icon = "\ca\ui\data\map_tree_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 12;
		importance = 0.9 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Tourism {
		icon = "\ca\ui\data\map_tourism_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.7;
		coefMax = 4;
	};
	
	class Transmitter {
		icon = "\ca\ui\data\map_transmitter_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 20;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class ViewTower {
		icon = "\ca\ui\data\map_viewtower_ca.paa";
	color[] = {0, 0.35, 0.7, 1};
		size = 16;
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Watertower {
		icon = "\ca\ui\data\map_watertower_ca.paa";
		color[] = {0, 0.35, 0.7, 1};
		size = 32;
		importance = 1.2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Waypoint {
		icon = "\ca\ui\data\map_waypoint_ca.paa";
  	color[] = {0, 0.35, 0.7, 1};
  	size = 32;
  	coefMin = 1.00;
  	coefMax = 1.00;
  	importance = 1.00;
	};
	
	class WaypointCompleted {
		icon = "\ca\ui\data\map_waypoint_completed_ca.paa";
  	color[] = {Dlg_Color_Black, 1};
  	size = 24;
  	importance = 1.00;
  	coefMin = 1.00;
  	coefMax = 1.00;
	};
};