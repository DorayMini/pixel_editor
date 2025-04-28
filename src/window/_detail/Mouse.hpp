#ifndef __DETAIL_MOUSE__
#define __DETAIL_MOUSE__

#include "../../tools/ITool.hpp"

#include <map>
#include <utility>
#include <vector>
#include <functional>

namespace px::_detail {
    class Mouse {
    public:
        struct Callback {
            std::function<void(bool&)> callback;
            sf::Mouse::Button button;
            bool isClicked;
        };

        static inline std::vector<Callback> callbacks;
    };
} // namespace px::detail

#endif // __DETAIL_MOUSE__
