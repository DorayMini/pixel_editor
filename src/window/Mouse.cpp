#include "Mouse.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

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

bool px::Mouse::isCanvasPixelHovered(sf::RenderWindow& window, px::Canvas& canvas, int px, int py) {
    sf::Vector2i canvasCenter = canvas.getPos();
    sf::Vector2i canvasSize = canvas.getSize();
    float pxSize = canvas.getPixelSize();

    float gridOriginX = canvasCenter.x - static_cast<float>(canvasSize.x / 2);
    float gridOriginY = canvasCenter.y - static_cast<float>(canvasSize.y / 2);

    float cellX = gridOriginX + px * pxSize;
    float cellY = gridOriginY + py * pxSize;

    sf::Vector2i mousePos = getPosition(window);

    float pxS2 = (pxSize / 2);

    float dx = cellX + pxS2 - mousePos.x;
    float dy = cellY + pxS2 - mousePos.y;
    uint dist = std::sqrt(dx * dx + dy * dy) / pxS2;
    return !dist;
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
