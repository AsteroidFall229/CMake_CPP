//
// Created by AsteroidFall229 on 2025/8/23.
//

#ifndef TOOLS_PUT_H
#define TOOLS_PUT_H

#include "box.h"
#include <stdio.h>

//输出单元
void tools::PLU(const int& value,const color& font, const color& background) {
    std::cout << " ";
    setColor(font,background);
    if (value==0)    printf(" ");
    else             printf("%d",value);
    setColor();
    printf(" |");
}
// void tools::PLU(const int& value,const color& font, const color& background) {
//     std::cout << " ";
//     setColor(font,background);
//     if (value==0)    std::cout <<" ";
//     else             std::cout <<value;
//     setColor();
//     std::cout <<" |";
// }

//输出UI
void tools::put() {
    using namespace stdio;
    system("cls");

    cout << left << setw(20) << Game::T[0].getGamerName();

    cout << "\n                    +---+---+---+\n";
    cout << "  骰子:             |";
//第一行

    PLU(Game::T[0][0][2].value,Game::T[0][0][2].color,Game::T[0][0].bg_color);
    PLU(Game::T[0][1][2].value,Game::T[0][1][2].color,Game::T[0][1].bg_color);
    PLU(Game::T[0][2][2].value,Game::T[0][2][2].color,Game::T[0][2].bg_color);

    //中间random

    cout << "\n      +---+         +---+---+---+\n";
    cout << "      | ";
    if (Game::T[0].random == 0) cout << " ";
    else                        cout << Game::T[0].random;
    cout << " |         |";

    //第二行

    PLU(Game::T[0][0][1].value,Game::T[0][0][1].color,Game::T[0][0].bg_color);
    PLU(Game::T[0][1][1].value,Game::T[0][1][1].color,Game::T[0][1].bg_color);
    PLU(Game::T[0][2][1].value,Game::T[0][2][1].color,Game::T[0][2].bg_color);

    //中间行

    cout << "\n      +---+         +---+---+---+\n";
    cout << "                    |";

    //第三行

    PLU(Game::T[0][0][0].value,Game::T[0][0][0].color,Game::T[0][0].bg_color);
    PLU(Game::T[0][1][0].value,Game::T[0][1][0].color,Game::T[0][1].bg_color);
    PLU(Game::T[0][2][0].value,Game::T[0][2][0].color,Game::T[0][2].bg_color);

        cout << "\n                  =================" << "    总分:" << Game::T[0].getScore();
        cout << "\n                    ";

        cout << right << setw(3) << Game::T[0][0].getScore() << " ";
        cout << right << setw(3) << Game::T[0][1].getScore() << " ";
        cout << right << setw(3) << Game::T[0][2].getScore() << " ";

        cout << "\n\n                    ";

        cout << right << setw(3) << Game::T[1][0].getScore() << " ";
        cout << right << setw(3) << Game::T[1][1].getScore() << " ";
        cout << right << setw(3) << Game::T[1][2].getScore() << " ";

        cout << "\n                  =================" << "    总分:" << Game::T[1].getScore();
        cout << left << setw(20) <<"\n当前分数最高玩家:"<< "   |";

    PLU(Game::T[1][0][0].value,Game::T[1][0][0].color,Game::T[1][0].bg_color);
    PLU(Game::T[1][1][0].value,Game::T[1][1][0].color,Game::T[1][1].bg_color);
    PLU(Game::T[1][2][0].value,Game::T[1][2][0].color,Game::T[1][2].bg_color);

        cout <<"\n"<< left << setw(20) << Game::gamer_name;
        cout << "+---+---+---+         +---+\n";
        cout << "                    |";

    PLU(Game::T[1][0][1].value,Game::T[1][0][1].color,Game::T[1][0].bg_color);
    PLU(Game::T[1][1][1].value,Game::T[1][1][1].color,Game::T[1][1].bg_color);
    PLU(Game::T[1][2][1].value,Game::T[1][2][1].color,Game::T[1][2].bg_color);
            cout << "         | ";
            if(Game::T[1].random == 0) cout << " ";
            else cout << Game::T[1].random;
            cout << " |\n";

            cout << "最高分/分差         +---+---+---+         +---+\n ";
            cout << right << setw(4) << std::max(Game::T[0].getScore(), Game::T[1].getScore())
                 << "/"
                 << left << setw(4) << abs(Game::T[0].getScore() - Game::T[1].getScore());
            cout << "          |" ;

    PLU(Game::T[1][0][2].value,Game::T[1][0][2].color,Game::T[1][0].bg_color);
    PLU(Game::T[1][1][2].value,Game::T[1][1][2].color,Game::T[1][1].bg_color);
    PLU(Game::T[1][2][2].value,Game::T[1][2][2].color,Game::T[1][2].bg_color);

                cout << "             :骰子\n";
                cout << "                    +---+---+---+" << "                    \n";
                cout << "                    ";

                cout << right << setw(33) << Game::T[1].getGamerName()<<endl;
}

#endif //TOOLS_PUT_H
