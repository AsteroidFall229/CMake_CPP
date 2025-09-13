//
// Created by AsteroidFall229 on 2025/8/23.
//

#ifndef TOOLS_PUT_H
#define TOOLS_PUT_H

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
        setColor(Game::T[0][0][2].color, Game::T[0][0].bg_color);
        cout << " " << Game::T[0][0][2].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][1][2].value==0) cout << "   |";
    else {
        setColor(Game::T[0][1][2].color, Game::T[0][1].bg_color);
        cout << " " << Game::T[0][1][2].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][2][2].value==0) cout << "   |";
    else {
        setColor(Game::T[0][2][2].color, Game::T[0][2].bg_color);
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
        setColor(Game::T[0][0][1].color, Game::T[0][0].bg_color);
        cout << " " << Game::T[0][0][1].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][1][1].value==0) cout << "   |";
    else {
        setColor(Game::T[0][1][1].color, Game::T[0][1].bg_color);
        cout << " " << Game::T[0][1][1].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][2][1].value==0) cout << "   |";
    else {
        setColor(Game::T[0][2][1].color, Game::T[0][2].bg_color);
        cout << " " << Game::T[0][2][1].value;
        setColor();
        cout <<" |";
    }

    //中间行

    cout << endl << "      +---+         +---+---+---+" << endl;
    cout << "                    |";

    //第三行

    if (Game::T[0][0][0].value==0) cout << "   |";
    else {
        setColor(Game::T[0][0][0].color, Game::T[0][0].bg_color);
        cout << " " << Game::T[0][0][0].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][1][0].value==0) cout << "   |";
    else {
        setColor(Game::T[0][1][0].color, Game::T[0][1].bg_color);
        cout << " " << Game::T[0][1][0].value;
        setColor();
        cout <<" |";
    }
    if (Game::T[0][2][0].value==0) cout << "   |";
    else {
        setColor(Game::T[0][2][0].color, Game::T[0][2].bg_color);
        cout << " " << Game::T[0][2][0].value;
        setColor();
        cout <<" |";
    }
        cout<<endl;
        cout << "                  =================" << "    总分:" << Game::T[0].getScore() << endl;
        cout << "                    ";

        cout << right << setw(3) << Game::T[0][0].getScore() << " ";
        cout << right << setw(3) << Game::T[0][1].getScore() << " ";
        cout << right << setw(3) << Game::T[0][2].getScore() << " ";

        cout << endl<<endl;
        cout << "                    ";

        cout << right << setw(3) << Game::T[1][0].getScore() << " ";
        cout << right << setw(3) << Game::T[1][1].getScore() << " ";
        cout << right << setw(3) << Game::T[1][2].getScore() << " ";

        cout << endl << "                  =================" << "    总分:" << Game::T[1].getScore() << endl;
        cout << left << setw(20) <<"当前分数最高玩家:"<< "   |";

        if (Game::T[1][0][0].value==0) cout << "   |";
        else {
            setColor(Game::T[1][0][0].color, Game::T[1][0].bg_color);
            cout << " " << Game::T[1][0][0].value;
            setColor();
            cout <<" |";
        }
        if (Game::T[1][1][0].value==0) cout << "   |";
        else {
            setColor(Game::T[1][1][0].color, Game::T[1][1].bg_color);
            cout << " " << Game::T[1][1][0].value;
            setColor();
            cout <<" |";
        }
        if (Game::T[1][2][0].value==0) cout << "   |";
        else {
            setColor(Game::T[1][2][0].color, Game::T[1][2].bg_color);
            cout << " " << Game::T[1][2][0].value;
            setColor();
            cout <<" |";
        }

        cout << endl;
        cout << left << setw(20) << Game::gamer_name;
        cout << "+---+---+---+         +---+" << endl;
        cout << "                    |";

        if (Game::T[1][0][1].value==0) cout << "   |";
        else {
            setColor(Game::T[1][0][1].color, Game::T[1][0].bg_color);
            cout << " " << Game::T[1][0][1].value;
            setColor();
            cout <<" |";
        }
        if (Game::T[1][1][1].value==0) cout << "   |";
        else {
            setColor(Game::T[1][1][1].color, Game::T[1][1].bg_color);
            cout << " " << Game::T[1][1][1].value;
            setColor();
            cout <<" |";
        }
        if (Game::T[1][2][1].value==0) cout << "   |";
        else {
            setColor(Game::T[1][2][1].color, Game::T[1][2].bg_color);
            cout << " " << Game::T[1][2][1].value;
            setColor();
            cout <<" |";
        }
            cout << "         | ";
            if(Game::T[1].random == 0) cout << " ";
            else cout << Game::T[1].random;
            cout << " |" << endl;

            cout << "最高分/分差         +---+---+---+         +---+" << endl <<" ";
            const int total_width = 8;  // 总宽度根据需要调整
            int max_score = std::max(Game::T[0].getScore(), Game::T[1].getScore());
            int diff = abs(Game::T[0].getScore() - Game::T[1].getScore());
            cout << right << setw(total_width/2) << max_score
                 << "/"
                 << left << setw(total_width/2) << diff;

            cout << "          |" ;

            if (Game::T[1][0][2].value==0) cout <<"   |";
            else {
                setColor(Game::T[1][0][2].color, Game::T[1][0].bg_color);
                cout << " " << Game::T[1][0][2].value;
                setColor();
                cout <<" |";
            }
            if (Game::T[1][1][2].value==0) cout << "   |";
            else {
                setColor(Game::T[1][1][2].color, Game::T[1][1].bg_color);
                cout << " " << Game::T[1][1][2].value;
                setColor();
                cout <<" |";
            }
            if (Game::T[1][2][2].value==0) cout << "   |";
            else {
                setColor(Game::T[1][2][2].color, Game::T[1][2].bg_color);
                cout << " " << Game::T[1][2][2].value;
                setColor();
                cout <<" |";
            }
                cout << "             :骰子" << endl;
                cout << "                    +---+---+---+" << "                    " << endl;
                cout << "                    ";

                cout << right << setw(33) << Game::T[1].getGamerName() << endl;
}//输出UI

#endif //TOOLS_PUT_H
