#include "texturemanager.h"
#include <SFML/Graphics.hpp>

namespace rm
{
    TextureManager::TextureManager()
    {
    }

    TextureManager::~TextureManager()
    {
    }

    void TextureManager::AddTexture(sf::Texture& texture)
    {
        textures.push_back(texture);
    }

    sf::Texture* TextureManager::GetTexture(const int index)
    {
        return &textures[index];
    }

    // Takes an image of constant sized images on a grid and fills
    // the textures list with them
    void TextureManager::FillFromImage(sf::Image* image, int w, int h)
    {
        sf::Vector2u vector = image->getSize();

        // The width and height of a single sprite/texture
        // on the spritesheet image
        int tileW = (vector.x + w - 1) / w;
        int tileH = (vector.y + h - 1) / h;

        for(int i = 0; i < tileW; i++)
        {
            for(int j = 0; j < tileH; j++)
            {
                // Cut a texture out of the image, displacing the rectangle
                // to cut out by multiple's of the width and height
                sf::Texture texture;
                texture.loadFromImage(*image, sf::IntRect(i*w, j*h, w, h));
                
                textures.push_back(texture);
            }
        }
    }
}
