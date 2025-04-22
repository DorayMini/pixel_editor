#ifndef __APP_HPP__
#define __APP_HPP__

#include "../window/WindowWrapper.hpp"
#include "../canvas/Canvas.hpp"

namespace px {
    class App {
    private:
        void run();
        void update(float dt);
    public:
        px::WindowWrapper& window;
        px::Canvas& canvas;
    };
} // namespace px
#endif
