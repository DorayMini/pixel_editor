#include "Mouse.hpp"

#include <cmath>
#include <algorithm>

sf::Vector2i px::Mouse::getPosition(sf::RenderWindow& window) {
    return sf::Mouse::getPosition(window);
}

void px::Mouse::setPosition(sf::RenderWindow& window, int x, int y) {
    sf::Mouse::setPosition(sf::Vector2i(x, y), window);
}

float px::Mouse::getDistanceToMouse(sf::RenderWindow& window, int x, int y) {
    auto mousePos = getPosition(window);
    return sqrt((x-mousePos.x)*(x-mousePos.x) + (y-mousePos.y)*(y-mousePos.y));
}

float px::Mouse::getCanvasDistanceToMouse(sf::RenderWindow& window, px::Canvas& canvas, int px, int py) {
    sf::Vector2i mousePos = getPosition(window);

    sf::Vector2i canvasCenter = canvas.getPos();
    sf::Vector2i canvasSize = canvas.getSize();
    float pxSize = canvas.getPixelSize();

    int gridOriginX = canvasCenter.x - static_cast<int>((canvasSize.x) / 2);
    int gridOriginY = canvasCenter.y - static_cast<int>((canvasSize.y) / 2);

    float cellCenterX = gridOriginX + (px + (px / 2)) * pxSize;
    float cellCenterY = gridOriginY + (py + (px / 2)) * pxSize;

    float dx = cellCenterX - mousePos.x;
    float dy = cellCenterY - mousePos.y;
    float dist = std::sqrt(dx * dx + dy * dy);

    return dist / pxSize;
}


void px::Mouse::setOnClick(ITool* tool, sf::Mouse::Button button) {
    px::_detail::Mouse::activeTools[button] = std::make_pair(tool, false);
}

void px::Mouse::mousePressed(sf::RenderWindow& window) {
    if (px::_detail::Mouse::activeTools.empty())
        return;

    for (const auto& pair: px::_detail::Mouse::activeTools) {
        auto [tool, isClicked] = pair.second;
        if (sf::Mouse::isButtonPressed(pair.first)) {
            isClicked = true;
            auto mousePos = getPosition(window);
            if (tool->acceptsClick(mousePos.x, mousePos.y)) {
                tool->onMouseDown();
            }
        }
        else {
            if (isClicked) {
                tool->onMouseUp();
                isClicked = false;
            }
        }
    }
}
