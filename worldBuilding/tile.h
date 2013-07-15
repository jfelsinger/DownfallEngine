//===========================
// tile.h
//
// A distinct building block that makes up a map
// Each tile on a map is distinctly its own, but references
// a shared list of layer groups that dictate the tile's look
//
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
            bool accessible;    // Whether or not the tile can be accessed(walked on),
                                // It'll be extended to a class/bitmap later so that access can be more granular
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
