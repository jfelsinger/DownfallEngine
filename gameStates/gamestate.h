//===========================
// gamestate.h
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
