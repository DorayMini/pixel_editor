#include "App.hpp"

#include "tools/PaintTool.hpp"
#include "tools/EraseTool.hpp"


px::App::App() {
    window_w = &px::WindowWrapper::getInstance("Pixel editor", 800, 600);
    window = &window_w->getWindow();
    window->setFramerateLimit(144);

    canvas = &px::Canvas::create(100, 100, 10, 10, window->getSize().x / 2, window->getSize().y / 2);

    toolManager.createTool<PaintTool>(*window, *canvas, sf::Color::Red);
    toolManager.createTool<EraseTool>(*window, *canvas);
    px::Mouse::setOnClick(&toolManager, sf::Mouse::Button::Left);
}

void px::App::run() {
    while (window->isOpen()) {
    while (const std::optional event = window->pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window->close();
      }
    }
    px::Mouse::mousePressed(*window);

    window->clear();
    canvas->draw();
    window_w->update();
  }
}
