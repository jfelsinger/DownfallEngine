//===========================
// mapfactory.h
//
// Handles creation of maps,
// loading of maps from files and generation of new maps
// (Might need to extend something off for the really complex 
// map generation that is planned on for later down the line)
//
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
