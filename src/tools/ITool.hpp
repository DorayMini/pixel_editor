#ifndef __TOOL_HPP__
#define __TOOL_HPP__

namespace px {
    class ITool {
    public:
        virtual bool acceptsClick(int x, int y) const = 0;
        virtual void onMouseDown() = 0;
        virtual void onMouseUp() = 0;

        virtual ~ITool() = default;
    };
} // namespace px

#endif // __CANVAS_HPP__
