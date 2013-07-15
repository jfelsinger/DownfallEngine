//===========================
// world.h
//
// Encapsulates the entire game world,
// I am thinking that their would only be one per game session.
// It holds all of the places that something might happen in the game (maps)
// as well as of the somethings that might be in the game (entities) [maybe]
//
#ifndef WORLD_H
#define WORLD_H

//===========================
// Forwarded dependencies
namespace wb {
    class Map;
}

//===========================
// Included dependencies
#include <vector>

namespace wb
{
    class World
    {
        private:
            std::vector<Map*> maps;
            // std::vector<Entities> // Probably a good place for them, but might need to go somewhere's else (IDK)

        public:
            World();
            ~World();

            Map* GetMap(const int index);
            void AddMap(Map* map);
    };
}

#endif
