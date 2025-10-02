#include "box.h"

using namespace stdio;

CLASS::Random ran;
//CLASS::Alt alt;

int main() {
    tools::initConsole();
    Game::game_start();
    Game::switch_process();
    Game::over();
    getch();
    return 0;
}
