#include "imagemanager.h"
#include <SFML/Graphics.hpp>

namespace rm
{
    ImageManager::ImageManager()
    {
    }
    
    ImageManager::~ImageManager()
    {
    }

    void ImageManager::AddImage(sf::Image& image)
    {
        images.push_back(image);
    }

    // Generally used for loading an entire spritesheet at once so that
    // it can be chopped up by the texture manager
    void ImageManager::LoadImageFromFile(const std::string imgLocation)
    {
        sf::Image image;
        image.loadFromFile(imgLocation);

        images.push_back(image);
    }

    sf::Image* ImageManager::GetImage(const int index)
    {
        return &images[index];
    }
}
