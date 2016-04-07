////diag functions

yink_fnc_diag =
	{	_target = _this select 0;
		_caller = _this select 1;
		_id		= _this select 2;
		_currentDiag = "";
		_array 	= [_target,_caller,_id,_currentdiag];
		_caller setvariable ["diagVars",[_target,_caller,_id,_currentdiag]];
		caller1 = _caller;
		[{caller1 switchmove "";},"BIS_fnc_spawn",true,true] call BIS_fnc_MP;
		_caller setvariable ["loop_anim","false"];
		createDialog "main_window";
		
		ctrlSetText
		[
			1003,
			name _target + " has:"
		];
		
		[_target,_caller] spawn 
		{
			_target = _this select 0;
			_caller = _this select 1;
			waituntil
			{	(((_target distance _caller)>5)||(!dialog))
			};
			closeDialog 5;
		};
		
		waituntil {!dialog};
		[{caller1 switchmove "";},"BIS_fnc_spawn",true,true] call BIS_fnc_MP;
		_caller setvariable ["loop_anim","false"];
	};

yink_fnc_diag_set =
	{	_caller = _this select 0;
		_part 	= _this select 1;
		ctrlSetText 
		[	
			1004,
			"Looking at " + _part + "."
		];
		
		_caller setvariable
		[	"currentPart",
			_part
		];
	};
	
yink_fnc_diag_diag =
	{
		if !(dialog) exitwith { };
		_caller = _this select 0;
		_part	= _caller getvariable "currentPart";
		_array	= _caller getvariable "diagVars";
		_target = _array select 0;
		_list2 	= [ ];
		_list 	= [_target] call yink_fnc_part_list;
		_temp1 	= [ ];
		_string2= "";
	
		{
			if (((_x select 0)==(_caller getvariable "currentPart"))||((_x select 0)=="")) then
			{	
			
				_string2 = (_caller getvariable "currentPart");
				_temp1 = _x - [_x select 0];
				_list2 = _list2 + _temp1;

			};

		} foreach _list;
		
		_ran1 = 20 + (round(random 15));
		_string1 = ["",".","..","...","....",".....","......"];
		_num1 = 0;
		_cond = "up";
		_cond2= 1;
		_caller setvariable ["loop_anim","true"];
		_script = [_caller,"diag"] spawn yink_fnc_anim;
		
		for [{_i=0},{_i<=_ran1},{_i=_i+1}] do
		{	_string2 = _string1 select _num1;
			ctrlSetText 
			[
				1004,
				"Working" +_string2
			];
			if (_num1==6) then 
			{	_cond = "down";
			};
			if (_num1==0) then 
			{	_cond = "up";
			};
			switch (_cond) do
			{	case "down"	:{_num1=_num1-1};
				case "up"	:{_num1=_num1+1};
			};
		sleep 0.125;
		};
		{
			_part	= _caller getvariable "currentPart";
			_severity = "";
			_num1 = (_x select 1);
			if (_num1==0) then
			{	_severity = "No";
			};
			if (_num1>0) then
			{	_severity= "Light";
			};
			if (_num1>0.15) then
			{	_severity = "Minor";
			};
			if (_num1>0.30) then
			{	_severity = "Moderate";
			};
			if (_num1>0.50) then
			{	_severity = "Major";
			};
			if (_num1>0.65) then
			{	_severity = "Severe";
			};
			if (_num>0.80) then
			{	_severity = "Critical";
			};
			ctrlSetText 
			[
				1004,
				format
				[
					"%1 %2 damage to the %3.",
					_severity,
					(_x select 0),
					_part
				]
			];
			sleep 2.5;
		} foreach _list2;
		
		if ((count _list2)==0) then
		{	ctrlSetText 
			[
				1004,
				"No Injuries to report."
			];
			sleep 2.5;
		};
		_array = _caller getVariable "diagVars";
		_array set [3,_part];
		_caller setVariable ["diagVars",_array];
		ctrlSetText 
		[
			1004,
			"Diagnostic Complete."
		];
	_caller setvariable ["loop_anim","false"];
	detach _target;
	};
	
