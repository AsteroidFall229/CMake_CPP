//
// Created by AsteroidFall229 on 2025/8/3.
//

#ifndef BOX_H
#define BOX_H

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>
#include <condition_variable>
#include <vector>
#include <windows.h>
#include <conio.h>

enum class color : uint8_t {
    black =     0,   // 黑色 - 文字和背景都可用
    blue =      1,   // 蓝色 - 文字和背景都可用
    green =     2,   // 绿色 - 文字和背景都可用
    cyan =      3,   // 青色 - 文字和背景都可用
    red =       4,   // 红色 - 文字和背景都可用
    magenta =   5,   // 洋红 - 文字和背景都可用
    yello =     6,   // 黄色 - 文字和背景都可用
    l_gray =    7,   // 浅灰 - 文字和背景都可用
    // 以下颜色主要用作文字色，背景色可能显示异常
    d_gray =    8,   // 深灰色 - 主要用作文字色
    l_blue =    9,   // 亮蓝色 - 主要用作文字色
    l_green =   10,  // 亮绿色 - 主要用作文字色
    l_cyan =    11,  // 亮青色 - 主要用作文字色
    l_red =     12,  // 亮红色 - 主要用作文字色
    l_magenta = 13,  // 亮洋红 - 主要用作文字色
    l_yellow =  14,  // 亮黄色 - 主要用作文字色
    white =     15,  // 白色色 - 主要用作文字色
};
enum class AorD : uint8_t {
    left = 0,
    right = 1
};

namespace stdio {
    using std::cout;
    using std::endl;
    using std::cin;
    using std::left;
    using std::right;
    using std::setw;
}
namespace tools {
    inline void sleep(const int& ms) {std::this_thread::sleep_for(std::chrono::milliseconds(ms));}
    inline void cls() {system("cls");}
    static void windowSize(int width, int height);
    void initConsole();
    void setColor(const color &font = color::white, const color &background = color::black);
    void PLU(const int&,const color&,const color&);
    void put_last();
    void put();
    inline void slept(const int& ms){put();sleep(ms);}
}

namespace CLASS {
    class Random {
    private:
        std::random_device rd;
        std::mt19937 engine;
        std::uniform_int_distribution<int> dist;
        std::array<int, 6> history;
        int history_index;
        std::array<int, 7> count;
        const int history_size = 6;
    public:
        Random();
        Random& operator=(const Random&) = delete;
        int r();
        void reset_history();
        operator int();
    };
    class Alt {
    private:
        bool alt_b;
    public:
        explicit Alt(bool al=true) : alt_b(al) {}
        int x() { return ((alt_b = !alt_b)) ? 1 : 0; }//交替&使用
        operator int() const { return alt_b ? 1 : 0; }//使用
    };
    class Table {
        class List {
        public:
            struct Unit {
                int value {0};
                color color{color::white};
            };
            Unit unit[3];
            color bg_color{color::black};
            List();
            [[nodiscard]] bool isFull() const{return unit[0].value != 0 && unit[1].value != 0 && unit[2].value != 0;}
            void flushFontColor();
            void deleteValue(int);
            void inputValue(int);
            [[nodiscard]] int getScore() const;
            const Unit& operator[](int i) const {return unit[i];}
            Unit& operator[](int i) {return unit[i];}
        };
        List list[3];
        std::string gamer_name;
    public:
        color bg_use{color::white};
        color font_bg_use{color::black};
        int random{0};
        void setGamerName(const std::string& name) {gamer_name = name;}
        [[nodiscard]] const std::string& getGamerName() const {return gamer_name;}
        [[nodiscard]] bool allFull();

        [[nodiscard]]bool inputValue(Table&);
        void set_Color(AorD);
        void set_Color();

        explicit Table(std::string g="Player") : gamer_name(std::move(g)) {}

        const List& operator[](int i) const {return list[i];}
        List& operator[](int i) {return list[i];}

        [[nodiscard]] int getScore(const int i) const {return list[i].getScore();}
        [[nodiscard]] int getScore() const {return list[0].getScore()+list[1].getScore()+list[2].getScore();}
    };
}

namespace Game {
    inline CLASS::Random random;
    inline CLASS::Alt alt;
    inline CLASS::Table T[2];
    inline std::string gamer_name{"DeBug"};
    void ESC();
    void switch_process();
}

#endif
