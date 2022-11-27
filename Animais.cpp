#include "Animais.h"

bool Animais::vivo() {
  if(getSaude() < 0)
      return false;
  return true;
}

void Animais::aumentaFome() {}
void Animais::diminuiFome() {}
void Animais::aumentaSaude() {}
void Animais::diminuiSaude() {}

void Animais::setVida(int vida) {
    Animais::vida = vida;
}

void Animais::setSaude(int saude) {
    Animais::saude = saude;
}

void Animais::setFome(int fome) {
    Animais::fome = fome;
}

void Animais::setPeso(float peso) {
    Animais::peso = peso;
}

