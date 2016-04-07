execVM "MedYink\diag_functions.sqf";

yink_fnc_addHealAction =
{

	if (isServer) then
	{
		{
			 _x setvariable ["hasHealAction", false, true];
		};
	}


	 player setvariable ["hasHealAction", false, true];
 
 

};


yink_fnc_single_des	=
	{
		_source1 = _this select 0;
		_final = 0;
		
					if (_source1 isKindOf "Grenade") 			then
					{	_final = 3;
					};
					
					if (_source1=="") 							then
					{	_final = 1;
					};
				
					if (_source1 isKindOf "MissileCore")		then
					{	_final = 3;
					};
					
					if (_source1 isKindOf "BombCore") 			then
					{	_final = 3;
					};
					
					if (_source1 isKindOf "RocketCore") 		then
					{	_final = 3;
					};	
						
					if (_source1 isKindOf "ShellCore") 			then
					{	_final = 3;
					};
					
					if (_source1 isKindOf "SubmunitionCore") 	then
					{	_final = 3;
					};
						
					if (_source1 isKindOf "ShotDeployCore")		then
					{	_final = 3;
					};
						
					if (_source1 isKindOf "GrenadeCore") 		then
					{	_final = 3;
					};
				
					if (_source1 isKindOf "TimeBombCore") 		then
					{	_final = 3;
					};
					
					if (_source1 isKindOf "BulletCore") 		then
					{	_final = 2;
					};
				
					if (_source1 isKindOf "ShotgunCore") 		then
					{	_final = 2;
					};
					
		_final
	};
	
	//used for generalizing injury data
yink_fnc_des_injury =
	{
		_partHit 	= _this select 0;
		_listUnit	= _this select 1;
		_tempList	= [_partHit,["misc",0],["bullet",0],["explosive",0]];
			{	if ((_partHit)==(_x select 0)) then
				{	_source1 	= _x select 2;
					_tempList0	= _tempList select 1;
					_tempList1	= _tempList select 2;
					_tempList2	= _tempList select 3;
					_tempList01 = ((_tempList select 1) select 1);
					_tempList11 = ((_tempList select 2) select 1);
					_tempList21 = ((_tempList select 3) select 1);
					
					
					if (_source1 isKindOf "Grenade") 			then
					{	_tempList2 set [1,_tempList21 + (_x select 1)];
					};
					
					if (_source1=="") 							then
					{	_tempList0 set [1,_tempList01 + (_x select 1)]
					};
				
					if (_source1 isKindOf "MissileCore")		then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
					
					if (_source1 isKindOf "BombCore") 			then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
					
					if (_source1 isKindOf "RocketCore") 		then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};	
						
					if (_source1 isKindOf "ShellCore") 			then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
					
					if (_source1 isKindOf "SubmunitionCore") 	then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
						
					if (_source1 isKindOf "ShotDeployCore")		then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
						
					if (_source1 isKindOf "GrenadeCore") 		then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
				
					if (_source1 isKindOf "TimeBombCore") 		then
					{	_tempList2 set [1,_tempList21 + (_x select 1)]
					};
					
					if (_source1 isKindOf "BulletCore") 		then
					{	_tempList1 set [1,_tempList11 + (_x select 1)]
					};
				
					if (_source1 isKindOf "ShotgunCore") 		then
					{	_tempList1 set [1,_tempList11 + (_x select 1)]
					};
				};
			} foreach _listUnit;
	
	_tempList
	};
	
	
//takes in a units damage data and sorts into a 5 index array
yink_fnc_part_list =
	{	_unit = _this select 0;
		_list = _unit getvariable "damageHist";
		_head	= [ ];//"head"
		_body	= [ ];//"body"
		_hands	= [ ];//"hands"
		_legs	= [ ];//"legs"
		_misc	= [ ];//""

		{	_part = _x select 0;
			switch (_part) do
			{		case "head"		: { _head 	= ["head"	,_list]	call yink_fnc_des_injury;};
					case "body"		: { _body 	= ["body"	,_list]	call yink_fnc_des_injury;};
					case "hands"	: { _hands 	= ["hands"	,_list]	call yink_fnc_des_injury;};
					case "legs"		: { _legs 	= ["legs"	,_list] call yink_fnc_des_injury;};
					case ""			: { _misc	= [""		,_list] call yink_fnc_des_injury;};
			};
		} foreach _list;
	_unit setvariable ["damageTotal",[_head,_body,_hands,_legs,_misc]];
	
	[_head,_body,_hands,_legs,_misc]
	};


