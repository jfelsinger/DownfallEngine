//===========================
// texturemanager.h
//
// Manages sets of textures that can be used as game
// sprites. Size isn't limited but spritesheets should
// be loaded in grouped by size to make things easier
//
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

//===========================
// Forwarded dependencies


//===========================
// Included dependencies
#include <vector>
#include <SFML/Graphics.hpp>

namespace rm
{
    class TextureManager
    {
        private:
            std::vector<sf::Texture> textures;

        public:
            TextureManager();
            ~TextureManager();

            void AddTexture(sf::Texture& texture);
            sf::Texture* GetTexture(const int index);

            void FillFromImage(sf::Image* image, int w, int h);
    };
}

#endif
