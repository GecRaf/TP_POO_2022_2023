//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "Headers/Interface.h"
#include "Terminal/Terminal.h"
#include "curses.h"


using namespace term;

int main() {
    Terminal &t = Terminal::instance();
    Interface::initInterface();
    return 0;
}

