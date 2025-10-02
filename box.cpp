//
// Created by AsteroidFall229 on 2025/8/3.
//

#include "box.h"

//tools
void tools::initConsole() {
    // 设置控制台输出编码为UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // 设置控制台输入编码为UTF-8（可选）
    SetConsoleCP(CP_UTF8);

    // 启用虚拟终端处理（支持ANSI转义序列）
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
void tools::setColor(const color &font, const color &background) {
    static uint8_t _font, _bg;
    _font=static_cast<uint8_t>(font);
    _bg=static_cast<uint8_t>(background);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD color_attr = (_bg << 4) | _font;
    SetConsoleTextAttribute(hConsole, color_attr);
}
void tools::windowSize(const int &width, const int &height) {
    HWND hwnd = GetConsoleWindow();
    if (hwnd != nullptr) {
        //SetWindowLong(hwnd, GWL_STYLE,GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME);      // 禁用窗口缩放
        RECT rect;
        GetWindowRect(hwnd, &rect);
        MoveWindow(hwnd, rect.left, rect.top  ,  width * 8, height * 16, TRUE);  // 设置固定尺寸,字符单元格近似计算
    }
}

//CLASS::Random
CLASS::Random::Random()
    : engine(rd()), dist(1, 6), history({0}), history_index(0), count({0}) {
    // 优化预热
    for (int i = 0; i < 10; ++i) {
        engine();
    }
}
int CLASS::Random::r() {
    constexpr int max_attempts = 50;
    int result = 0;

    for (int attempt = 0; attempt < max_attempts; ++attempt) {
        result = dist(engine);

        // O(1) 时间复杂度的检查
        if (count[result] < 2) {
            break;
        }
    }

    // 更新历史记录和计数
    int old_value = history[history_index];
    if (old_value >= 1 && old_value <= 6) {
        count[old_value]--;
    }

    history[history_index] = result;
    history_index = (history_index + 1) % history_size;

    if (result >= 1 && result <= 6) {
        count[result]++;
    }

    return result;
}
void CLASS::Random::reset_history() {
    history.fill(0);
    history_index = 0;
}
CLASS::Random::operator int() {
    return this->r();
}

//CLASS::Table::List
CLASS::Table::List::List () {
    unit[0].value=0;
    unit[1].value=0;
    unit[2].value=0;

    unit[0].color =color::white;
    unit[1].color =color::white;
    unit[2].color =color::white;
}
void CLASS::Table::List::flushFontColor() {

    // 三个相同
    if (unit[0].value == unit[1].value && unit[1].value == unit[2].value && unit[0].value >= 1 && unit[0].value <= 6) {
        unit[0].color = color::cyan;
        unit[1].color = color::cyan;
        unit[2].color = color::cyan;
        return;
    }

    // 前两个相同
    if (unit[0].value == unit[1].value && unit[0].value >= 1 && unit[0].value <= 6) {
        unit[0].color = color::yello;
        unit[1].color = color::yello;
        unit[2].color = color::white;
        return;
    }

    // 第一个和第三个相同
    if (unit[0].value == unit[2].value && unit[0].value >= 1 && unit[0].value <= 6) {
        unit[0].color = color::yello;
        unit[2].color = color::yello;
        unit[1].color = color::white;
        return;
    }

    // 后两个相同
    if (unit[1].value == unit[2].value && unit[1].value >= 1 && unit[1].value <= 6) {
        unit[1].color = color::yello;
        unit[2].color = color::yello;
        unit[0].color = color::white;
        return;
    }

    // 没有相同数字
    unit[0].color = color::white;
    unit[1].color = color::white;
    unit[2].color = color::white;
}
void CLASS::Table::List::deleteValue(const int &del) {
    // 标记要删除的数字
    if (unit[0].value == del) unit[0].color = color::red;
    if (unit[1].value == del) unit[1].color = color::red;
    if (unit[2].value == del) unit[2].color = color::red;

    tools::slept(500);
    //001
    if (unit[0].value == del) {
        unit[0].value = 0;
        unit[0].color = color::white;
        tools::slept(500);
        unit[0].color = unit[1].color;
        unit[0].value = unit[1].value;
        unit[1].value = unit[2].value;
        unit[1].color = unit[2].color;
        unit[2].value = 0;
        unit[2].color = color::white;
        tools::slept(200);
        //-01
        if (unit[0].value == del) {
            unit[0].value = 0;
            unit[0].color = color::white;
            tools::slept(500);
            unit[0].color = unit[1].color;
            unit[0].value = unit[1].value;
            unit[1].value = 0;
            unit[1].color = color::white;
            tools::slept(200);
            //001
            if (unit[0].value == del) {
                unit[0].value = 0;
                unit[0].color = color::white;
                tools::slept(500);
                unit[0].color = unit[1].color;
                unit[0].value = unit[1].value;
                unit[1].value = 0;
                unit[1].color = color::white;
                tools::slept(200);
                return;
            }
            //010
            if (unit[1].value == del) {
                unit[1].value = 0;
                unit[1].color = color::white;
                tools::slept(400);
                return;
            }
        }
        //-10
        if (unit[1].value == del) {
            unit[1].value = 0;
            unit[1].color = color::white;
            tools::slept(400);
        }
    }

    //010
    if (unit[1].value == del) {
        unit[1].value = 0;
        unit[1].color = color::white;
        tools::slept(500);
        unit[1].value = unit[2].value;
        unit[1].color = unit[2].color;
        unit[2].value = 0;
        unit[2].color = color::white;
        tools::slept(200);
        //-10
        if (unit[1].value == del) {
            unit[1].value = 0;
            unit[1].color = color::white;
            tools::slept(400);
            return;
        }
        if (unit[2].value == del) {
            unit[2].value = 0;
            unit[2].color = color::white;
            tools::slept(400);
            return;
        }
    }

    //100
    if (unit[2].value == del) {
        unit[2].value = 0;
        unit[2].color = color::white;
        tools::slept(400);
        return;
    }
}
void CLASS::Table::List::inputValue(const int &ivl) {
    if (isFull()) {
        std::cerr<<"err:isFull,but input";
        return;
    }

    if (unit[0].value == 0) {
        unit[0].value = ivl;
    } else if (unit[1].value == 0) {
        unit[1].value = ivl;
    } else if (unit[2].value == 0) {
        unit[2].value = ivl;
    }

    tools::put();
    flushFontColor();
}
int  CLASS::Table::List::getScore() const {
    if (unit[0].value == unit[1].value && unit[1].value == unit[2].value)
        return unit[0].value * 9;
    if (unit[0].value == unit[1].value)
        return unit[0].value * 4 + unit[2].value;
    if (unit[1].value == unit[2].value)
        return unit[1].value * 4 + unit[0].value;
    if (unit[0].value == unit[2].value)
        return unit[0].value * 4 + unit[1].value;
    return unit[0].value + unit[1].value + unit[2].value;
}

//CLASS::Table
bool CLASS::Table::inputValue(Table& t) {
    if (list[0].bg_color==bg_use) {
        if (list[0].isFull())
            return false;
        set_Color();
        list[0].inputValue(random);
        t.list[0].deleteValue(random);
    }
    if (list[1].bg_color==bg_use) {
        if (list[1].isFull())
            return false;
        set_Color();
        list[1].inputValue(random);
        t.list[1].deleteValue(random);
    }
    if (list[2].bg_color==bg_use) {
        if (list[2].isFull())
            return false;
        set_Color();
        list[2].inputValue(random);
        t.list[2].deleteValue(random);
    }
    return true;
}
void CLASS::Table::set_Color(const AorD lr) {
    if (list[1].bg_color!=color::black) {
        if (lr == AorD::left) {
            list[1].bg_color=color::black,
            list[0].bg_color=bg_use;
            list[1].flushFontColor();
            list[2].flushFontColor();
            list[0][0].color = font_bg_use;
            list[0][1].color = font_bg_use;
            list[0][2].color = font_bg_use;
        }
        if (lr == AorD::right) {
            list[1].bg_color=color::black,
            list[2].bg_color=bg_use;
            list[0].flushFontColor();
            list[1].flushFontColor();
            list[2][0].color = font_bg_use;
            list[2][1].color = font_bg_use;
            list[2][2].color = font_bg_use;
        }
    }
    if (list[0].bg_color!=color::black) {
        if (lr == AorD::right) {
            list[0].bg_color=color::black,
            list[1].bg_color=bg_use;
            list[0].flushFontColor();
            list[2].flushFontColor();
            list[1][0].color = font_bg_use;
            list[1][1].color = font_bg_use;
            list[1][2].color = font_bg_use;
        }
    }
    if (list[2].bg_color!=color::black) {
        if (lr == AorD::left) {
            list[2].bg_color=color::black,
            list[1].bg_color=bg_use;
            list[0].flushFontColor();
            list[2].flushFontColor();
            list[1][0].color = font_bg_use;
            list[1][1].color = font_bg_use;
            list[1][2].color = font_bg_use;
        }
    }
}
void CLASS::Table::set_Color() {
    list[0].bg_color = color::black;
    list[1].bg_color = color::black;
    list[2].bg_color = color::black;
    list[0].flushFontColor();
    list[2].flushFontColor();
}
bool CLASS::Table::allFull() const {
    if (list[0].isFull()&&list[1].isFull()&&list[2].isFull())
        return true;
    return false;
}

//Game
void Game::menu() {
    std::cout<<std::endl<<"敬请期待(bushi"<<std::endl;
    getch();
}
void Game::game_start() {
    T[0].setGamerName("AsteroidFall229");
    T[1].setGamerName("zwx3570");
}
void Game::over() {
    T[0].set_Color();
    T[1].set_Color();
    T[0].random=0;
    T[1].random=0;
    tools::put();
    std::cout<<gamer_name<<"获得最终胜利"<<std::endl;
}

