#include "box.h"

using namespace stdio;

CLASS::Random ran;
//CLASS::Alt alt;

int main() {
    tools::initConsole();
    //tools::setColor(color::red,color::cyan);
    for (int i = 1; i <= 100; i++) {
        cout << ran << "\n" ;
    }
    tools::sleep(500);
    //tools::cls();
    Game::T[0][0].flushFontColor();
    tools::put();
    Game::switch_process();
    return 0;
}
