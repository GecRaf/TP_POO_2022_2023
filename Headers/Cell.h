//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

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
    void setAnimal(string specie, int instant, int id);
    string getFoodString(Cell *c);
    void setFood(string type, int id);
    ~Cell();
    string getAnimais(Cell *c);
    const vector<Animais *> &getAnimals() const;
    Alimentos *getFood() const;
};


#endif //TPPOO2223_CELL_H
