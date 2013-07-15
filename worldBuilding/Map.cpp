#include "map.h"

namespace wb
{
    Map::Map(const int w, const int h)
    {
        SetDimensions(w, h);
        width = w;
        height = h;
    }

    Map::~Map()
    {
    }

    // Resizes the 2d vector map
    void Map::SetDimensions(const int w, const int h)
    {
        tiles.resize(w);

        for(int i = 0; i < w; i++)
        {
            tiles.at(i).resize(h, 0);
        }
    }

    // Add a tile to the map at a given x,y coord
    void Map::AddTile(const int x, const int y, Tile* tile)
    {
        tiles[x][y] = tile;
    }

    // Get a tile at a given x,y coord
    Tile* Map::GetTile(const int x, const int y)
    {
        return tiles[x][y];
    }

    int Map::GetWidth()
    {
        return width;
    }

    int Map::GetHeight()
    {
        return height;
    }
}
