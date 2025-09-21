//
// Created by AsteroidFall229 on 2025/8/23.
//

#ifndef TOOLS_PUT_H
#define TOOLS_PUT_H

#include "box.h"

void tools::PLU(const int& value,const color& font, const color& background) {
    std::cout << " ";
    setColor(font,background);
    if (value==0)    std::cout <<" ";
    else             std::cout <<value;
    setColor();
    std::cout <<" |";
}

void tools::put_last() {
    system("cls");

    std::cout << std::left << std::setw(20) << Game::T[0].getGamerName()<<"\n";

    std::cout << "                    +---+---+---+\n";
    std::cout << "  骰子:             |";

    PLU(Game::T[0][0][2].value,Game::T[0][0][2].color, Game::T[0][0].bg_color);
    PLU(Game::T[0][1][2].value,Game::T[0][1][2].color, Game::T[0][1].bg_color);
    PLU(Game::T[0][2][2].value,Game::T[0][2][2].color, Game::T[0][2].bg_color);

    std::cout <<"\n      +---+         +---+---+---+\n";
    std::cout << "      | ";
    if (Game::T[0].random == 0) std::cout << " ";
    else                        std::cout << Game::T[0].random;
    std::cout << " |         |";

    PLU(Game::T[0][0][1].value==0, Game::T[0][0][1].color, Game::T[0][0].bg_color);
    PLU(Game::T[0][1][1].value==0, Game::T[0][1][1].color, Game::T[0][1].bg_color);
    PLU(Game::T[0][2][1].value==0, Game::T[0][2][1].color, Game::T[0][2].bg_color);

    std::cout <<"\n      +---+         +---+---+---+\n";
    std::cout << "                    |";

    PLU(Game::T[0][0][0].value==0, Game::T[0][0][0].color, Game::T[0][0].bg_color);
    PLU(Game::T[0][1][0].value==0, Game::T[0][1][0].color, Game::T[0][1].bg_color);
    PLU(Game::T[0][2][0].value==0, Game::T[0][2][0].color, Game::T[0][2].bg_color);

    std::cout << "\n                  =================" << "    总分:" << Game::T[0].getScore() <<"\n";
    std::cout << "                    ";

    std::cout << std::right << std::setw(3) << Game::T[0][0].getScore() << " ";
    std::cout << std::right << std::setw(3) << Game::T[0][1].getScore() << " ";
    std::cout << std::right << std::setw(3) << Game::T[0][2].getScore() << " ";

    std::cout << "\n\n";
    std::cout << "                    ";

    std::cout << std::right << std::setw(3) << Game::T[1][0].getScore() << " ";
    std::cout << std::right << std::setw(3) << Game::T[1][1].getScore() << " ";
    std::cout << std::right << std::setw(3) << Game::T[1][2].getScore() << " ";

    std::cout <<"\n                  =================" << "    总分:" << Game::T[1].getScore() << "\n";
    std::cout << std::left << std::setw(20) <<"当前分数最高玩家:"<< "   |";

    PLU(Game::T[1][0][0].value==0, Game::T[1][0][0].color, Game::T[1][0].bg_color);
    PLU(Game::T[1][1][0].value==0, Game::T[1][1][0].color, Game::T[1][1].bg_color);
    PLU(Game::T[1][2][0].value==0, Game::T[1][2][0].color, Game::T[1][2].bg_color);

    std::cout << "\n";
    std::cout << std::left << std::setw(20) << Game::gamer_name;
    std::cout << "+---+---+---+         +---+\n";
    std::cout << "                    |";

    PLU(Game::T[1][0][1].value==0, Game::T[1][0][1].color, Game::T[1][0].bg_color);
    PLU(Game::T[1][1][1].value==0, Game::T[1][1][1].color, Game::T[1][1].bg_color);
    PLU(Game::T[1][2][1].value==0, Game::T[1][2][1].color, Game::T[1][2].bg_color);

    std::cout << "         | ";
    if(Game::T[1].random == 0) std::cout << " ";
    else std::cout << Game::T[1].random;
    std::cout << " |\n";

    std::cout << "最高分/分差         +---+---+---+         +---+\n ";

    std::cout << std::right << std::setw(4) << std::max(Game::T[0].getScore(), Game::T[1].getScore())
         << "/"
         << std::left << std::setw(4) << abs(Game::T[0].getScore() - Game::T[1].getScore());
    std::cout << "          |" ;

    PLU(Game::T[1][0][2].value,Game::T[1][0][2].color, Game::T[1][0].bg_color);
    PLU(Game::T[1][1][2].value,Game::T[1][1][2].color, Game::T[1][1].bg_color);
    PLU(Game::T[1][2][2].value,Game::T[1][2][2].color, Game::T[1][2].bg_color);

    std::cout << "             :骰子\n";
    std::cout << "                    +---+---+---+" << "                    \n";
    std::cout << "                    ";

    std::cout << std::right << std::setw(33) << Game::T[1].getGamerName() <<"\n";
}

void tools::put() {
    using namespace stdio;
    cls();

    cout << left << setw(20) << Game::T[0].getGamerName();

    cout << "\n                    +---+---+---+\n";
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

    cout << "\n      +---+         +---+---+---+\n";
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

    cout << "\n      +---+         +---+---+---+\n";
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

        cout <<"\n"<< left << setw(20) << Game::gamer_name;
        cout << "+---+---+---+         +---+\n";
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
            cout << " |\n";

            cout << "最高分/分差         +---+---+---+         +---+\n ";
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
                cout << "             :骰子\n";
                cout << "                    +---+---+---+" << "                    \n";
                cout << "                    ";

                cout << right << setw(33) << Game::T[1].getGamerName()<<endl;
}//输出UI

#endif //TOOLS_PUT_H
