#ifndef __CANVAS_HPP__
#define __CANVAS_HPP__

#include "../window/WindowWrapper.hpp"

#include <vector>

#include <SFML/Graphics.hpp>

typedef unsigned int uint;

/*
    TODO:
        - Colors
        - Adaptation to the size of the window
*/

namespace px {
    class Canvas {
    public:
        static Canvas& create(uint cw, uint ch, uint nx, uint ny, uint posx, uint posy);

        void update(uint cw, uint ch, uint ny, uint nx, uint posx, uint posy);
        void draw();

        void setPixelColor(uint x, uint y, const sf::Color& color);

        sf::Vector2i getPos();
        sf::Vector2i getSize();
        sf::Vector2i getScreenPixelCount();
        float getPixelSize();
    private:
        Canvas(uint cw, uint ch, uint nx, uint ny, uint posx, uint posy);

        Canvas(const Canvas&) = delete;
        void operator=(const Canvas&) = delete;


        uint _cw, _ch; // Canvas size
        uint _nx, _ny; // Pixel count in X and Y directions
        uint _posx, _posy; // Canvas pos
        float _ps; // Pixel size
        std::vector<std::pair<sf::Vector2i, sf::Color>> _pixels;

        sf::Color _stdColor = sf::Color::White;
        bool isUpdate = false;
        sf::RenderWindow& _window;
    };
} // namespace px
#endif // __CANVAS_HPP__
