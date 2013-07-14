//===========================
// imagemanager.h
#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

//===========================
// Forwarded dependencies


//===========================
// Included dependencies
#include <vector>
#include <SFML/Graphics.hpp>

namespace rm
{
    class ImageManager
    {
        private:
            std::vector<sf::Image> images;

        public:
            ImageManager();
            ~ImageManager();

            void AddImage(sf::Image& image);
            void LoadImageFromFile(const std::string imgLocation);

            sf::Image* GetImage(const int index);
    };
}

#endif
