#include "Mouse.hpp"

#include <cmath>
#include <algorithm>
#include <iostream>

typedef px::_detail::Mouse _dMouse;

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


unsigned int px::Mouse::setCallback(std::function<void(bool&)> callback, sf::Mouse::Button button, unsigned int pos) {
    if(pos == std::numeric_limits<unsigned int>::max()) {
        _dMouse::callbacks.push_back(_dMouse::Callback{callback, button, false});
        return _dMouse::callbacks.size() - 1;
    }
    else {
        if (pos < _dMouse::callbacks.size()) {
            _dMouse::Callback call = _dMouse::callbacks[pos];
            call.callback = callback;
            call.button = button;
            return pos;
        }
        else {
            std::cerr << "Invalid position provided for callback update.\n";
            return std::numeric_limits<unsigned int>::max();
        }
    }
}

void px::Mouse::mousePressed(const sf::Event& event, sf::RenderWindow& window) {
    if (_dMouse::callbacks.empty()) return;

    for (auto& callbackData: _dMouse::callbacks) {
        if (event.is<sf::Event::MouseButtonPressed>()) {
            callbackData.isClicked = true;
        } else if (event.is<sf::Event::MouseButtonReleased>()) {
            callbackData.isClicked = false;
        }

        callbackData.callback(callbackData.isClicked);
    }
}
