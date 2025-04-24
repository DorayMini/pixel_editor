#include "ToolManager.hpp"

px::ITool& px::ToolManager::getTool(int index) const {
    return *_tools.at(index);
}

bool px::ToolManager::acceptsClick(int x, int y) const{
    return _tools.at(_currentTool).get()->acceptsClick(x, y);
}

void px::ToolManager::onMouseDown() {
    _tools.at(_currentTool).get()->onMouseDown();
}

void px::ToolManager::onMouseUp() {
    _tools.at(_currentTool).get()->onMouseUp();
}
