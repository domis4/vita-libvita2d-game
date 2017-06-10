#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

#include "titlescreen/titlescreen-module.h"

class GameModule {
    private:
        SceCtrlData pad;
        vita2d_pgf *pgf;
        vita2d_pvf *pvf;
        vita2d_texture *image;
        TitlescreenModule titlescreen;
        float rad;
        
    public:
        void init();
        void update();
        void initRender();
        void render();
        void end();
};