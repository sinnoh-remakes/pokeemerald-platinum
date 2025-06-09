Route119_MapScripts::
	@ map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	@ map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

@ Route119_OnResume:
@ 	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
@   end

@ Route119_OnTransition:
@ 	end
