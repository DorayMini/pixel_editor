#ifndef __MOUSE_HPP__
#define __MOUSE_HPP__

#include "../canvas/Canvas.hpp"
#include "../tools/ITool.hpp"

#include <SFML/Graphics.hpp>

#include <map>
#include <utility>
#include <vector>

typedef unsigned int uint;

namespace px {
    class Mouse {
    public:
        static sf::Vector2i getPosition(sf::RenderWindow& window);
        static void setPosition(sf::RenderWindow& window, int x, int y);
        static float getDistanceToMouse(sf::RenderWindow& window, int x, int y);
        static float getCanvasDistanceToMouse(sf::RenderWindow& window, px::Canvas& canvas, int px, int py);

        static void setOnClick(ITool* tool, sf::Mouse::Button button);
        static void mousePressed(sf::RenderWindow& window);
        void view();
    private:

        Mouse(const Mouse&) = delete;
        void operator=(const Mouse&) = delete;
    };

} // namespace px

namespace px::_detail {
    class Mouse {
    public:
        static inline std::map<sf::Mouse::Button, std::pair<ITool*, bool /* OnClicked */>> activeTools;
    };
} // namespace px::detail
#endif
