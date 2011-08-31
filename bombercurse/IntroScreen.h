/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef INTROSCREEN_H
#define INTROSCREEN_H

#include "pdc34dllw\curses.h"
#include "pdc34dllw\panel.h"
#include <string>
#include "Screen.h"

class IntroScreen : public Screen
{
	int nCreateTime;
public:
	IntroScreen()
	{
		SETBIT(nStatus, DRAW_SCREEN);
		SETBIT(nStatus, UPDATE_SCREEN);
		nCreateTime = (int)clock();
	};

	void vUpdate()
	{
		if((int)clock() - nCreateTime > 2 * CLOCKS_PER_SEC)
		{
			CLRBIT(nStatus, DRAW_SCREEN);
			CLRBIT(nStatus, UPDATE_SCREEN);
			SETBIT(nStatus, REMOVE_SCREEN);
		}
	}
	void vDraw()
	{
		mvprintw(1, 0, "                 ,--.                            .  .         ");
		mvprintw(2, 0, "                | `-' . . ,-. ,-. ,-.   ,-. ,\"   |- |-. ,-.   ");
		mvprintw(3, 0, "                |   . | | |   `-. |-'   | | |-   |  | | |-'   ");
		mvprintw(4, 0, "                `--'  `-^ '   `-' `-'   `-' |    `' ' ' `-'   ");
		mvprintw(5, 0, "                                            '                 ");
		mvprintw(6, 0, "                                                              ");
		mvprintw(7, 0, "                 ,-,---.           .                         ");
		mvprintw(8, 0, "                  '|___/,-. ,-,-. |-. ,-. ,-. ,-,-. ,-. ,-. ");
		mvprintw(9, 0, "                  ,|   \ | | | | | | | |-' |   | | | ,-| | | ");
		mvprintw(10, 0, "                 `-^---'`-' ' ' ' ^-' `-' '   ' ' ' `-^ ' ' ");
		mvprintw(11, 0, "                                                Version: -1");

	}
	void vLoadContent() { }
	void vUnloadContent() {}
};

#endif