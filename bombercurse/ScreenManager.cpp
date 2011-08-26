/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#include <vector>
#include "ScreenManager.h"
#include "Screen.h"

using namespace std;

ScreenManager::ScreenManager()
{
	fInitialized = false;
}

void ScreenManager::vInitialize()
{		
	fInitialized = true;
}

void ScreenManager::vLoadContent()
{
	for(unsigned int i=0;i<screens.size();i++)
	{
		screens[i]->vLoadContent();
	}
}

void ScreenManager::vUnloadContent()
{
	for(unsigned int i=0;i<screens.size();i++)
	{
		screens[i]->vUnloadContent();
	}
}

void ScreenManager::vUpdate()
{
	for(unsigned int i=0;i<screens.size();i++)
	{
		screens[i]->vUpdate();
	}
}

void ScreenManager::vDraw()
{
	for(unsigned int i=0;i<screens.size();i++)
	{
		if(screens[i]->bIsActive() == true)
		{
			screens[i]->vDraw();
		}
	}
}

void ScreenManager::vAddScreen(Screen * screen)
{
	screens.push_back(screen);
}

void ScreenManager::vRemoveScreen(Screen * screen)
{
	screen->vUnloadContent();
}