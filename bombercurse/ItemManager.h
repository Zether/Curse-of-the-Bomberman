/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <vector>
#include "Item.h"

using namespace std;

class ItemManager
{
private:
	bool fInitialized;
	vector<Item*> items;
public:
	ItemManager();
	~ItemManager();

	void vInitialize();

	void vLoadContent();

	void vUnloadContent();

	void vUpdate();

	void vDraw();

	void vAddItem(Item * item);

	void vRemoveItem(Item * item);

	
};


#endif