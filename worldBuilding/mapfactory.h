//===========================
// mapfactory.h
#ifndef MAPFACTORY_H
#define MAPFACTORY_H

//===========================
// Forwarded declarations
namespace wb {
    class Map;
}

//===========================
// Included dependencies
#include <vector>
#include "layergroup.h"

namespace wb
{
    class MapFactory
    {
        // Used for random world/map generation
        public:
            MapFactory();
            ~MapFactory();

            Map* TileMap(std::vector<wb::LayerGroup>* layerGroups);
    };
}

#endif
