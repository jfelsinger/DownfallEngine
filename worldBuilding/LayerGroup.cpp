#include "layergroup.h"
#include <SFML/Graphics.hpp>

namespace wb
{
    LayerGroup::LayerGroup()
    {
    }

    LayerGroup::~LayerGroup()
    {
    }

    void LayerGroup::Draw(int x, int y, sf::RenderWindow* renderWindow)
    {
        DrawFloor(x, y, renderWindow);
        DrawSky(x, y, renderWindow);
    }

    void LayerGroup::DrawFloor(int x, int y, sf::RenderWindow* renderWindow)
    {
        for(sf::Sprite* sprite : floorLayers)
        {
            sprite->setPosition(x, y);
            renderWindow->draw(*sprite);
        }
    }

    void LayerGroup::DrawSky(int x, int y, sf::RenderWindow* renderWindow)
    {
        for(sf::Sprite* sprite : skyLayers)
        {
            sprite->setPosition(x, y);
            renderWindow->draw(*sprite);
        }
    }

    void LayerGroup::AddFloorSprite(sf::Sprite* sprite)
    {
        floorLayers.push_back(sprite);
    }

    void LayerGroup::AddSkySprite(sf::Sprite* sprite)
    {
        skyLayers.push_back(sprite);
    }

    sf::Sprite* LayerGroup::GetFloorSprite(int index)
    {
        return floorLayers[index];
    }

    sf::Sprite* LayerGroup::GetSkySprite(int index)
    {
        return skyLayers[index];
    }
}
