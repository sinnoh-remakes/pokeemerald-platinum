Route219_MapScripts::
	@ map_script MAP_SCRIPT_ON_RESUME, Route219_OnResume
	@ map_script MAP_SCRIPT_ON_TRANSITION, Route219_OnTransition
	.byte 0

@ Route219_OnResume:
@ 	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route219_EventScript_TryRemoveKecleon
@   end

@ Route219_OnTransition:
@ 	end
