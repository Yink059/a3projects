execVM "MedYink\functions.sqf";
sleep 1;
_diag = [unit2,_this select 1,_id] spawn yink_fnc_diag;

//[] call BIS_fnc_GUIeditor;

//_diag1 = [(_this select 0),"hands"] spawn yink_fnc_anim;
//[] call BIS_fnc_animViewer;
/*
_target = _this select 0;
_caller = _this select 1;
_id		= _this select 2;


prone check		: 	AinvPknlMstpSnonWnonDr_medic4
prone inject	:	AinvPknlMstpSnonWnonDnon_medic1
prone head		:	AinvPknlMstpSnonWnonDnon_medic0
prone body		:	AinvPknlMstpSnonWnonDnon_medic4
prone legs		: 	AinvPknlMstpSnonWnonDr_medic2
prone hands		:	AinvPknlMstpSnonWnonDnon_medic2
prone misc		:	AinvPknlMstpSnonWnonDnon_medic3

crouch check	:	AinvPknlMstpSnonWnonDr_medicUp4
crouch inject	:	AinvPknlMstpSnonWnonDnon_medicUp1
croucn hands	:	AinvPknlMstpSnonWnonDnon_medicUp2
crouch head		:	AinvPknlMstpSnonWnonDr_medicUp1
crouch body		:	AinvPknlMstpSnonWnonDnon_medicUp3
crouch legs		:	AinvPknlMstpSnonWnonDnon_medicUp3


defib			:	AinvPknlMstpSnonWnonDr_medic5
cpr				:	AinvPknlMstpSnonWnonDr_medic0

AinjPpneMstpSnonWnonDnon
crouch healed	:	AinvPknlMstpSnonWnonDnon_healed_2
prone healed	: 	AinjPpneMstpSnonWnonDnon_injuredHealed







[unit2,"AmovPercMstpSrasWrflDnon_AinvPknlMstpSlayWrflDnon"] call BIS_fnc_ambientAnim;



_diag = [_target,_caller,_id] spawn yink_fnc_diag;


/*































if ((_partHit)==(_x select 0)) then
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


