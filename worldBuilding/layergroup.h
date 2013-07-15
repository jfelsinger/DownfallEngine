//===========================
// layergroup.h
//
#ifndef LAYERGROUP_H
#define LAYERGROUP_H

//===========================
// Forwarded dependencies

//===========================
// include dependencies
#include <vector>
#include <SFML/Graphics.hpp>

namespace wb
{
    class LayerGroup
    {
        private:
            std::vector<sf::Sprite*> floorLayers;   // Tiles that show behind entities, like the player
            std::vector<sf::Sprite*> skyLayers;     // Layers that show above entities, cover the player

        public:
            LayerGroup();
            ~LayerGroup();

            void Draw(int x, int y, sf::RenderWindow* renderWindow);
            void DrawFloor(int x, int y, sf::RenderWindow* renderWindow);
            void DrawSky(int x, int y, sf::RenderWindow* renderWindow);

            void AddFloorSprite(sf::Sprite* sprite);
            void AddSkySprite(sf::Sprite* sprite);

            sf::Sprite* GetFloorSprite(int index);
            sf::Sprite* GetSkySprite(int index);
    };
}

#endif
