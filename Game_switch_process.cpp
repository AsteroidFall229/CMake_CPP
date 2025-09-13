//
// Created by AsteroidFall229 on 2025/9/12.
//

#ifndef GAME_SWITCH_PROCESS
#define GAME_SWITCH_PROCESS

#include "box.h"

void Game::switch_process() {
    T[alt].random=random;
    T[alt][1].bg_color=T[1].bg_use;
    T[alt][1][0].color=T[1].font_bg_use;
    T[alt][1][1].color=T[1].font_bg_use;
    T[alt][1][2].color=T[1].font_bg_use;
    while (true) {
        tools::cls();
        tools::put();
        if (T[0].allFull()||T[1].allFull())
            return;
        switch (getch()) {
            case 'a':
            case 'A':
                T[alt].set_Color(AorD::left);
                break;
            case 'd':
            case 'D':
                T[alt].set_Color(AorD::right);
                break;
            case 'E':
            case 'e':
                if (T[alt].inputValue(T[!alt])) {
                    T[alt].random=0;
                    alt.x();
                    T[alt].random=random;
                    T[alt][1].bg_color=T[1].bg_use;
                    T[alt][1][0].color = color::white;
                    T[alt][1][1].color = color::white;
                    T[alt][1][2].color = color::white;
                }
                break;
            case 'q':
            case 'Q':
                ESC();
                break;
        }
    }
}

#endif //GAME_SWITCH_PROCESS
