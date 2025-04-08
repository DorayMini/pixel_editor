#ifndef __CANVAS_HPP__
#define __CANVAS_HPP__

#include "../window/WindowWrapper.hpp"

#include <vector>

#include <SFML/Graphics.hpp>

typedef unsigned int uint;

class Canvas {
public:
    static Canvas& create(uint w, uint h, uint posx, uint posy);
    void view();
private:
    Canvas(uint w, uint h, uint posx, uint posy);

    Canvas(const Canvas&) = delete;
    void operator=(const Canvas&) = delete;

    uint _w, _h; // Canvas size
    uint _posx, _posy; // Canvas pos
    float _ps; // Pixel size
    std::vector<sf::RectangleShape> _pixels;
    sf::RenderWindow& _window;
};
#endif // __CANVAS_HPP__
