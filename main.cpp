#include "Interface.h"
#include "Terminal.h"
#include "curses.h"


using namespace term;

int main() {
    Terminal &t = Terminal::instance();
    auto hwnd = t.create_window(0, 0, 80, 25, false);
    Interface::initInterface();
    return 0;
}

