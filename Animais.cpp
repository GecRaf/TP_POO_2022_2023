//
// Created by Rafael Couto on 06/11/2022.
//

#include "Animais.h"

bool Animais::vivo(int saude)
{
    if(saude > 0)
        return true;
    return false;
}
int Animais::getId() {
    return id++;
}
void Animais::aumentaFome(int fome) {

}

void Animais::diminuiFome(int fome) {

}
void Animais::aumentaSaude(int saude) {

}
void Animais::diminuiSaude(int saude) {

}
