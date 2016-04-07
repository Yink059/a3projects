
//Group manager
execVM "YGM\initYGM.sqf";
//medical
execVM "MedYink\functions.sqf";
execVM "MedYink\diag_functions.sqf";
execVM "MedYink\variables.sqf";
hint "all functions loaded";

{
	_x setvariable ["damageHist", [ ]];
	_x addEventHandler
		["handleDamage",
			{	_unit 	= _this select 0;
				_part 	= _this select 1;
				_dam	= _this select 2;
				_source	= _this select 4;
				_list 	= (_unit getvariable "damageHist") + [[_part,_dam,_source,diag_tickTime]];
				
				_unit setvariable ["damageHist", _list];
			}	
		];
	_bleedout = [_x] spawn yink_fnc_bleed_out;
} foreach allUnits;

