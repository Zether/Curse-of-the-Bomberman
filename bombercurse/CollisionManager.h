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

		for(int i=0;i < pCreatureManager->creatures.size();i++)
		{
			if((pCreatureManager->creatures[i]->nX == nX) && (pCreatureManager->creatures[i]->nY == nY))
			{
				return true;
			}
		}

		return false;
	}
};

#endif