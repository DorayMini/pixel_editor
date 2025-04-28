#ifndef __MOUSE_HPP__
#define __MOUSE_HPP__

#include "../canvas/Canvas.hpp"

#include "_detail/Mouse.hpp"
#include <SFML/Graphics.hpp>

typedef unsigned int uint;

namespace px {
    class Mouse {
    public:
        static sf::Vector2i getPosition(sf::RenderWindow& window);
        static void setPosition(sf::RenderWindow& window, int x, int y);
        static float getDistanceToMouse(sf::RenderWindow& window, int x, int y);
        static bool isCanvasPixelHovered(sf::RenderWindow& window, px::Canvas& canvas, int px, int py);

        /*
        The "pos" parameter is responsible
        for changing the callback,
        if you do not want to change it,
        do not set the parameter
        */
        static unsigned int setCallback(std::function<void(bool&)> callback, sf::Mouse::Button button, unsigned int pos = std::numeric_limits<unsigned int>::max());
        static void mousePressed(const sf::Event& event, sf::RenderWindow& window);
        void view();
    private:

        Mouse(const Mouse&) = delete;
        void operator=(const Mouse&) = delete;
    };

} // namespace px
#endif
