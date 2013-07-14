#include "world.h"

namespace wb
{
    World::World()
    {
    }

    World::~World()
    {
    }

    Map* World::GetMap(const int index)
    {
        return maps[index];
    }

    void World::AddMap(Map* map)
    {
        maps.push_back(map);
    }
}
