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

        if (T[0].getScore()>T[1].getScore())
            gamer_name=T[0].getGamerName();
        else
            if (T[1].getScore()>T[0].getScore())
                gamer_name=T[1].getGamerName();
            else
                gamer_name="--FAIR--";

        if (T[0].allFull()||T[1].allFull())
            return;

        tools::put();

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
                    T[alt][1].bg_color=T[0].bg_use;
                    T[alt][1][0].color = color::black;
                    T[alt][1][1].color = color::black;
                    T[alt][1][2].color = color::black;
                }
                break;
            case 'q':
            case 'Q':
                menu();
                break;
            default:
                continue;
        }
    }
}

#endif //GAME_SWITCH_PROCESS
