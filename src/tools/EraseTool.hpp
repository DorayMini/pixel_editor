#ifndef __ERASE_TOOL_HPP__
#define __ERASE_TOOL_HPP__

#include "BaseCanvasTool.hpp"

namespace px {
    class EraseTool: public BaseCanvasTool {
    public:
        EraseTool(sf::RenderWindow& window, px::Canvas& canvas);
    protected:
        void applyToPixel(int index) override;
        void endApplyToPixel() override;
    };
} // namespace px
#endif // namespace __ERASE_TOOL__
