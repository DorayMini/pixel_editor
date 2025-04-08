#include "Canvas.hpp"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

Canvas::Canvas(uint w, uint h, uint posx, uint posy)
    : _w(w), _h(h), _posx(posx), _posy(posy), _window(WindowWrapper::getInstance().getWindow())
{
    auto windowSize = _window.getSize();
    float _pw = windowSize.x / _w;
    float _ph = windowSize.y / _h;
    _ps = std::min(_pw, _ph);

    std::cout << _pw << '\n';
    for (int y = 0; y < _w; ++y) {
        for (int x = 0; x < _h; ++x) {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(_ps, _ps));
            rect.setPosition({_posx + (x - _w / 2), _posy + (y - _h / 2)});
            rect.setFillColor(sf::Color::White);
            _pixels.push_back(rect);
        }
    }
}


Canvas& Canvas::create(uint w, uint h, uint posx, uint posy) {
    static Canvas canvas(w, h, posx, posy);
    return canvas;
}

void Canvas::view() {
    for (auto& pixel: _pixels)
        _window.draw(pixel);
}