yink_fnc_diag_inspect =
	{
		_num1 = 0;
		_num2 = 1;
		_severity = "No";
		_caller = _this select 0;
		_target = (_caller getvariable "diagVars") select 0;
		_caller setvariable ["loop_anim","true"];
		_list	= [_target] call yink_fnc_part_list;
		_script = [_caller,"diag"] spawn yink_fnc_anim;
		_ran1 = 60 + (round(random 20));
		_string1 = ["",".","..","...","....",".....","......"];
		_num1 = 0;
		_cond = "up";
		for [{_i=0},{_i<=60},{_i=_i+1}] do
		{	_string2 = _string1 select _num1;
			ctrlSetText 
			[
				1004,
				"Working" +_string2
			];
			if (_num1==6) then 
			{	_cond = "down";
			};
			if (_num1==0) then 
			{	_cond = "up";
			};
			switch (_cond) do
			{	case "down"	:{_num1=_num1-1};
				case "up"	:{_num1=_num1+1};
			};
		sleep 0.125;
		};
		{
			_severity = "No";
			_part = _x select 0;
			_num1 = 0;
			_num1 = _num1 + ((_x select 1) select 1);
			_num1 = _num1 + ((_x select 2) select 1);
			_num1 = _num1 + ((_x select 3) select 1);
			if (_num1==0) then
			{	_severity = "No";
			};
			if (_num1>0) then
			{	_severity = "Light";
			};
			if (_num1>0.20) then
			{	_severity = "Minor";
			};
			if (_num1>0.30) then
			{	_severity = "Moderate";
			};
			if (_num1>0.50) then
			{	_severity = "Major";
			};
			if (_num1>0.65) then
			{	_severity = "Severe";
			};
			if (_num>0.80) then
			{	_severity = "Critical";
			};
			if (_part=="") then
			{	_part = "misc";
			};
				ctrlSetText 
				[
					1004,
					format
					[
						"%1 damage to the %2.",
						_severity,
						_part
					]
				];
			sleep 2.5;
		} foreach _list;
		ctrlSetText
		[
			1004,
			"Inspection Complete."
		];
		_caller setvariable ["loop_anim","false"];
	};
	
yink_fnc_diag_treat =//_heal = [_caller,_item] spawn yink_fnc_diag_treat;
	{
		_caller = _this select 0;
		_item	= _this select 1;
		_part	= _caller getvariable "currentPart";
		_array	= _caller getvariable "diagVars";
		_target = _array select 0;
		_part2	= _array select 3;
		if (_part2!=_part) exitwith
		{
			ctrlSetText 
				[
					1004,
					format
					[	"Diagnose the %1 First!",
						_part
					]
				];
		};
		_list1 = [ ];
		_anim_caller = "";
		switch (_part) do
		{
			case "head"	:{_list1 = yink_head; _anim_caller = "AinvPknlMstpSnonWnonDnon_medic0"};
			case "body"	:{_list1 = yink_body; _anim_caller = "AinvPknlMstpSnonWnonDnon_medic4"};
			case "legs"	:{_list1 = yink_legs; _anim_caller = "AinvPknlMstpSnonWnonDr_medic2"};
			case "hands":{_list1 = yink_hands; _anim_caller = "AinvPknlMstpSnonWnonDnon_medic2"};
			case "misc"	:{_list1 = yink_misc2; _anim_caller = "AinvPknlMstpSnonWnonDnon_medic3"};
		};
		if (!(_item in _list1)) then
		{
			ctrlSetText 
				[
					1004,
					format
					[	"Dont use a %1 here!",
						_item
					]
				];
		};
		_timer1 = 0;
		switch (_item) do
		{
			case "bandage":{_timer = 50};
			case "adrenalin":{_timer = 35};
			case "morphine":{_timer = 35};
			case "splint":{_timer = 50};
			case "First Aid":{_timer = 65};
		};
		
		if (_item in _list1) then
		{	
		
			if ((_item=="morphine")||(_item=="adrenalin")) then
			{	_part = "inject";
			};
			_caller setvariable ["loop_anim","true"];
			_script = [_caller,_part] spawn yink_fnc_anim;
			if (_item=="morphine") then
			{	_part = "body";
			};
			if (_item=="adrenalin") then
			{	_part = "body";
			};
			_ran1 = _timer + (round(random 15));
			_string1 = ["",".","..","...","....",".....","......"];
			_num1 = 0;
			_cond = "up";
			for [{_i=0},{_i<=48},{_i=_i+1}] do
			{	_string2 = _string1 select _num1;
				ctrlSetText 
				[
					1004,
					"Applying " + _item + _string2
				];
				if (_num1==6) then 
				{	_cond = "down";
				};
				if (_num1==0) then 
				{	_cond = "up";
				};
				switch (_cond) do
				{	case "down"	:{_num1=_num1-1};
					case "up"	:{_num1=_num1+1};
				};
			sleep 0.125;
			};
			_caller setvariable ["loop_anim","false"];
			_heal = [_target,_item,_part] call yink_fnc_heal;
			ctrlSetText 
			[
				1004,
				_item + " Applied!"
			];
			
		};
		_caller setvariable ["loop_anim","false"];

	};
		
			
			
			
	
		