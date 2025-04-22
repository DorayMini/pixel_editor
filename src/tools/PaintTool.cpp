#include "PaintTool.hpp"
#include <iostream>

bool px::PaintTool::acceptsClick(int x, int y) const {
    return true;
}

void px::PaintTool::onMouseDown() {
    std::cout << "click" << '\n';
    return;
}

void px::PaintTool::onMouseUp() {
    std::cout << "no click" << '\n';
    return;
}
