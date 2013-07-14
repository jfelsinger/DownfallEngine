#include "gamestate.h"
#include "../resourceManagers/texturemanager.h"
#include "../worldBuilding/layergroup.h"
#include "../worldBuilding/tile.h"
#include "../worldBuilding/map.h"
#include "../worldBuilding/world.h"
#include "../worldBuilding/mapfactory.h"

#include <iostream>

namespace gs
{
    GameState::GameState()
    {
    }

    GameState::~GameState()
    {
    }

    void GameState::Draw(sf::RenderWindow* renderWindow)
    {
        wb::Map* map = world->GetMap(0);

        int w = map->GetWidth();
        int h = map->GetHeight();

        renderWindow->clear();

        // Iterate through all of the tiles in the map
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                // Draw tiles to the screen
                map->GetTile(i, j)
                   ->GetLayerGroup()
                   ->Draw(i*16, j*16, renderWindow); // 16x16 is the size of the tile, so each one should be rendered at an offset of 16
            }
        }
    }

    void GameState::Init()
    {
        LoadLayerGroups();

        // Generate a map
        wb::MapFactory mapFactory;
        wb::Map* map = mapFactory.TileMap(&layerGroups);

        // Instantiate a new world and add the map to it
        world = new wb::World();
        world->AddMap(map);
    }

    void GameState::SetTextureManager(rm::TextureManager* tm)
    {
        // Should be moved to constructor
        textureManager = tm;
    }

    void GameState::LoadLayerGroups()
    {
        for (int i = 0; i < 256; i++)
        {
            sf::Sprite* sprite = new sf::Sprite();

            // we are printing out all of the sprites in a sprite sheet
            sf::Texture* texture = textureManager->GetTexture(i);

            sprite->setTexture(*texture);

            // Only one sprite on the layer groups for now
            wb::LayerGroup* lg = new wb::LayerGroup();
            lg->AddFloorSprite(sprite);

            layerGroups.push_back(*lg);
        }
    }
}
