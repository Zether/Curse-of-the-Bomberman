/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#include "pdc34dllw\curses.h"
#include "pdc34dllw\panel.h"
#include "ItemManager.h"
#include "ScreenManager.h"
#include "GameStates.h"
#include "GameplayScreen.h"
#include "CreatureManager.h"
#include "MapManager.h"
#include "Bomb.h"

extern ItemManager * pItemManager;
extern ScreenManager* pScreenManager;
extern CreatureManager* pCreatureManager;
extern MapManager* pMapManager;

GameplayScreen::GameplayScreen()
{
	SETBIT(nStatus, DRAW_SCREEN);
	SETBIT(nStatus, UPDATE_SCREEN);
}

void GameplayScreen::vUpdate()
{ 	
	pCreatureManager->vUpdate();
	pItemManager->vUpdate();
};

void GameplayScreen::vDraw()
{ 
	//Draw header
	attron(COLOR_PAIR(2));
	mvprintw(0,0, "Welcome to Curse of the Bomberman\n\r");	
	attron(COLOR_PAIR(1));		

	//Draw map
	pMapManager->vDraw();
	//Draw items
	pItemManager->vDraw();
	//Draw creatures
	pCreatureManager->vDraw();
};

void GameplayScreen::vLoadContent() { };
void GameplayScreen::vUnloadContent() { };