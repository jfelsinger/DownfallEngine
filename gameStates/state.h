//===========================
// state.h
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
