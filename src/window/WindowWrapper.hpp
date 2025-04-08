#ifndef __WINDOW_WRAPPER_HPP__
#define __WINDOW_WRAPPER_HPP__

#include <array>
#include <string>

#include <SFML/Graphics.hpp>

typedef unsigned int uint;

class WindowWrapper {
public:
    static WindowWrapper& getInstance(const std::string& title, uint width, uint height);
    static WindowWrapper& getInstance();
    sf::RenderWindow& getWindow();
private:
    WindowWrapper(const std::string& title, uint width, uint height);
    ~WindowWrapper();

    WindowWrapper(const WindowWrapper&) = delete;
    void operator=(const WindowWrapper&) = delete;

    std::string _title;
    uint _width, _height;
    sf::RenderWindow* _window;

    static WindowWrapper* _instance;
};

#endif // __WINDOW_WRAPPER_HPP__
