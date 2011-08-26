/*
Curse of the Bomberman by Taavi Võsumaa and Tanel Võsumaa is licensed 
under a Creative Commons Attribution-ShareAlike 3.0 Unported License.
http://creativecommons.org/licenses/by-sa/3.0/

This notice must be kept intact.
*/

#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <string>
#include "Dependencies\TmxParser\Tmx.h"
#include "Tile.h"

using namespace std;

class MapManager
{
public:
	Tmx::Map * pMap;
	bool bMapLoaded;
	int nMapHeight;
	int nMapWidth;

	vector<Tile> vMap;
	MapManager()
	{ 
		bMapLoaded = false;
		nMapHeight = 0;
		nMapWidth = 0;
	};

	~MapManager()
	{
		if(pMap != NULL)
		{
			vUnloadMap();
		}
	};

	bool bLoadMap(string strMap)
	{
		Tile tTile = { 0 };

		pMap = new Tmx::Map();
		pMap->ParseFile(strMap);
		//pMap->GetErrorCode();
		//pMap->GetErrorText().c_str();

		if (pMap->HasError()) {
			bMapLoaded = false;
			return false;
		}			

		const Tmx::Layer *layer = pMap->GetLayer(0);
		
		nMapHeight = layer->GetHeight();
		nMapWidth = layer->GetWidth();

		vMap.resize(nMapHeight*nMapWidth+nMapWidth);

		for (int y = 0; y < layer->GetHeight(); ++y) {
			for (int x = 0; x < layer->GetWidth(); ++x) {
				vGetTile(layer->GetTileGid(x, y), &tTile);
				vMap.at(x + y*nMapWidth) = tTile;
			}
		}	

		bMapLoaded = true;
		return true;
	};

	void vUnloadMap()
	{
		if(pMap != NULL)
		{
			delete pMap;
		}

		bMapLoaded = false;
	};

	Tmx::Map* pGetMap()
	{
		return pMap;
	};

	void vDraw()
	{		
		string strMap = "";

		for (int y = 0; y < nMapHeight; ++y) {
			for (int x = 0; x < nMapWidth; ++x) {
				strMap.push_back(vMap.at(x + y *nMapWidth).cSymbol);
			}
			mvprintw(y, 0, "%s", strMap.c_str());
			strMap = "";
		}		

		
	};

	void vGetTile(int nTile, Tile * ptTile)
	{
		const Tmx::Tileset *tileset = pMap->FindTileset(nTile);
		const Tmx::Tile *tile = tileset->GetTile(nTile-1);		

		// Print the properties of a tile.
		std::map< std::string, std::string > list = tile->GetProperties().GetList();
		std::map< std::string, std::string >::iterator iter;
		for (iter = list.begin(); iter != list.end(); ++iter) {
			if(iter->first == "symbol")
			{
				if((iter->second).length() == 0)
				{
					ptTile->cSymbol = (char)32;
				}
				else
				{
					ptTile->cSymbol = ((iter->second).at(0));
				}
			}
			else if(iter->first == "walkable")
			{
				if((iter->second).length() == 0)
				{
					ptTile->bWalkable = false;
				}
				else
				{
					if(iter->second == "0")
					{
						ptTile->bWalkable = false;
					}
					else
					{
						ptTile->bWalkable = true;
					}
				}
			}
		}
	};


};

#endif