//uses the damage list to deal bleed damage over time.	
yink_fnc_bleed_out =
	{	
		_unit = _this select 0;
		while {alive _unit} do
		{
			sleep 5;
			_list = _unit getVariable "damageTotal";
			{	_part = _x select 0;
				_mult = 1.0;
				switch (_part) do
				{	case "head"	: {_mult = 2.0};
					case "body"	: {_mult = 1.2};
					case "hands": {_mult = 0.5};
					case "legs" : {_mult = 0.8};
				};
				if (((_x select 1)<=0.15)&&((_x select 1)>0)) then
				{	_x set [1,(_x select 1) - 0.03];
				};
				if ((_x select 1)<0.03) then
				{	_x set [1,0];
				};
				if ((_x select 1)>0.15) then
				{
					_bleed = ((_x select 1)/100) * _mult;
					_unit setdamage ((damage _unit)+_bleed);
				};
			} foreach _list;
		};
	};
	
	
	
//healing function that takes the unit,part and item used and applies the heal accordingly
yink_fnc_heal =//_heal = [_caller,_item,_part] call yink_fnc_heal;
	{
		_unit 	= _this select 0;
		_list = [_unit] call yink_fnc_part_list;
		_item 	= _this select 1;
		_part 	= _this select 2;
		_amount	= _this select 3;
		
		switch (_part) do
		{	case "head"	:
			{	_array = _list select 0;
				switch (_item) do
				{	case "bandage":
					{	_temp1 = 0;
						_list2 = _unit getVariable "damageHist";
						_list3 = _list2;
						_ran1 = (round(random 1)) + 2;
						_counter = 0;
						_temp2 = 3;
						{	
							if ((((_x select 0)=="head")&&(_temp1<0.35))||((_counter<1)&&((_x select 0)=="head"))) then
							{	_temp1 = _temp1 + (_x select 1);
								_counter = _counter + 1;
								_temp2 = [_x select 2] call yink_fnc_single_des;
								_unit setHit ["head",((((_list select 0) select _temp2) select 1) - (_x select 1))];
								_list2 = _list2 - [_x];
								_list = [_unit] call yink_fnc_part_list;
							};
						} forEach _list3;
						_unit setVariable ["damageHist",_list2];
					};
				};
			};
		
			case "body"	:
			{	_array = _list select 1;
				switch (_item) do
				{	case "bandage":
					{	_temp1 = 0;
						_list2 = _unit getvariable "damageHist";
						_list3 = _list2;
						_ran1 = 3;
						_counter = 0;
						{	
							if ((((_x select 0)=="body")&&(_temp1<0.35))||((_counter<1)&&((_x select 0)=="body"))) then
							{	_temp1 = _temp1 + (_x select 1);
								_counter = _counter + 1;
								_temp2 = [_x select 2] call yink_fnc_single_des;
								_unit sethit ["body",((((_list select 1) select _temp2) select 1) - (_x select 1))];
								_list2 = _list2 - [_x];
								_list = [_unit] call yink_fnc_part_list;
							};
						} foreach _list3;
						_unit setvariable ["damageHist",_list2];
					};
					case "morphine":
					{	if ((damage _unit)>0.30) then
						{	_unit setdamage ((damage _unit) - 0.30);
						}
						else
						{	_unit setdamage 0;
						};
					};
				};
			};
		
			case "hands":
			{	_array = _list select 2;
				switch (_item) do
				{	case "bandage":
					{	_temp1 = 0;
						_list2 = _unit getVariable "damageHist";
						_list3 = _list2;
						_ran1 = 3;
						_counter = 0;
						{	
							if ((((_x select 0)=="hands")&&(_temp1<0.35))||((_counter<1)&&((_x select 0)=="hands"))) then
							{	_temp1 = _temp1 + (_x select 1);
								_counter = _counter + 1;
								_temp2 = [_x select 2] call yink_fnc_single_des;
								_unit setHit ["head",(((_list select 2) select _temp2) select 1)  - (_x select 1)];
								_list2 = _list2 - [_x];
								_list = [_unit] call yink_fnc_part_list;
							};
						} forEach _list3;
						_unit setVariable ["damageHist",_list2];
					};
					case "powder":
					{	if ((damage _unit)>0.30) then
						{	_unit setDamage ((damage _unit) - 0.30);
						}
						else
						{	_unit setDamage 0;
						};
					};
				};
			};
			case "legs":
			{	_array = _list select 2;
				switch (_item) do
				{	case "bandage":
					{	_temp1 = 0;
						_list2 = _unit getvariable "damageHist";
						_list3 = _list2;
						_ran1 = 3;
						_counter = 0;
						{	
							if ((((_x select 0)=="legs")&&(_temp1<0.35))||((_counter<1)&&((_x select 0)=="legs"))) then
							{	_temp1 = _temp1 + (_x select 1);
								_counter = _counter + 1;
								_temp2 = [_x select 2] call yink_fnc_single_des;
								_unit sethit ["legs",(((_list select 3) select _temp2) select 1)  - (_x select 1)];
								_list2 = _list2 - [_x];
								_list = [_unit] call yink_fnc_part_list;
							};
						} foreach _list3;
						_unit setvariable ["damageHist",_list2];
					};
					case "Splint":
					{	if ((damage _unit)>0.30) then
						{	_unit setdamage ((damage _unit) - 0.30);
						}
						else
						{	_unit setdamage 0;
						};
					};
				};
			};
			case "misc":
			{
				switch (_item) do
				{
					case "bandage":
					{	_temp1 = 0;
						_list2 = _unit getvariable "damageHist";
						_list3 = _list2;
						_ran1 = 3;
						_counter = 0;
						{	
							if ((((_x select 0)=="")&&(_temp1<0.35))||((_counter<1)&&((_x select 0)==""))) then
							{	_temp1 = _temp1 + (_x select 1);
								_counter = _counter + 1;
								_temp2 = [_x select 2] call yink_fnc_single_des;
								_unit sethit ["",(((_list select 4) select _temp2) select 1)  - (_x select 1)];
								_list2 = _list2 - [_x];
								_list = [_unit] call yink_fnc_part_list;
							};
						} foreach _list3;
						_unit setvariable ["damageHist",_list2];
					};
					case "First Aid":
					{		
						_temp1 = _unit getvariable "damageHist";
						{
							if ((_x select 0)=="") then
							{	_temp1 = _temp1 - [_x];
							};
						} foreach _temp1;
						_unit setvariable ["damageHist",_temp1];
						_unit setdamage ((damage _unit) - 0.05);
					};
				};
			};
		};
		_list = [_unit] call yink_fnc_part_list;
		
	_bool1
	};
	
