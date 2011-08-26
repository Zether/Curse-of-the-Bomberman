/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <vector>
#include "Screen.h"

using namespace std;

class ScreenManager
{
private:
	bool fInitialized;
	vector<Screen*> screens;
public:
	ScreenManager();

	void vInitialize();

	void vLoadContent();

	void vUnloadContent();

	void vUpdate();

	void vDraw();

	void vAddScreen(Screen * screen);

	void vRemoveScreen(Screen * screen);

	
};


#endif