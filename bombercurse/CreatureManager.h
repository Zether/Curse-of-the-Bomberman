/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef CREATUREMANAGER_H
#define CREATUREMANAGER_H

#include <vector>
#include "Creature.h"

using namespace std;

class CreatureManager
{
private:
	bool fInitialized;	
public:
	vector<Creature*> creatures;
	CreatureManager();
	~CreatureManager();

	void vInitialize();

	void vUpdate();

	void vDraw();

	void vLoadContent();

	void vUnloadContent();

	void vAddCreature(Creature * creature);

	void vRemoveCreature(Creature * creature);
	
};


#endif