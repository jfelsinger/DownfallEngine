//===========================
// engine.h
//
// The engine facilitates the running of the
// entire application. Especially handles the loading of
// all resources so that they can be used by other things
// later.
//
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
            gs::GameState* state;   // Currently set to gamestate so that I don't have to worry about casting
                                    // Should just be a base State class so that it is interchangeable.
            rm::ImageManager imageManager;
            rm::TextureManager textureManager;
            sf::RenderWindow* renderWindow;
            sf::Time updateRate;
            uint32_t maxUpdates;

            // making events private, why would you call them directly? 
            void onResize();

        public:
            Engine();
            ~Engine();

            void Init(); // Might break-up init into more functions later

            void MainLoop(); // Main game loop

            void ProcessInput();

            void Update(); // Update internal states

            void Cleanup(); // Clean up for after exiting

            void Run();
    };
}

#endif
