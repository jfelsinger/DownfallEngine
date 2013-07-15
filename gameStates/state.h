//===========================
// state.h
//
// States are distinct states that the application
// could be in within the running process
// The game itself would be one,
// The start menu would be another. etc, etc.
//
#ifndef STATE_H
#define STATE_H

//===========================
// Forward declarations

//===========================
// Included dependencies
#include <SFML/Graphics.hpp>

namespace gs
{
    // Virtual class to extend off of for other states
    class State
    {
        public:
            virtual void Init() = 0;
            virtual void Draw(sf::RenderWindow* renderWindow) = 0;
    };
}

#endif
