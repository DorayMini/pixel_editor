#include "PaintTool.hpp"

px::PaintTool::PaintTool(sf::RenderWindow& window, px::Canvas& canvas, sf::Color col)
    : BaseCanvasTool(window, canvas), color(col) {}


void px::PaintTool::applyToPixel(int index) {
    _canvas.pixels[index].second = color;
}

void px::PaintTool::endApplyToPixel() {
    return;
}
