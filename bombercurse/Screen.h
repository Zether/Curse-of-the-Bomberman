/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef SCREEN_H
#define SCREEN_H

enum ScreenStatus
{
	Active,
	Inactive
};

class Screen
{
protected:
	ScreenStatus eStatus;
public:
	Screen() { };
	virtual void vUpdate()=0;
	virtual void vDraw()=0;
	virtual void vLoadContent()=0;
	virtual void vUnloadContent()=0;

	ScreenStatus eGetStatus()
	{
		return eStatus;
	}

	bool bIsActive()
	{
		return (eStatus == ScreenStatus::Active);
	}

};

#endif