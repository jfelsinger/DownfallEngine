//===========================
// tile.h
#ifndef TILE_H
#define TILE_H

//===========================
// Forwarded dependencies
namespace wb {
    class LayerGroup;
}

//===========================
// Included dependencies
#include <vector>


namespace wb
{
    class Tile
    {
        private:
            bool accessible; // A class with defined element and player/monster access later
            LayerGroup* layerGroup;

        public:
            Tile();
            Tile(LayerGroup* lg);
            ~Tile();

            void SetLayerGroup(LayerGroup* lg);
            LayerGroup* GetLayerGroup();

            void SetAccessible(const bool access);
            bool IsAccessible();
    };
}

#endif
