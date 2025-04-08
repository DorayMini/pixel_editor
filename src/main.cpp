#include <window/WindowWrapper.hpp>
#include <canvas/Canvas.hpp>

#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow& window = WindowWrapper::getInstance("Pixel editor", 800, 600).getWindow();
    window.setFramerateLimit(144);

    Canvas& canvas = Canvas::create(200, 200, 400, 300);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        canvas.view();
        window.display();
    }
}
