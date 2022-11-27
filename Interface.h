
#ifndef TPPOO2223_INTERFACE_H
#define TPPOO2223_INTERFACE_H
#include "Utils.h"
#include "Reserva.h"
#include "Cell.h"

class Interface {

public:
    static void ASCII();
    static void initInterface();
    static void showMatrix(Reserva &r);
    static void commandReader(Reserva &r, string fileCommand = "");
};


#endif //TPPOO2223_INTERFACE_H