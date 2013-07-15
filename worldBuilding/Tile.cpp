#include "tile.h"

namespace wb
{
    Tile::Tile()
    {
    }

    Tile::Tile(LayerGroup* lg)
    {
        layerGroup = lg;
    }

    Tile::~Tile()
    {
    }

    void Tile::SetLayerGroup(LayerGroup* lg)
    {
        layerGroup = lg;
    }

    LayerGroup* Tile::GetLayerGroup()
    {
        return layerGroup;
    }

    void Tile::SetAccessible(const bool access)
    {
        accessible = access;
    }

    bool Tile::IsAccessible()
    {
        return accessible;
    }
}
