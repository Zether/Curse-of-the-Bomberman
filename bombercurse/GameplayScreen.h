/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "Screen.h"

class GameplayScreen : public Screen
{
public:
	GameplayScreen();
	void vUpdate();
	void vDraw();
	void vLoadContent();
	void vUnloadContent();
};

#endif