/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef CREATURE_H
#define CREATURE_H

#include "CreatureTypes.h"

class Creature
{
public:
	Creature() { };

	virtual void vUpdate()=0;

	virtual void vDraw()=0;

	virtual void vLoadContent()=0;

	virtual void vUnloadContent()=0;

	virtual CreatureType eGetType()=0;

	virtual void vMove(int x, int y)=0;

	virtual void vMoveTo(int x, int y)=0;

	int nX;
	int nY;
};

#endif