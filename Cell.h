//
// Created by Rafac on 09/11/2022.
//

#ifndef TP_POO_2022_2023_CELL_H
#define TP_POO_2022_2023_CELL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Animais.h"
#include "Alimentos.h"
#include "Reserva.h"

class Reserva;

class Cell {
    private:
        int areaLin;
        int areaCol;
        Animais* animal;
        Alimentos* food;
    public:
        Cell(int areaLin, int areaCol);
        void getAnimal();
        void getAnimalSpecie();
        vector<Alimentos> getFood();
        void setAnimal(Animais* a);
        void addFood(Alimentos);
        ~Cell();
};


#endif //TP_POO_2022_2023_CELL_H
