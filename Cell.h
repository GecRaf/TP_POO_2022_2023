
#ifndef TPPOO2223_CELL_H
#define TPPOO2223_CELL_H

#include "Utils.h"
#include "Animais.h"
#include "Alimentos.h"

class Cell {
private:
    int Lin, Col;
    vector<Animais*> animais;
    Alimentos* food;
public:
    Cell(int Lin, int Col);
    static string getInfo(Cell *c);
    void getAnimalSpecie();
    void setAnimal(string specie);
    string getFood(Cell *c);
    void setFood(string type);
    int test = 3;
    ~Cell();
    string getAnimais(Cell *c);
};


#endif //TPPOO2223_CELL_H
