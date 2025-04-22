#ifndef __PERFOMANCE_STATS__
#define __PERFOMANCE_STATS__

#include <SFML/Graphics.hpp>

namespace px {
    namespace _detail {
        class PerfomanceStats {
        public:
            void updateFPS(float alpha);
            float getFPS();
        private:
            sf::Clock clock;
            float fps = 0.0f;
        };
    } // namespace _detail
} // namespace px

#endif
