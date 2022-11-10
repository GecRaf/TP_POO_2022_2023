//
// Created by Rafael Couto on 06/11/2022.
//

#ifndef TP_POO_2022_2023_RESERVA_H
#define TP_POO_2022_2023_RESERVA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include "Cell.h"

class Reserva {
    private:
        int NL, NC;
        int areaLinMax, areaLinMin, areaColMax, areaColMin;
        //vector< vector<Cell*>> areaTotal;
    public:
        Reserva(); // Default constructor, applies predefined size
        Reserva(int NL, int NC);
        void commandReader();
        void initMatrix(int NL, int NC);
        //Cell* getCell(int x, int y);
        //void setCell(int x, int y, Cell* c);
};


#endif //TP_POO_2022_2023_RESERVA_H
