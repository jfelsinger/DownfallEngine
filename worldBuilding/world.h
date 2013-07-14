//===========================
// world.h
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
            // std::vector<Entities> // Probably a good place for them

        public:
            World();
            ~World();

            Map* GetMap(const int index);
            void AddMap(Map* map);
    };
}

#endif
