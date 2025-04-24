#include "EraseTool.hpp"

px::EraseTool::EraseTool(sf::RenderWindow& window, px::Canvas& canvas)
    : BaseCanvasTool(window, canvas){}

void px::EraseTool::applyToPixel(int index) {
    _canvas.pixels[index].second = _canvas.getStdColor();
}

void px::EraseTool::endApplyToPixel() {
    return;
}
