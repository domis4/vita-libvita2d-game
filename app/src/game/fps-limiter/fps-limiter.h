#pragma once

#include <iostream>
#include <chrono>

#include <psp2/kernel/threadmgr.h>
#include <vita2d.h> 

class FpsLimiter {
    private:
        int desired = 61;
        long lastLoopTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        long now = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        long OPTIMAL_TIME = 1000000 / desired;
        double delta = 0.0;
        long lastFpsTime = 0;
        int realFps = 0;
        int displayFps = 0;
        bool limitFPS = true;
    public:
        void init(bool vsync);
        void limitFps();
        int getFps();
        double getDelta();
};