#ifndef __MOUSE_HPP__
#define __MOUSE_HPP__

#include "../canvas/Canvas.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <optional>

typedef unsigned int uint;

namespace px {
    namespace _detail {
        class Mouse {
        public:
            static sf::Vector2i getPosition(sf::RenderWindow& window);
            static void setPosition(sf::RenderWindow& window, int x, int y);
            static uint getDistanceToMouse(sf::RenderWindow& window, int x, int y);
            static uint getCanvasDistanceToMouse(sf::RenderWindow& window, px::Canvas& canvas, int x, int y);

            void view();
        private:

            Mouse(const Mouse&) = delete;
            void operator=(const Mouse&) = delete;
            static inline sf::Vector2i s_mousePos;
        };
    } // namespace detail
} // namespace px
#endif
