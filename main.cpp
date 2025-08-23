#include "box.h"

using namespace stdio;

//CLASS::Random ran;
CLASS::Alt alt;

int main() {
    for (int i = 1; i <= 100; i++) {
        cout<<alt.x()<<"\n";
    }
    tools::sleep(1500);
    tools::cls();
    getch();
    return 0;
}
