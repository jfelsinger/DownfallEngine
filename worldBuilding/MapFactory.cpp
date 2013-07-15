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

    // Creates a set map of tiles based on a 256 sprite tileset,
    // Eventually to be replaced by a functions to load a map, and 
    // functions to intelligently create them from scratch.
    Map* MapFactory::TileMap(std::vector<wb::LayerGroup>* layerGroups)
    {
        // These numbers are based on the image that I am using for testing
        // They sort of add a bit of coupling that will fixed later,
        // In other words, I am expecting a 16,16 tileset

        unsigned int mapWidth = 80;     // Arbitrary values
        unsigned int mapHeight = 40;    //
        unsigned int tCount = 0;

        wb::Map* map = new wb::Map(mapWidth, mapHeight);

        for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                // Create a tile and give it one of the incrementally chosen Layer groups
                wb::Tile* tile = new wb::Tile();
                tile->SetLayerGroup(&layerGroups->at(tCount));

                // i,j corresponds to an x,y; since it is 
                // explicitly based on map width and height
                map->AddTile(i, j, tile);

                // Use one of the 256 layer groups that are available, incrementally
                if (tCount < 255)
                    ++tCount;
                else
                    tCount = 0;
            }
        }

        return map;
    }
}
