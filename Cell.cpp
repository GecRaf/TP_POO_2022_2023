//
// Created by Rafac on 09/11/2022.
//

#include "Cell.h"

using std::cout;
using std::endl;

void Cell::setAnimal(Animais* a) {
    //cout << "Animal " << a.getSpecie() << " added to the cell" << endl;
    this->animal = a;
}
