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
#include "CollisionManager.h"

extern ItemManager * pItemManager;
extern CollisionManager * pCollisionManager;

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
	bool bSmoke;
	bool bFire;
	int nDamage;

public:
	Bomb() { };

	Bomb(int x, int y, int radius = 5, double bombExpire = 10.0, double flameExpire = 5.0, double smokeExpire = 0.3, int damage = 1)
	{
		nX = x;
		nY = y;
		nRadius = radius;
		dBombExpire = bombExpire;
		dFlameExpire = flameExpire;
		dSmokeExpire = smokeExpire;

		nCreateTime = (int)clock();
		bActive = true;

		nDamage = damage;
		bSmoke = false;
		bFire = false;
	};

	void vUpdate()
	{ 
		if(!bActive)
		{
			pItemManager->vRemoveItem(this);
		}
		else
		{
			if(bFire && !bSmoke)
			{
				bool bXWallReached = false;
				bool bYWallReached = false;

				//Look for victims
				for(int j = 0; j <= this->nRadius; j++)
				{
					if(!bXWallReached && pCollisionManager->bIsEmpty(this->nX - j, this->nY))
					{
						pCollisionManager->vDealDamage(this->nX -j, this->nY, nDamage);
					}
					else
					{
						bXWallReached = true;
					}
					if(!bYWallReached && pCollisionManager->bIsEmpty(this->nX, this->nY - j))
					{
						pCollisionManager->vDealDamage(this->nX, this->nY -j, nDamage);
					}
					else
					{
						bYWallReached = true;
					}
				}

				bXWallReached = false;
				bYWallReached = false;
				for(int j = 0; j <= this->nRadius; j++)
				{
					if(!bXWallReached && pCollisionManager->bIsEmpty(this->nX + j, this->nY))
					{
						pCollisionManager->vDealDamage(this->nX + j, this->nY, nDamage);
					}
					else
					{
						bXWallReached = true;
					}
					if(!bYWallReached && pCollisionManager->bIsEmpty(this->nX, this->nY + j))
					{
						pCollisionManager->vDealDamage(this->nX, this->nY + j, nDamage);
					}
					else
					{
						bYWallReached = true;
					}
				}
			}
		}
	};

	void vDraw()
	{
		char* szBombChar = "o";
		char* szFlameSmokeChar = "*";
		bool bXWallReached = false;
		bool bYWallReached = false;
		
		int nBombDuration = (clock() - this->nCreateTime) / CLOCKS_PER_SEC;
		
		if(nBombDuration > dBombExpire + dFlameExpire + dSmokeExpire)
		{
			this->bActive = false;
		}
		else if (nBombDuration > dBombExpire + dFlameExpire)
		{
			szFlameSmokeChar = ",";
			bSmoke = true;
		}
		else if (nBombDuration > dBombExpire)
		{
			szFlameSmokeChar = "*";
			bFire = true;
		}

		if(bActive)
		{
			if ((clock() / CLOCKS_PER_SEC)  % 2 == 0) szBombChar = "O";
			mvprintw(this->nY, this->nX, szBombChar);

			bXWallReached = false;
			bYWallReached = false;
			
			if(bFire || bSmoke)
			{
			//Draw negative side of bomb
				for(int j = 0; j <= this->nRadius; j++)
				{
					if(!bXWallReached && pCollisionManager->bIsEmpty(this->nX - j, this->nY))
					{
						mvprintw(this->nY, this->nX - j, szFlameSmokeChar);
					}
					else
					{
						bXWallReached = true;
					}
					if(!bYWallReached && pCollisionManager->bIsEmpty(this->nX, this->nY - j))
					{
						mvprintw(this->nY - j, this->nX, szFlameSmokeChar);
					}
					else
					{
						bYWallReached = true;
					}
				}

				bXWallReached = false;
				bYWallReached = false;
				//Draw positive side of bomb
				for(int j = 0; j <= this->nRadius; j++)
				{
					if(!bXWallReached && pCollisionManager->bIsEmpty(this->nX + j, this->nY))
					{
						mvprintw(this->nY, this->nX + j, szFlameSmokeChar);
					}
					else
					{
						bXWallReached = true;
					}
					if(!bYWallReached && pCollisionManager->bIsEmpty(this->nX, this->nY + j))
					{
						mvprintw(this->nY + j, this->nX, szFlameSmokeChar);
					}
					else
					{
						bYWallReached = true;
					}
				}
			}
		}

	};
	void vLoadContent() { };
	void vUnloadContent() { };
};

#endif