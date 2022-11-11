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
        vector<Reserva *> reservas; // Vector to store game states
    public:
        Reserva(); // Default constructor, applies predefined size
        Reserva(int Id=0):id(Id){}
        Reserva(Reserva *Reserva); // Copy constructor
        Reserva(int NL, int NC, string filename); // Constructor with size and filename
        int getId(){id++; return id;}
        void commandReader(string fileCommand);
        ~Reserva(); // Destructor
};


#endif //TP_POO_2022_2023_RESERVA_H