yink_fnc_anim =
	{
		_caller = _this select 0;
		_caller setvariable ["loop_anim","true"];
		_anim_caller = "";
		_anim_target = "";
		_part	= _caller getvariable "currentPart";
		_array	= _caller getvariable "diagVars";
		_target = _array select 0;
		_type	= _this select 1;
		_target attachto [_caller,[0,0.75,0]];
		sleep 0.5;
		_target setDir 90;
		_anim_state	 = animationState _caller;
		while {((_caller getvariable "loop_anim")=="true")} do
		{
			if (true) then
			{
				switch (_type) do
				{
					case "diag"		: {_anim_caller = "AinvPknlMstpSnonWnonDr_medic4"};
					case "inject"	: {_anim_caller = "AinvPknlMstpSnonWnonDnon_medic1"};
					case "head"		: {_anim_caller = "AinvPknlMstpSnonWnonDnon_medic0"};
					case "body"		: {_anim_caller = "AinvPknlMstpSnonWnonDnon_medic4"};
					case "legs"		: {_anim_caller = "AinvPknlMstpSnonWnonDr_medic2"};
					case "hands"	: {_anim_caller = "AinvPknlMstpSnonWnonDnon_medic2"};
					case "misc"		: {_anim_caller = "AinvPknlMstpSnonWnonDnon_medic3"};
				};
				target1 = _target;
				publicVariable "target1";
				[{target1 switchmove "AinjPpneMstpSnonWnonDnon";},"BIS_fnc_spawn",true,true] call BIS_fnc_MP;
				caller1 = _caller;
				publicVariable "caller1";
				anim_caller1 = _anim_caller;
				publicVariable "anim_caller1";
				[{caller1 playmove anim_caller1;},"BIS_fnc_spawn",true,true] call BIS_fnc_MP;
				
				
				[{target1 enableSimulation false;},"BIS_fnc_spawn",true,true] call BIS_fnc_MP;
				sleep 2;
					
			};
		};
		detach _target;
		target1 = _target;
		publicVariable "target1";
		[{target1 enableSimulation true;},"BIS_fnc_spawn",true,true] call BIS_fnc_MP;
		
	};
			
	





	