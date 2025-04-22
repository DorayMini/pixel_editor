#ifndef __PAINT_TOOL__
#define __PAINT_TOOL__

#include "ITool.hpp"

#include <SFML/Graphics.hpp>

namespace px {
    class PaintTool: public ITool {
    public:
        bool acceptsClick(int x, int y) const override;
        void onMouseDown() override;
        void onMouseUp() override;
    private:
        sf::Color color;
    };
} // namespace px

#endif // __PAINT_TOOL__
