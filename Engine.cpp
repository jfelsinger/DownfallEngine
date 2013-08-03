#include <iostream>
#include <stdint.h>
#include <SFML/Graphics.hpp>

#include "worldBuilding/layergroup.h"
#include "worldBuilding/tile.h"
#include "worldBuilding/map.h"
#include "worldBuilding/mapfactory.h"
#include "worldBuilding/world.h"
#include "gameStates/gamestate.h"
#include "engine.h"

namespace ae
{
    Engine::Engine() :
        updateRate(sf::milliseconds(1000.0f / 20.0f)), // 20Hz(df)
        maxUpdates(10)
    {
    }

    Engine::~Engine()
    {
    }

    void Engine::Init()
    {
        renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Adventure Engine");

        // Going to have to use some type of resource file when the app gets released
        // Don't want our resources to be so easy to get to, lol
        //
        // Load all of the spritesheet/common images into memory so that drawing them
        // is quick, special images (ie those used in cutscenes) would be loaded
        // when used.
        imageManager.LoadImageFromFile("textures/mc16x16.png");
        textureManager.FillFromImage(imageManager.GetImage(0), 16, 16);

        // Initialize a new game state
        // Will be handled by a menu later on and wouldn't start as a gamestate
        state = new gs::GameState();

        // Give the gamestate a reference to the textures
        state->SetTextureManager(&textureManager);
        state->Init();
    }

    void Engine::MainLoop()
    {
        sf::Clock updateClock;
        updateClock.restart();

        // When to update next?
        sf::Time updateNext = updateClock.getElapsedTime();

        while (renderWindow->isOpen())
        {
            // Count update loop calls
            uint32_t updates = 0;

            ProcessInput();

            sf::Time currentTime = updateClock.getElapsedTime();

            // If the time elapsed (currentTime - updateNext) is >= the update rate, (We don't have extra time)
            // and the ammount of updated is still lower than the max to run before drawing
            // continue to process/catchup
            while((currentTime - updateNext) >= updateRate && updates++ < maxUpdates)
            {

                // Set the time for the next update
                updateNext += updateRate;
            }
            // When we have extra time, or it has processed the max amount of updates
            // the below runs, drawing what output there is to draw

            // Let the active state draw to the window
            state->Draw(renderWindow);

            // Display everything that was drawn
            renderWindow->display();

            // Calculate the remaining time and sleep it
            sf::Time sleepTime = currentTime - updateNext;
            if (sleepTime > sf::milliseconds(0))
            {
                sf::sleep(sleepTime);
            }
        }
    }

    void Engine::ProcessInput()
    {
        // A bunch of temporary stuff to handle if the window has been closed or not
        sf::Event event;

        renderWindow->pollEvent(event);

        if (event.type == sf::Event::Closed)
            renderWindow->close();
        else if (event.type == sf::Event::Resized)
            onResize();
    }

    void Engine::Update()
    {
    }

    void Engine::Cleanup()
    {
        // Everybody, everywhere
    }

    void Engine::Run()
    {
        Init();

        MainLoop();

        Cleanup();
    }

    void Engine::onResize()
    {
        sf::Vector2f size = static_cast<sf::Vector2f>(renderWindow->getSize());

        if (size.x < 800)
            size.x = 800;
        if (size.y < 600)
            size.y = 600;

        renderWindow->setSize(static_cast<sf::Vector2u>(size));

        // Reset grid view
        
        renderWindow->setView(*(new sf::View(sf::FloatRect(0.f, 0.f, size.x, size.y))));
    }
}
