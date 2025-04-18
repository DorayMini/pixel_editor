#include "Mouse.hpp"

#include <cmath>

sf::Vector2i px::_detail::Mouse::getPosition(sf::RenderWindow& window) {
    s_mousePos = sf::Mouse::getPosition(window);
    return s_mousePos;
}

void px::_detail::Mouse::setPosition(sf::RenderWindow& window, int x, int y) {
    sf::Mouse::setPosition(sf::Vector2i(x, y), window);
}

uint px::_detail::Mouse::getDistanceToMouse(sf::RenderWindow& window, int x, int y) {
    getPosition(window);
    return sqrt((x-s_mousePos.x)*(x-s_mousePos.x) + (y-s_mousePos.y)*(y-s_mousePos.y));
}

uint px::_detail::Mouse::getCanvasDistanceToMouse(sf::RenderWindow& window, px::Canvas& canvas, int x, int y) {
    float pxSize = canvas.getPixelSize();
    auto screenPxCount = canvas.getScreenPixelCount();
    int nx = x / screenPxCount.x;
    int ny = y / screenPxCount.y;

    uint dist = getDistanceToMouse(window, nx, ny);
    return dist;
}
