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

    void Map::SetDimensions(const int w, const int h)
    {
        tiles.resize(w);

        for(int i = 0; i < w; i++)
        {
            tiles.at(i).resize(h, 0);
        }
    }

    void Map::AddTile(const int x, const int y, Tile* tile)
    {
        tiles[x][y] = tile;
    }

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
