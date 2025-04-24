#ifndef __TOOL_MANAGER_HPP__
#define __TOOL_MANAGER_HPP__

#include "ITool.hpp"

#include <vector>
#include <memory>

namespace px {
    class ToolManager: public ITool{
    public:
        template<typename ToolType, typename... Args>
        void createTool(Args&&... args) {
            _tools.push_back(std::make_unique<ToolType>(std::forward<Args>(args)...));
        }
        px::ITool& getTool(int index) const;

        bool acceptsClick(int x, int y) const override;
        void onMouseDown() override;
        void onMouseUp() override;
    private:
        std::vector<std::unique_ptr<ITool>> _tools;
        int _currentTool = 0;
    };
} // namespace px
#endif // __TOOL_MANAGER_HPP__
