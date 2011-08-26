/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#include <vector>
#include "ItemManager.h"
#include "Item.h"

using namespace std;

ItemManager::ItemManager()
{
	fInitialized = false;
}

ItemManager::~ItemManager()
{
	for(unsigned int i=0;i<items.size();i++)
	{
		delete items[i];
	}
}
void ItemManager::vInitialize()
{
		
	fInitialized = true;
}

void ItemManager::vLoadContent()
{
	for(unsigned int i=0;i<items.size();i++)
	{
		items[i]->vLoadContent();
	}
}

void ItemManager::vUnloadContent()
{
	for(unsigned int i=0;i<items.size();i++)
	{
		items[i]->vUnloadContent();
	}
}

void ItemManager::vUpdate()
{
	for(unsigned int i=0;i<items.size();i++)
	{
		items[i]->vUpdate();
	}
}

void ItemManager::vDraw()
{
	for(unsigned int i=0;i<items.size();i++)
	{
		items[i]->vDraw();
	}
}

void ItemManager::vAddItem(Item * item)
{
	items.push_back(item);
}

void ItemManager::vRemoveItem(Item * item)
{
	item->vUnloadContent();
}