#include "fps-limiter.h"

void FpsLimiter::init() {

}

void FpsLimiter::limitFps() {

    now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    long updateLength = now - lastLoopTime;
    lastLoopTime = now;
    delta = updateLength / OPTIMAL_TIME;
    lastFpsTime = lastFpsTime + updateLength;
    realFps = realFps + 1;

    if (lastFpsTime >= 1000000) {
        displayFps = realFps;
        lastFpsTime = 0;
        realFps = 0;
    }

    if (limitFPS == true) {
        sceKernelDelayThread((lastLoopTime - now + OPTIMAL_TIME)); //microseconds = 1000000
    }
}

int FpsLimiter::getFps() {
    return displayFps;
}

double FpsLimiter::getDelta() {
    return delta;
}