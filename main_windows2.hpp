class main_window {

idd = 5;
movingEnable = true;

controls[]=
{
	frame_3,
	frame_1,
	frame_2,
	text_title,
	text_parts,
	text_supply,
	button_body,
	button_hands,
	button_legs,
	button_misc,
	button_head,
	button_bandage,
	button_morphine,
	button_adrenalin,
	button_splint,
	button_firstaid,
	button_diagnose,
	button_inspect,
	button_treat,
	text_report,
	text_report_title
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by |TG-355th| Yink, v1.063, #Pudolo)
////////////////////////////////////////////////////////

class frame_3: RscFrame
{
	idc = 1801;
	x = 0.6275 * safezoneW + safezoneX;
	y = 0.176985 * safezoneH + safezoneY;
	w = 0.111563 * safezoneW;
	h = 0.64603 * safezoneH;
	colorBackground[] = {0.12,0.12,0.12,0.9};
};
class frame_1: RscFrame
{
	idc = 1800;
	x = 0.260937 * safezoneW + safezoneX;
	y = 0.176985 * safezoneH + safezoneY;
	w = 0.111563 * safezoneW;
	h = 0.64603 * safezoneH;
	colorBackground[] = {0.12,0.12,0.12,0.9};
};
class frame_2: RscFrame
{
	idc = 1802;
	x = 0.3725 * safezoneW + safezoneX;
	y = 0.176985 * safezoneH + safezoneY;
	w = 0.255 * safezoneW;
	h = 0.204009 * safezoneH;
	colorBackground[] = {0.12,0.12,0.12,0.9};
};
class text_title: RscText
{
	idc = 1000;
	text = "MedYink Diagnostics"; //--- ToDo: Localize;
	x = 0.420312 * safezoneW + safezoneX;
	y = 0.0919812 * safezoneH + safezoneY;
	w = 0.159375 * safezoneW;
	h = 0.0850039 * safezoneH;
	colorBackground[] = {0,0,0,1};
};
class text_parts: RscText
{
	idc = 1001;
	text = "Parts"; //--- ToDo: Localize;
	x = 0.260937 * safezoneW + safezoneX;
	y = 0.125983 * safezoneH + safezoneY;
	w = 0.06375 * safezoneW;
	h = 0.0510023 * safezoneH;
	colorBackground[] = {0,0,0,1};
};
class text_supply: RscText
{
	idc = 1002;
	text = "Supplies"; //--- ToDo: Localize;
	x = 0.675313 * safezoneW + safezoneX;
	y = 0.125983 * safezoneH + safezoneY;
	w = 0.06375 * safezoneW;
	h = 0.0510023 * safezoneH;
	colorBackground[] = {0,0,0,1};
};
class button_body: RscButton
{
	idc = 1600;
	text = "Body"; //--- ToDo: Localize;
	x = 0.276875 * safezoneW + safezoneX;
	y = 0.329992 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player,""body""] spawn yink_fnc_diag_set;";
};
class button_hands: RscButton
{
	idc = 1601;
	text = "Hands"; //--- ToDo: Localize;
	x = 0.276875 * safezoneW + safezoneX;
	y = 0.448998 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player,""hands""] spawn yink_fnc_diag_set;";
};
class button_legs: RscButton
{
	idc = 1602;
	text = "Legs"; //--- ToDo: Localize;
	x = 0.276875 * safezoneW + safezoneX;
	y = 0.568003 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player,""legs""] spawn yink_fnc_diag_set;";
};
class button_misc: RscButton
{
	idc = 1603;
	text = "Misc."; //--- ToDo: Localize;
	x = 0.276875 * safezoneW + safezoneX;
	y = 0.687009 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player,""misc""] spawn yink_fnc_diag_set;";
};
class button_head: RscButton
{
	idc = 1604;
	text = "Head"; //--- ToDo: Localize;
	x = 0.276875 * safezoneW + safezoneX;
	y = 0.210987 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player,""head""] spawn yink_fnc_diag_set";
};
class button_bandage: RscButton
{
	idc = 1605;
	text = "Bandage"; //--- ToDo: Localize;
	x = 0.643438 * safezoneW + safezoneX;
	y = 0.210987 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "player setvariable [""currentItem"",""bandage""];";
};
class button_morphine: RscButton
{
	idc = 1606;
	text = "Morphine"; //--- ToDo: Localize;
	x = 0.643438 * safezoneW + safezoneX;
	y = 0.329992 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "player setvariable [""currentItem"",""morphine""];";
};
class button_adrenalin: RscButton
{
	idc = 1607;
	text = "Adrenaline"; //--- ToDo: Localize;
	x = 0.643438 * safezoneW + safezoneX;
	y = 0.448998 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "player setvariable [""currentItem"",""adrenalin""];";
};
class button_splint: RscButton
{
	idc = 1608;
	text = "Splint"; //--- ToDo: Localize;
	x = 0.643438 * safezoneW + safezoneX;
	y = 0.568003 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "player setvariable [""currentItem"",""splint""];";
};
class button_firstaid: RscButton
{
	idc = 1609;
	text = "Blood Bag"; //--- ToDo: Localize;
	x = 0.643438 * safezoneW + safezoneX;
	y = 0.687009 * safezoneH + safezoneY;
	w = 0.0796875 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "player setvariable [""currentItem"",""First Aid""];";
};
class button_diagnose: RscButton
{
	idc = 1610;
	text = "Diagnose"; //--- ToDo: Localize;
	x = 0.380469 * safezoneW + safezoneX;
	y = 0.193986 * safezoneH + safezoneY;
	w = 0.06375 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player] spawn yink_fnc_diag_diag;";
};
class button_inspect: RscButton
{
	idc = 1611;
	text = "Inspect"; //--- ToDo: Localize;
	x = 0.460156 * safezoneW + safezoneX;
	y = 0.193986 * safezoneH + safezoneY;
	w = 0.06375 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "dialogexe = [player] spawn yink_fnc_diag_inspect";
};
class button_treat: RscButton
{
	idc = 1612;
	text = "Treat"; //--- ToDo: Localize;
	x = 0.539844 * safezoneW + safezoneX;
	y = 0.193986 * safezoneH + safezoneY;
	w = 0.0717188 * safezoneW;
	h = 0.0680031 * safezoneH;
	colorBackground[] = {0,0,0,1};
	action = "_heal = [player,player getvariable ""currentItem""] spawn yink_fnc_diag_treat;";
};
class text_report: RscText
{
	idc = 1004;
	text = "Report:"; //--- ToDo: Localize;
	x = 0.388438 * safezoneW + safezoneX;
	y = 0.329992 * safezoneH + safezoneY;
	w = 0.223125 * safezoneW;
	h = 0.0510023 * safezoneH;
	colorBackground[] = {0,0,0,1};
	sizeEx = 0.75 * GUI_GRID_H;
};
class text_report_title: RscText
{
	idc = 1003;
	text = "Report"; //--- ToDo: Localize;
	x = 0.43625 * safezoneW + safezoneX;
	y = 0.295991 * safezoneH + safezoneY;
	w = 0.1275 * safezoneW;
	h = 0.0340016 * safezoneH;
	colorBackground[] = {0,0,0,1};
	sizeEx = 0.75 * GUI_GRID_H;
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////
};