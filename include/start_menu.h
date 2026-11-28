#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

#include "global.h"
#include "config/start_menu.h"

#if START_MENU_USE_ICONS
extern bool8 gShouldStartMenuIconsBePrinted;
bool8 IsAStartMenuIconAtPosition(u8 position);
void SetStartMenuIconSelected(u8 position, bool8 selected);
u8 GetStartMenuIconRowY(u8 position);
#endif

extern bool8 (*gMenuCallback)(void);

void ShowReturnToFieldStartMenu(void);
void Task_ShowStartMenu(u8 taskId);
void ShowStartMenu(void);
void ShowBattlePyramidStartMenu(void);
void SaveGame(void);
void CB2_SetUpSaveAfterLinkBattle(void);
void SaveForBattleTowerLink(void);
void HideStartMenu(void);
void AppendToList(u8 *list, u8 *pos, u8 newEntry);

#endif // GUARD_START_MENU_H
