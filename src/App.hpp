#ifndef __APP_HPP__
#define __APP_HPP__

#include <SFML/Graphics.hpp>

#include "window/WindowWrapper.hpp"
#include "canvas/Canvas.hpp"
#include "tools/ToolManager.hpp"

namespace px {
    class App {
    public:
        App();
        void run();
    private:
        px::WindowWrapper* window_w;
        sf::RenderWindow* window;
        px::Canvas* canvas;
        px::ToolManager toolManager;
    };
} // namespace px
#endif
