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
void tools::setColor(const int font, const int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD color_attr = (bg << 4) | font;
    SetConsoleTextAttribute(hConsole, color_attr);
}
void tools::windowSize(int width, int height) {
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
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
    int result;

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
    unit[0].font =color::white;
    unit[1].font =color::white;
    unit[2].font =color::white;
}
void CLASS::Table::List::flushFontColor() {

    // 三个相同
    if (unit[0].value == unit[1].value && unit[1].value == unit[2].value && unit[0].value >= 1 && unit[0].value <= 6) {
        unit[0].font = color::cyan;
        unit[1].font = color::cyan;
        unit[2].font = color::cyan;
        return;
    }

    // 前两个相同
    if (unit[0].value == unit[1].value && unit[0].value >= 1 && unit[0].value <= 6) {
        unit[0].font = color::yello;
        unit[1].font = color::yello;
        unit[2].font = color::white;
        return;
    }

    // 第一个和第三个相同
    if (unit[0].value == unit[2].value && unit[0].value >= 1 && unit[0].value <= 6) {
        unit[0].font = color::yello;
        unit[2].font = color::yello;
        unit[1].font = color::white;
        return;
    }

    // 后两个相同
    if (unit[1].value == unit[2].value && unit[1].value >= 1 && unit[1].value <= 6) {
        unit[1].font = color::yello;
        unit[2].font = color::yello;
        unit[0].font = color::white;
        return;
    }

    // 没有相同数字
    unit[0].font = color::white;
    unit[1].font = color::white;
    unit[2].font = color::white;
}
void CLASS::Table::List::deleteValue(const int dvl) {
    // 标记要删除的数字
    if (unit[0].value == dvl) unit[0].font = color::red;
    if (unit[1].value == dvl) unit[1].font = color::red;
    if (unit[2].value == dvl) unit[2].font = color::red;

    tools::put();
    tools::slept(200);

    // 处理第一个位置的删除
    if (unit[0].value == dvl) {
        unit[0].value = 0;
        unit[0].font = color::white;
        tools::put();
        tools::slept(200);

        // 下移后面的数字
        unit[0].value = unit[1].value;
        unit[0].font = unit[1].font;
        unit[1].value = unit[2].value;
        unit[1].font = unit[2].font;
        unit[2].value = 0;
        unit[2].font = color::white;

        tools::put();
        tools::slept(200);

        // 检查是否还有需要删除的（现在可能在新的位置）
        if (unit[0].value == dvl || unit[1].value == dvl) {
            deleteValue(dvl);  // 递归处理剩余的数字
        }
        return;
    }

    // 处理第二个位置的删除
    if (unit[1].value == dvl) {
        unit[1].value = 0;
        unit[1].font = color::white;
        tools::put();
        tools::slept(200);

        // 下移后面的数字
        unit[1].value = unit[2].value;
        unit[1].font = unit[2].font;
        unit[2].value = 0;
        unit[2].font = color::white;

        tools::put();
        tools::slept(200);

        // 检查第一个位置是否变成要删除的数字
        if (unit[0].value == dvl) {
            deleteValue(dvl);  // 递归处理
        }
        return;
    }

    // 处理第三个位置的删除
    if (unit[2].value == dvl) {
        unit[2].value = 0;
        unit[2].font  = color::white;
        tools::put();
        tools::slept(200);
        return;
    }
}
void CLASS::Table::List::inputValue(const int ivl) {
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
