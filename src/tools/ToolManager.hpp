#ifndef __TOOL_MANAGER_HPP__
#define __TOOL_MANAGER_HPP__

#include "ITool.hpp"
#include "../window/Mouse.hpp"

#include <vector>
#include <memory>

namespace px {
    class ToolManager {
    public:
        template<typename ToolType, typename... Args>
        void createTool(Args&&... args) {
            _tools.push_back(std::make_unique<ToolType>(std::forward<Args>(args)...));
            if (_callbackPos == std::numeric_limits<unsigned int>::max())
                _callbackPos = px::Mouse::setCallback(_tools.at(0)->getCallback(), sf::Mouse::Button::Left);
        }
        px::ITool& getTool(int index) const;
        void setCurrentTool(int index);

    private:
        std::vector<std::unique_ptr<ITool>> _tools;
        int _currentTool = 0;
        unsigned int _callbackPos = std::numeric_limits<unsigned int>::max();
    };
} // namespace px
#endif // __TOOL_MANAGER_HPP__
