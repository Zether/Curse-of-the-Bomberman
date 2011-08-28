/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef BOMB_H
#define BOMB_H

#include <ctime>
#include "pdc34dllw\curses.h"
#include "pdc34dllw\panel.h"
#include "Item.h"

#include "ItemManager.h"

extern ItemManager * pItemManager;

class Bomb : public Item
{
private:
	int nX;
	int nY;
	int nRadius;
	int nCreateTime;
	double dBombExpire;
	double dFlameExpire;
	double dSmokeExpire;
	bool bActive;

public:
	Bomb() { };

	Bomb(int x, int y, int radius = 5, double bombExpire = 10.0, double flameExpire = 5.0, double smokeExpire = 0.3)
	{
		nX = x;
		nY = y;
		nRadius = radius;
		dBombExpire = bombExpire;
		dFlameExpire = flameExpire;
		dSmokeExpire = smokeExpire;

		nCreateTime = (int)clock();
		bActive = true;
	};

	void vUpdate()
	{ 
		if(!bActive)
		{
			pItemManager->vRemoveItem(this);
		}
	};

	void vDraw()
	{
		char* szBombChar = "o";
		if(bActive)
		{
			if ((clock() / CLOCKS_PER_SEC)  % 2 == 0) szBombChar = "O";
			mvprintw(this->nY, this->nX, szBombChar);
		}
		
		int nBombDuration = (clock() - this->nCreateTime) / CLOCKS_PER_SEC;
		
		if(nBombDuration > dBombExpire + dFlameExpire + dSmokeExpire)
		{
			this->bActive = false;
		}
		else if (nBombDuration > dBombExpire + dFlameExpire)
		{
			for (int j = 0; j <= 2 * this->nRadius; j++)
			{
				mvprintw(this->nY, this->nX - j + this->nRadius, ",");
				mvprintw(this->nY - j + this->nRadius,this->nX, ",");
			}
		}
		else if (nBombDuration > dBombExpire)
		{
			for (int j = 0; j <= 2 * this->nRadius; j++)
			{
				mvprintw(this->nY, this->nX - j + this->nRadius, "*");
				mvprintw(this->nY - j + this->nRadius,this->nX, "*");
			}
		}
	};
	void vLoadContent() { };
	void vUnloadContent() { };
};

#endif