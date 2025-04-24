#ifndef __PAINT_TOOL__
#define __PAINT_TOOL__

#include "BaseCanvasTool.hpp"

#include <SFML/Graphics.hpp>

namespace px {
    class PaintTool: public BaseCanvasTool{
    public:
        PaintTool(sf::RenderWindow& window, px::Canvas& canvas, sf::Color col);

        sf::Color color;
    protected:
        void applyToPixel(int index) override;
        void endApplyToPixel() override;
    };
} // namespace px

#endif // __PAINT_TOOL__
