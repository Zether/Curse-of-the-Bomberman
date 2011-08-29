#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "ItemManager.h"
#include "CreatureManager.h"
#include "MapManager.h"

extern ItemManager * pItemManager;
extern CreatureManager* pCreatureManager;
extern MapManager* pMapManager;

class CollisionManager
{
public:
	bool bIsEmpty(int nX, int nY)
	{		
		if(nX < 0 || nY < 0)
		{
			return false;
		}

		return pMapManager->vMap.at(nX + nY*pMapManager->nMapWidth).bWalkable;
	}

	bool bIsCreature(int nX, int nY)
	{		
		if(nX < 0 || nY < 0)
		{
			return false;
		}

		for(unsigned int i=0;i < pCreatureManager->creatures.size();i++)
		{
			if((pCreatureManager->creatures[i]->nX == nX) && (pCreatureManager->creatures[i]->nY == nY))
			{
				return true;
			}
		}

		return false;
	}

	void vDealDamage(int nX, int nY, int nDam)
	{
		if(nX < 0 || nY < 0  || nDam == 0)
		{
			return;
		}

		for(unsigned int i=0;i < pCreatureManager->creatures.size();i++)
		{
			if((pCreatureManager->creatures[i]->nX == nX) && (pCreatureManager->creatures[i]->nY == nY))
			{
				pCreatureManager->creatures[i]->vReceiveDamage(nDam);
			}

			//Add crate destroy code
		}
	}
};

#endif