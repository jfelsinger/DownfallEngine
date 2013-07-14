//===========================
// engine.h
#ifndef ENGINE_H
#define ENGINE_H


//===========================
// Forwarded dependencies
namespace gs {
    class GameState;
}

//===========================
// Included dependencies
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include "worldBuilding/world.h"
#include "resourceManagers/imagemanager.h"
#include "resourceManagers/texturemanager.h"

namespace ae
{
    class Engine
    {
        private:
            gs::GameState* state;
            rm::ImageManager imageManager;
            rm::TextureManager textureManager;
            sf::RenderWindow* renderWindow;
            sf::Time updateRate;
            uint32_t maxUpdates;

        public:
            Engine();
            ~Engine();

            void Init(); // Might break-up init into more functions later

            void MainLoop(); // Main game loop

            void ProcessInput();

            void Update(); // Update internal states

            void Cleanup(); // Clean up for after exiting

            void Run();

            void Draw(); // Temp
    };
}

#endif
