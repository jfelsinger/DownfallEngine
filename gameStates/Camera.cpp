#include "camera.h"
#include <SFML/Graphics.hpp>
#include <math.h>

namespace gs
{
    Camera::Camera(const int w, const int h, float speed)
    {
        width = w;
        height = h;

        if (speed < 0.0)
            speed = 0.0;
        else if (speed > 1.0)
            speed = 1.0;

        this->speed = speed;
    }

    Camera::~Camera()
    { }

    wb::Map* Camera::GetMap()
    {
        return map;
    }

    void Camera::SetMap(wb::Map* map)
    {
        this->map = map;
    }

    int Camera::GetWidth()
    {
        return width;
    }

    int Camera::GetHeight()
    {
        return height;
    }

    void Camera::Move(const int x, const int y)
    {
        position.x = (float)x;
        position.y = (float)y;
        targetPosition.x = (float)x;
        targetPosition.y = (float)y;
    }

    void Camera::MoveCenter(int x, int y)
    {
        x = x - (width / 2);
        y = y - (width / 2);

        position.x = (float)x;
        position.y = (float)y;
        targetPosition.x = (float)x;
        targetPosition.y = (float)y;
    }

    void Camera::PanTo(const int x, const int y)
    {
        targetPosition.x = (float)x;
        targetPosition.y = (float)y;
    }

    void Camera::PanToCenter(int x, int y)
    {
        x = x - (width / 2);
        y = y - (width / 2);

        targetPosition.x = (float)x;
        targetPosition.y = (float)y;
    }

    void Camera::Update()
    {
        // x/y distance and Euclidean distance
        float x, y, d;

        // Velocity magnitues
        float vx, vy, v;

        // Find x and y
        x = (float)(targetPosition.x - position.x);
        y = (float)(targetPosition.y - position.y);

        // If within 1px snap to it
        if ((x*x + y*y) <= 1)
        {
            position.x = targetPosition.x;
            position.y = targetPosition.y;
        }
        else
        {
            // Distance forumla
            d = sqrt((x*x + y*y));

            // 60 is currently an arbitrary number -> meh.
            v = (d*speed)/60;

            // Always move at least 1px
            if (v < 1.0f)
                v = 1.0f;

            vx = x * (v/d);
            vy = y * (v/d);

            // Update camera position
            position.x += vx;
            position.y += vy;
        }
    }

    sf::IntRect Camera::GetTileBounds(int tileSize)
    {
        int x = (int)(position.x / tileSize);
        int y = (int)(position.y / tileSize);

        int w = (int)(width / tileSize + 2);
        int h = (int)(height / tileSize + 2);

        if (x % tileSize != 0)
            w++;
        if (y % tileSize != 0)
            h++;

        return sf::IntRect(x, y, w, h);
    }

}

