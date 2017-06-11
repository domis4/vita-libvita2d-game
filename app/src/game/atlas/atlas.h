#pragma once

class Atlas {
    private:
        bool inMainMenu = true;
    public:
        void init();
        bool isInMainMenu();
};