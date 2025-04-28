#include "ToolManager.hpp"

px::ITool& px::ToolManager::getTool(int index) const {
    return *_tools.at(index);
}

void px::ToolManager::setCurrentTool(int index) {
    if (index < 0 && index >= _tools.size()) return;

    _currentTool = index;
    px::Mouse::setCallback(_tools.at(_currentTool)->getCallback(), sf::Mouse::Button::Left, _callbackPos);
}
