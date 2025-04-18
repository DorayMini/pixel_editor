#include <canvas/Canvas.hpp>
#include <window/Mouse.hpp>
#include <window/WindowWrapper.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

int main() {
  sf::RenderWindow &window = px::WindowWrapper::getInstance("Pixel editor", 800, 400).getWindow();
  window.setFramerateLimit(60);

  px::Canvas &canvas = px::Canvas::create(100, 100, 10, 10, 0, window.getSize().y / 2);

  int x = 1;
  int n = 3;
  float i = 0.1;
  float s = 0;
  while (window.isOpen()) {
    if (x >= window.getSize().x || x <= 0) {
        n *= -1;
        i *= -1;
    }
    system("clear");
    // unsigned int dist = px::_detail::Mouse::getCanvasDistanceToMouse(window, canvas, window.getSize().x / 2, window.getSize().y / 2);
    // std::cout << dist << std::endl;

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear();
    canvas.update(50 + s, 200 + s, 10, 10, x, window.getSize().y / 2);
    canvas.draw();
    window.display();

    s += i;
    x += n;
  }
}
