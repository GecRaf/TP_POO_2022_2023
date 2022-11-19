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
        int Lin, Col;
        vector<Animais*> animais;
        Alimentos* food;
    public:
        Cell(int Lin, int Col);
        string getInfo();
        void getAnimalSpecie();
        vector<Animais> getAnimais();
        void setAnimal(Animais* a);
        void getFood();
        void setFood(Alimentos);
        ~Cell();
};


#endif //TP_POO_2022_2023_CELL_H
