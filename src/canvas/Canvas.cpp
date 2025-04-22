#include "Canvas.hpp"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

px::Canvas::Canvas(uint cw, uint ch, uint nx, uint ny, uint posx, uint posy)
    : _cw(cw), _ch(ch), _nx(nx), _ny(ny), _posx(posx), _posy(posy), _window(WindowWrapper::getInstance().getWindow())
{
    update(cw, ch, nx, ny, posx, posy);
}

void px::Canvas::update(uint cw, uint ch, uint nx, uint ny, uint posx, uint posy) {
    bool isEmpty = _pixels.empty();

    auto windowSize = _window.getSize();
    _ps = std::min(float(cw / nx), float(ch / ny));

    for (int y = 0; y < ny; ++y) {
        for (int x = 0; x < nx; ++x) {
            int px = (posx - (cw / 2)) + x * _ps + 1;
            int py = (posy - (ch / 2)) + y * _ps + 1;

            if (isEmpty)
                _pixels.push_back(std::make_pair(sf::Vector2i(px, py), _stdColor));
            else {
                int index = x * nx + y;
                _pixels[index].first = sf::Vector2i(px, py);
            }
        }
    }
}

px::Canvas& px::Canvas::create(uint cw, uint ch, uint nx, uint ny, uint posx, uint posy) {
    static Canvas canvas(cw, ch, nx, ny, posx, posy);
    return canvas;
}

void px::Canvas::draw() {
    sf::RectangleShape pixelShape(sf::Vector2f(_ps, _ps));

    for (auto& px: _pixels) {
        if (px.first.x < 0 || px.first.y < 0
        || px.first.x > _window.getSize().x
        || px.first.y > _window.getSize().y)
            continue;

        pixelShape.setFillColor(px.second);
        pixelShape.setOutlineThickness(0.5f);
        pixelShape.setOutlineColor(sf::Color::Black);
        pixelShape.setPosition(sf::Vector2f(px.first.x, px.first.y));
        _window.draw(pixelShape);
    }
}

void px::Canvas::setPixelColor(uint x, uint y, const sf::Color& color) {
    int index = x * _nx + y;
    _pixels[index].second = color;
}

sf::Vector2i px::Canvas::getPos(){
    return sf::Vector2i(_posx, _posy);
}

sf::Vector2i px::Canvas::getSize() {
    return sf::Vector2i(_cw, _ch);
}

sf::Vector2i px::Canvas::getPixelCounts() {
    return sf::Vector2i(_nx, _ny);
}

float px::Canvas::getPixelSize() {
    return _ps;
}
