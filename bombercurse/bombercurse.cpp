/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

// bombercurse.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#pragma comment(lib, "pdc34dllw\\pdcurses.lib")
#include "pdc34dllw\curses.h"
#include "pdc34dllw\panel.h"

#include <ctime>
#include <vector>
#include "Bomb.h"
#include "ItemManager.h"
#include "ScreenManager.h"
#include "GameplayScreen.h"
#include "IntroScreen.h"
#include "GameStates.h"
#include "CreatureManager.h"
#include "Creature.h"
#include "Character.h"
#include "MapManager.h"
#include "CollisionManager.h"

using namespace std;

double m_dTickInterval = 0.037f; // sec
double m_dLastTick = clock();
double m_dBombExpire = 2.0;
double m_dFlameExpire = 1.0;

struct MapTile
{
	int ntypeID;
	int nX;
	int nY;
	int nWalkable;
};

ItemManager* pItemManager = new ItemManager();
CreatureManager* pCreatureManager = new CreatureManager();
ScreenManager* pScreenManager = new ScreenManager();
MapManager* pMapManager = new MapManager();
CollisionManager* pCollisionManager = new CollisionManager();

GameStates eGameState = INTRO_GAME;

int _tmain(int argc, _TCHAR* argv[])
{
	int nInkey = 0;
	
	//Set up terminal
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	nodelay(stdscr, TRUE);

	pMapManager->bLoadMap("Maps/Map1.tmx");

	Tmx::Map * pMap = pMapManager->pGetMap();
	
	GameplayScreen* pGameScreen; 
	IntroScreen* pIntroScreen;

	pScreenManager->vAddScreen(pIntroScreen = new IntroScreen());
	pScreenManager->vAddScreen(pGameScreen = new GameplayScreen());
	pGameScreen->vSetStatus(0);

	pItemManager->vAddItem(new Bomb(5,1));
	pItemManager->vAddItem(new Bomb(5, 16));
	pItemManager->vAddItem(new Bomb(14, 11));
	pItemManager->vAddItem(new Bomb(48, 4));
	
	pCreatureManager->vAddCreature(new Character());

	for(int j=0;j<10000;j++)
		continue;
	
/*
		for (int i = 0; i < pMap->GetNumTilesets(); ++i) {
		printf("                                    \n");
		printf"====================================\n");
		printf("Tileset : %02d\n", i);
		printf("====================================\n");

		// Get a tileset.
		const Tmx::Tileset *tileset = pMap->GetTileset(i);

		// Print tileset information.
		printf("Name: %s\n", tileset->GetName().c_str());
		printf("Margin: %d\n", tileset->GetMargin());
		printf("Spacing: %d\n", tileset->GetSpacing());
		printf("Image Width: %d\n", tileset->GetImage()->GetWidth());
		printf("Image Height: %d\n", tileset->GetImage()->GetHeight());
		printf("Image Source: %s\n", tileset->GetImage()->GetSource().c_str());
		printf("Transparent Color (hex): %s\n", tileset->GetImage()->GetTransparentColor().c_str());

		if (tileset->GetTiles().size() > 0) {
			// Get a tile from the tileset.
			const Tmx::Tile *tile = tileset->GetTile(0);

			// Print the properties of a tile.
			std::map< std::string, std::string > list = tile->GetProperties().GetList();
			std::map< std::string, std::string >::iterator iter;
			for (iter = list.begin(); iter != list.end(); ++iter) {
				printf("%s = %s\n", iter->first.c_str(), iter->second.c_str());
			}
		}
	}

	// Iterate through the layers.
	for (int i = 0; i < pMap->GetNumLayers(); ++i) {
		printf("                                    \n");
		printf("====================================\n");
		printf("Layer : %02d/%s \n", i, pMap->GetLayer(i)->GetName().c_str());
		printf("====================================\n");
	
		// Get a layer.
		const Tmx::Layer *layer = pMap->GetLayer(i);

		for (int x = 0; x < layer->GetWidth(); ++x) {
			for (int y = 0; y < layer->GetHeight(); ++y) {
				// Get a tile global id.
				printf("%03d", layer->GetTileGid(y, x));

				// Find a tileset for that id.
				const Tmx::Tileset *tileset = pMap->FindTileset(layer->GetTileGid(y,x));
				if (layer->IsTileFlippedHorizontally(y, x)){
					printf("h");
				}else{
					printf(" ");
				}
				if (layer->IsTileFlippedVertically(y, x)){
					printf("v  ");
				}else{
					printf("   ");
				}
			}

			printf("\n");
		}
	}

	printf("\n\n");

	// Iterate through all of the object groups.
	for (int i = 0; i < pMap->GetNumObjectGroups(); ++i) {
		printf("                                    \n");
		printf("====================================\n");
		printf("Object group : %02d\n", i);
		printf("====================================\n");

		// Get an object group.
		const Tmx::ObjectGroup *objectGroup = pMap->GetObjectGroup(i);

		// Iterate through all objects in the object group.
		for (int j = 0; j < objectGroup->GetNumObjects(); ++j) {
			// Get an object.
			const Tmx::Object *object = objectGroup->GetObject(j);

			// Print information about the object.
			printf("Object Name: %s\n", object->GetName().c_str());
			printf("Object Position: (%03d, %03d)\n", object->GetX(), object->GetY());
			printf("Object Size: (%03d, %03d)\n", object->GetWidth(), object->GetHeight());
		}
	}
	*/
	while(1)
	{
		if(INTRO_GAME == eGameState && NULL != pIntroScreen && pIntroScreen->nGetStatusBit(REMOVE_SCREEN) !=0)
		{
			eGameState = PLAY_GAME;
			pGameScreen->vSetStatusBit(UPDATE_SCREEN);
			pGameScreen->vSetStatusBit(DRAW_SCREEN);
		}

		pScreenManager->vUpdate();
		if ((clock() - m_dLastTick) / CLOCKS_PER_SEC > m_dTickInterval)
		{
			m_dLastTick = clock();	
			clear();
			pScreenManager->vDraw();
			refresh();
		}

		/*
		for(unsigned int i=0;i<pCreatures.size();i++)
		{
			if(pCreatures[i]->eGetType() == TYPE_Character)
		{
				Character * pchar = static_cast<Character*>(pCreatures[i]);

				mvprintw(0,0, "%d  - life", pchar->nLifeTotal);	
			}
		}
		*/
		if(EXIT_GAME == eGameState)
		{
			break;
		}
	}
 
	delete pItemManager;
	delete pScreenManager;
	delete pCreatureManager;
	delete pMapManager;
	delete pCollisionManager;

	endwin();
	return 0;
}