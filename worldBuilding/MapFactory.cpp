#include "tile.h"
#include "map.h"
#include "mapfactory.h"

namespace wb
{
    MapFactory::MapFactory()
    {
    }

    MapFactory::~MapFactory()
    {
    }

    Map* MapFactory::TileMap(std::vector<wb::LayerGroup>* layerGroups)
    {
        // These numbers are based on the image that I am using for testing
        // They sort of add a bit of coupling that will fixed later,
        // In other words, I am expecting a 16,16 tileset

        unsigned int mapWidth = 80;
        unsigned int mapHeight = 40;
        unsigned int tCount = 0;

        wb::Map* map = new wb::Map(mapWidth, mapHeight);

        for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                wb::Tile* tile = new wb::Tile();
                tile->SetLayerGroup(&layerGroups->at(tCount));

                map->AddTile(i, j, tile);

                // Use one of the 256 layer groups that are available
                if (tCount < 255)
                    ++tCount;
                else
                    tCount = 0;
            }
        }

        return map;
    }
}
