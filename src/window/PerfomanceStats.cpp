#include "PerfomanceStats.hpp"

void px::_detail::PerfomanceStats::updateFPS(float alpha) {
    float deltaTime = clock.restart().asSeconds();
    float currentFPS = (deltaTime > 0.f) ? (1.f / deltaTime) : 0.f;

    fps = alpha * currentFPS + (1.f - alpha) * fps;
}

float px::_detail::PerfomanceStats::getFPS() {
    return fps;
}
