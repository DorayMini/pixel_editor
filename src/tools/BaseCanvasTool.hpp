#ifndef __BASE_CANVAS_TOOL_HPP__
#define __BASE_CANVAS_TOOL_HPP__
#include "ITool.hpp"

#include "../window/Mouse.hpp"
#include "../canvas/Canvas.hpp"
#include "../window/WindowWrapper.hpp"

namespace px {
    class BaseCanvasTool: public ITool {
    public:
        BaseCanvasTool(sf::RenderWindow& window, px::Canvas& canvas)
            : _window(window), _canvas(canvas ) {}
        bool acceptsClick() const override {
            int width = _canvas.getPixelCounts().x;
            for (size_t i = 0; i < _canvas.pixels.size(); i++) {
                int x = i % width;
                int y = i / width;
                if (px::Mouse::isCanvasPixelHovered(_window, _canvas, x, y)) {
                    _pxNum = i;
                    return 1;
                }
            }
            return 0;
        }

        void onMouseDown() override {
            applyToPixel(_pxNum);
        }

        void onMouseUp() override {
            endApplyToPixel();
        }

        std::function<void(bool&)> getCallback() override {
            return [this](bool& isClicked){
                if(isClicked) {
                    if (this->acceptsClick())
                        this->onMouseDown();
                }
                else
                    this->onMouseUp();
            };
        }
    protected:
        virtual void applyToPixel(int index) = 0;
        virtual void endApplyToPixel() = 0;

        sf::RenderWindow& _window;
        px::Canvas& _canvas;
        mutable int _pxNum = 0;
    };
} // namespace px
#endif // __BASE_CANVAS_TOOL_HPP__
