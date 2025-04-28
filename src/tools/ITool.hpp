#ifndef __TOOL_HPP__
#define __TOOL_HPP__

#include <functional>

namespace px {
    class ITool {
    public:
        virtual bool acceptsClick() const = 0;
        virtual void onMouseDown() = 0;
        virtual void onMouseUp() = 0;

        virtual std::function<void(bool&)> getCallback() = 0;
        virtual ~ITool() = default;
    };
} // namespace px

#endif // __CANVAS_HPP__
