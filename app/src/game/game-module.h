#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

class GameModule {
    private:
        SceCtrlData pad;
        vita2d_pgf *pgf;
        vita2d_pvf *pvf;
        vita2d_texture *image;
        float rad;
    public:
        void init();
        void update();
        void render();
        void end();
};