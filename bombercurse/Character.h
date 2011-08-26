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

extern ItemManager * pItemManager;
extern ScreenManager* pScreenManager;
extern CreatureManager* pCreatureManager;

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
		nX += nXShift;
		nY += nYShift;
	}

	void vMoveTo(int nx, int ny)
	{
		nX = nx;
		nY = ny;
	}
};

#endif