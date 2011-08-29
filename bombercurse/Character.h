/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "pdc34dllw\curses.h"
#include "pdc34dllw\panel.h"
#include "Creature.h"
#include "CreatureTypes.h"
#include "CollisionManager.h"

extern ItemManager * pItemManager;
extern ScreenManager* pScreenManager;
extern CreatureManager* pCreatureManager;
extern CollisionManager* pCollisionManager;

extern GameStates eGameState;

class Character : public Creature
{
public:
	int nLifeTotal;
	Character()
	{
		nLifeTotal = 20;
		nX = 0;
		nY = 0;
	};

	void vUpdate() 
	{ 
		int nInkey = getch();
		MEVENT event;

		if (nInkey == KEY_F(10)) { eGameState = EXIT_GAME; }
		if (nInkey == KEY_RIGHT) { vMove(1, 0);}
		if (nInkey == KEY_LEFT) { vMove(-1, 0);}
		if (nInkey == KEY_UP) { vMove(0, -1);}
		if (nInkey == KEY_DOWN) { vMove(0, 1);}
		if (nInkey == ' ') { pItemManager->vAddItem(new Bomb(nX, nY)); }
		if (nInkey == KEY_MOUSE)
		{
			if (nc_getmouse(&event) == OK)
			{
				if (event.bstate & BUTTON4_PRESSED) { vMove(0, -1); }
				if (event.bstate & BUTTON5_PRESSED) { vMove(0, 1); }
				if (event.bstate & BUTTON1_CLICKED) { vMoveTo(event.x, event.y); }
			}
		}
	};
	
	void vDraw() 
	{ 
		mvprintw(nY, nX, "@");
	};

	void vLoadContent() { };

	void vUnloadContent() { };

	CreatureType eGetType() { return TYPE_Character; };

	void vMove(int nXShift, int nYShift)
	{
		if(pCollisionManager->bIsEmpty(nX + nXShift, nY + nYShift) && !pCollisionManager->bIsCreature(nX + nXShift, nY + nYShift))
		{
			nX += nXShift;
			nY += nYShift;
		}
	}

	void vMoveTo(int nx, int ny)
	{
		if(pCollisionManager->bIsEmpty(nX, nY) && !pCollisionManager->bIsCreature(nX, nY))
		{
			nX = nx;
			nY = ny;
		}
	}

	void vReceiveDamage(int n)
	{
		//You are dead!
		nX = 0;
		nY = 0;
	}
};

#endif