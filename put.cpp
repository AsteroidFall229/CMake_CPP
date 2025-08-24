//
// Created by AsteroidFall229 on 2025/8/23.
//

#ifndef PUT_H
#define PUT_H

#include "box.h"

void tools::put() {
    using namespace stdio;
    cls();

    cout << left << setw(20) << Game::T[0].getGamerName()<<endl;

    cout << "                    +---+---+---+" << endl;
    cout << "  骰子:             |";
//第一行
    if (Game::T[0][0][2].value==0) cout <<"   |";
    else {
        setColor(Game::T[0][0][2].font, Game::T[0][0].bg);
        cout << " " << Game::T[0][0][2].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][1][2].value==0) cout << "   |";
    else {
        setColor(Game::T[0][1][2].font, Game::T[0][1].bg);
        cout << " " << Game::T[0][1][2].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][2][2].value==0) cout << "   |";
    else {
        setColor(Game::T[0][2][2].font, Game::T[0][2].bg);
        cout << " " << Game::T[0][2][2].value;
        setColor();
        cout <<" |";
    }

    //中间random

    cout << endl << "      +---+         +---+---+---+" << endl;
    cout << "      | ";
    if (Game::T[0].random == 0) cout << " ";
    else                        cout << Game::T[0].random;
    cout << " |         |";

    //第二行

    if (Game::T[0][0][1].value==0) cout << "   |";
    else {
        setColor(Game::T[0][0][1].font, Game::T[0][0].bg);
        cout << " " << Game::T[0][0][1].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][1][1].value==0) cout << "   |";
    else {
        setColor(Game::T[0][1][1].font, Game::T[0][1].bg);
        cout << " " << Game::T[0][1][1].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][2][1].value==0) cout << "   |";
    else {
        setColor(Game::T[0][2][1].font, Game::T[0][2].bg);
        cout << " " << Game::T[0][2][1].value;
        setColor();
        cout <<" |";
    }

    //中间行

    cout << endl << "      +---+         +---+---+---+" << endl;
    cout << "                    |";

    //第三行

    if (Game::T[0][0][0].value==0) cout << "   ";
    else {
        setColor(Game::T[0][0][0].font, Game::T[0][0].bg);
        cout << " " << Game::T[0][0][0].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][1][0].value==0) cout << "   |";
    else {
        setColor(Game::T[0][1][0].font, Game::T[0][1].bg);
        cout << " " << Game::T[0][1][0].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][2][0].value==0) cout << "   |";
    else {
        setColor(Game::T[0][2][0].font, Game::T[0][2].bg);
        cout << " " << Game::T[0][2][0].value;
        setColor();
        cout <<" |";

        cout<<endl;
        cout << "                  =================" << "    总分:" << Game::T[0].getScore() << endl;
        cout << "                    ";

        cout << right << setw(3) << Game::T[0][0].getScore() << " ";
        cout << right << setw(3) << Game::T[0][1].getScore() << " ";
        cout << right << setw(3) << Game::T[0][2].getScore() << " ";
    }
}//输出UI

#endif //PUT_H
