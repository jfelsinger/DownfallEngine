//===========================
// map.h
#ifndef MAP_H
#define MAP_H

//===========================
// Forwarded dependencies
namespace wb {
    class Tile;
}

//===========================
// Included dependencies
#include <vector>

namespace wb
{
    class Map
    {
        private:
            std::vector<std::vector<Tile*> > tiles;
            
            // Tile dimensions
            int width;
            int height;

            void SetDimensions(const int w, const int h);

        public:
            Map(const int w, const int h);
            ~Map();

            void AddTile(const int x, const int y, Tile* tile);
            Tile* GetTile(const int x, const int y);

            int GetWidth();
            int GetHeight();
    };
}

#endif
