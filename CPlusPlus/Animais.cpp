//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Animais.h"

Animais::Animais(Animais &a) : id(a.id), vida(a.vida), peso(a.peso), especie(a.especie), saude(a.saude), fome(a.fome), vivo(a.vivo){}

bool Animais::FicaVivo(int simulatedTime) {
    if (getEspecie() == "C"){
        if(getSaude()<=0 || birthInstant - simulatedTime == 30){
            setVida(0);
            return false;
        }
    }
    else if(getEspecie() == "O"){
        if (getSaude() <= 0 || birthInstant - simulatedTime == 35){
            setVida(0);
            return false;
        }
    }
    else if(getEspecie() == "L"){
        if (getSaude() <= 0){
            setVida(0);
            return false;
        }
    }
    else if(getEspecie() == "G"){
        if (getVida() == 70){
            setVida(0);
            return false;
        }
    }
    else if(getEspecie() =="P"){
        if(getSaude() <= 0){
            setVida(0);
            return false;
        }
    }
    return true;
}

void Animais::aumentaFome(int simulatedTime) {
    if (getEspecie() == "C"){
        if(simulatedTime+1){
            setFome(getFome()+1);
        }
    }
    else if(getEspecie() == "O"){
        if(simulatedTime + 1){
            setFome(getFome()+1);
        }
    }
    else if(getEspecie() == "L"){
        if(simulatedTime + 1){
            setFome(getFome()+2);
        }
    }
}

void Animais::aumentaSaude() {}

void Animais::diminuiSaude(int simulatedTime) {
    if (getEspecie() == "C"){
        if(getFome() > 10){
            setSaude(getSaude() - 1);
        }
        else if(getFome() > 20){
            setSaude(getSaude() - 2);
        }
    }
    else if (getEspecie() == "O"){
        if(getFome() > 15){
            setSaude(getSaude() - 1);
        }
        else if(getFome() > 20){
            setSaude(getSaude() - 2);
        }
    }
    else if (getEspecie() == "L"){
        if(getFome() > 15){
            setSaude(getSaude() - 1);
        }
        else if(getFome() > 25){
            setSaude(getSaude() - 2);
        }
    }
    else if(getEspecie() == "G"){
        if (!FicaVivo(simulatedTime)){
            setSaude(0);
        }
    }
}

void Animais::aumentaPeso(int simulatedTime) {
    if(getEspecie() == "G"){
        if (simulatedTime >= 20)
            setPeso(20);
    }
}

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

void Animais::addFoodHistory(Alimentos &food) {
    Alimentos* tmp = new Alimentos(food);
    if(::realloc(foodHistory, sizeof(Alimentos)*foodHistorySize+1) != nullptr){
        foodHistorySize++;
        foodHistory[foodHistorySize-1] = *tmp;
    }
    //TODO: Test this later
}

int Animais::getBirthInstant() const {
    return birthInstant;
}

int Animais::getId() const {
    return id;
}

string Animais::getInfo() {
    string info;
    info += "\t\t[~] Specie: " + especie + "\n";
    info += "\t[~] Weight" + to_string(peso) + "\n";
    info += "\t[~] Health: " + to_string(saude) + "\n",
    info += "\t[~] Life: " + to_string(vida) + "\n";
    info += "\t[~] Hunger: " + to_string(fome) + "\n";
    return info;
}

void Animais::feed(int id,string foodType, int nutritionPoints, int toxicityPoints){
    Alimentos* tmp = new Alimentos(id, foodType, 30, nutritionPoints, toxicityPoints, "User");
    addFoodHistory(*tmp);
    setSaude(getSaude() + nutritionPoints - toxicityPoints);
    setFome(getFome() - nutritionPoints);
    // TODO: Test this later
}

void Animais::setVivo(bool Vivo) {
    Animais::vivo = Vivo;

}

int Animais::getPerception() const {
    return perception;
}

void Animais::setPerception(int perception) {
    Animais::perception = perception;
}

int Animais::getSpeed() const {
    return speed;
}

void Animais::setSpeed(int speed) {
    Animais::speed = speed;
}
