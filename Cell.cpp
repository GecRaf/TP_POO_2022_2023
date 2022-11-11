//
// Created by Rafac on 09/11/2022.
//

#include "Cell.h"

using std::cout;
using std::endl;

Cell::Cell(int areaLin, int areaCol) {
    this->areaLin = areaLin;
    this->areaCol = areaCol;
    this->animal = nullptr;
    this->food = nullptr;
}

void Cell::getAnimal() {

}

void Cell::setAnimal(Animais* a) {
    //cout << "Animal " << a.getSpecie() << " added to the cell" << endl;
    this->animal = a;
}

void Cell::getAnimalSpecie() {

}

vector<Alimentos> Cell::getFood() {
    return vector<Alimentos>();
}

void Cell::addFood(Alimentos) {

}

Cell::~Cell() {

}
