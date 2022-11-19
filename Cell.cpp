//
// Created by Rafac on 09/11/2022.
//

#include "Cell.h"

using std::cout;
using std::vector;
using std::endl;

Cell::Cell(int areaLin, int areaCol) {
    this->areaLin = areaLin;
    this->areaCol = areaCol;
    this->animal = nullptr;
    this->food = nullptr;
}

void Cell::getFood() {

}

void Cell::setAnimal(Animais* a) {
    //cout << "Animal " << a.getSpecie() << " added to the cell" << endl;
    //this->animais = a;
}

void Cell::getAnimalSpecie() {

}

vector<Animais> Cell::getAnimais() {
    return vector<Animais>();
}

void Cell::setFood(Alimentos) {

}

Cell::~Cell() {

}

string Cell::getInfo() {
    return std::string();
}
