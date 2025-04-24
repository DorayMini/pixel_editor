#include <canvas/Canvas.hpp>
#include <window/Mouse.hpp>
#include <window/WindowWrapper.hpp>
#include <tools/PaintTool.hpp>
#include <tools/EraseTool.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

int main() {
  auto &windowW = px::WindowWrapper::getInstance("Pixel editor", 800, 600);
  sf::RenderWindow &window = windowW.getWindow();
  window.setFramerateLimit(144);

  px::Canvas &canvas = px::Canvas::create(100, 100, 10, 10, window.getSize().x / 2, window.getSize().y / 2);
  px::PaintTool tool(window, canvas, sf::Color::Red);
  px::EraseTool erase(window, canvas);
  px::Mouse::setOnClick(&tool, sf::Mouse::Button::Left);
  px::Mouse::setOnClick(&erase, sf::Mouse::Button::Right);
  while (window.isOpen()) {
    system("clear");
    unsigned int dist = px::Mouse::isCanvasPixelHovered(window, canvas, 1, 1);
    std::cout << dist << std::endl;

    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    px::Mouse::mousePressed(window);

    window.clear();
    canvas.draw();
    windowW.update();
  }
}
