#include "WindowWrapper.hpp"

#include <stdexcept>

WindowWrapper* WindowWrapper::_instance = nullptr;

WindowWrapper::WindowWrapper(const std::string& title, uint width, uint height)
    : _title(title), _width(width), _height(height)
{
    _window = new sf::RenderWindow(sf::VideoMode({_width, _height}), title);
}

WindowWrapper::~WindowWrapper() {
    delete _window;
}

WindowWrapper& WindowWrapper::getInstance(const std::string& title, uint width, uint height) {
    if(!_instance)
        _instance = new WindowWrapper(title, width, height);
    return *_instance;
}

WindowWrapper& WindowWrapper::getInstance() {
    if (!_instance)
        throw std::runtime_error("WindowWrapper not initialized! Call getInstance(title, width, height) first.");
    return *_instance;
}

sf::RenderWindow& WindowWrapper::getWindow() {
    if (!_window)
        throw std::runtime_error("Error");
    return *_window;
}
