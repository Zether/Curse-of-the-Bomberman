/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
	Item() { };
	virtual void vUpdate()=0;
	virtual void vDraw()=0;
	virtual void vLoadContent()=0;
	virtual void vUnloadContent()=0;
};

#endif