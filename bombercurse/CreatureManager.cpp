/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#include <vector>
#include "CreatureManager.h"
#include "Creature.h"

using namespace std;

CreatureManager::CreatureManager()
{
	fInitialized = false;
}

CreatureManager::~CreatureManager()
{
	for(unsigned int i=0;i<creatures.size();i++)
	{
		delete creatures[i];
	}
}
void CreatureManager::vInitialize()
{
		
	fInitialized = true;
}

void CreatureManager::vLoadContent()
{
	for(unsigned int i=0;i<creatures.size();i++)
	{
		creatures[i]->vLoadContent();
	}
}

void CreatureManager::vUnloadContent()
{
	for(unsigned int i=0;i<creatures.size();i++)
	{
		creatures[i]->vUnloadContent();
	}
}

void CreatureManager::vUpdate()
{
	for(unsigned int i=0;i<creatures.size();i++)
	{
		creatures[i]->vUpdate();
	}
}

void CreatureManager::vDraw()
{
	for(unsigned int i=0;i<creatures.size();i++)
	{
		creatures[i]->vDraw();
	}
}

void CreatureManager::vAddCreature(Creature * creature)
{
	creatures.push_back(creature);
}

void CreatureManager::vRemoveCreature(Creature * creature)
{
	creature->vUnloadContent();
}