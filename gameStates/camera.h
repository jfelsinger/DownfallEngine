#ifndef CAMERA_H
#define CAMERA_H

//===========================
// Forward declarations
namespace wb {
    class Map;
}

//===========================
// Included dependencies
#include <SFML/Graphics.hpp>
#include "../worldBuilding/tile.h"

namespace gs
{
    class Camera
    {
        private:
            // Absolute position of camera,
            // px from origin
            sf::Vector2f position;
            sf::Vector2f targetPosition;

            // Dimensions of viewable area
            int width;
            int height;

            // Map that camera is currently targetting
            wb::Map* map;

            // 0.0 - 1.0, camera speed
            float speed;

        public:
            Camera(const int w, const int h, float speed);
            ~Camera();

            wb::Map* GetMap();
            void SetMap(wb::Map* map);

            int GetWidth();
            int GetHeight();

            // Moves camera immediately
            void Move(const int x, const int y);
            void MoveCenter(int x, int y);

            // Animated camera motion
            void PanTo(const int x, const int y);
            void PanToCenter(int x, int y);

            // Updates camera position
            void Update();

            // Don't like any of the below functions,
            // consider refactoring them

            sf::IntRect GetTileBounds(const int tileSize);

            sf::Vector2i GetPosition() {
                return sf::Vector2i((int)position.x, (int)position.y);
            }

            sf::Vector2i GetTileOffset(const int tileSize) {
                return sf::Vector2i(
                        (int)(position.x) % tileSize,
                        (int)(position.y) % tileSize
                );
            }
    };
}

#endif
