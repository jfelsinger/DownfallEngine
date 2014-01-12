//===========================
// gamestate.h
//
// The game state handles the input and processing of the `actual`
// game. The world, the monsters, the player actions, and everything
// below it where gameplay in the world is involved.
//
// We're going to need a way to load and restore this later
//
#ifndef GAMESTATE_H
#define GAMESTATE_H

//===========================
// Forward declarations
namespace wb {
    class World;
}
namespace rm {
    class TextureManager;
}
namespace gs {
    class Camera;
}

//===========================
// Included dependencies
#include <vector>
#include "state.h"
#include "../worldBuilding/layergroup.h"

namespace gs
{
    class GameState : public State
    {
        private:
            Camera* camera;
            wb::World* world;
            rm::TextureManager* textureManager;
            std::vector<wb::LayerGroup> layerGroups;

        public:
            GameState();
            ~GameState();

            void Init();
            void Draw(sf::RenderWindow* renderWindow);
            void LoadLayerGroups();
            void SetTextureManager(rm::TextureManager* tm);
    };
}

#endif
