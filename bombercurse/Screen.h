/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef SCREEN_H
#define SCREEN_H

#include "BitMacros.h"

enum ScreenStatusBits
{
	UPDATE_SCREEN = 0,
	DRAW_SCREEN = 1,
	REMOVE_SCREEN = 2,

};

class Screen
{
protected:
	int nStatus;
public:
	Screen() { nStatus = 0; };
	virtual void vUpdate()=0;
	virtual void vDraw()=0;
	virtual void vLoadContent()=0;
	virtual void vUnloadContent()=0;

	int nGetStatus()
	{
		return nStatus;
	}

	int nIsActive()
	{
		return (CHCKBIT(nStatus,DRAW_SCREEN));
	}

	void vSetStatus(int status)
	{
		nStatus = status;
	}	

	void vSetStatusBit(int bit)
	{
		SETBIT(nStatus, bit);
	}

	void vClearStatusBit(int bit)
	{
		CLRBIT(nStatus, bit);
	}

	int nGetStatusBit(int bit)
	{
		return CHCKBIT(nStatus, bit);
	}
};

#endif