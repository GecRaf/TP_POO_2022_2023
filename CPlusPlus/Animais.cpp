//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Animais.h"
#include "../Terminal/Terminal.h"

using namespace term;

Animais::Animais(Animais &a) : id(a.id), vida(a.vida), peso(a.peso), especie(a.especie), saude(a.saude), fome(a.fome), vivo(a.vivo){}

bool Animais::FicaVivo(int simulatedTime) {
    if (getEspecie() == "C"){
        if(getSaude() == 0 || simulatedTime - birthInstant  == 30){
            setVida(0);
            return false;
        }
    }
    else if(getEspecie() == "O"){
        if (getSaude() == 0 || simulatedTime - birthInstant== 35){
            setVida(0);
            return false;
        }
    }
    else if(getEspecie() == "L"){
        if (getSaude() == 0){
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
        if(getSaude() == 0){
            setVida(0);
            return false;
        }
    }
    return true;
}

void Animais::setVida(int vida) {
    Animais::vida = vida;
}

void Animais::setSaude(int saude) {
    if(saude > 100)
        saude = 100;
    if(saude < 0){
        saude = 0;

    }
    Animais::saude = saude;
}

void Animais::setFome(int fome) {
    if(fome < 0)
        fome = 0;
    Animais::fome = fome;
}

void Animais::setPeso(float peso) {
    Animais::peso = peso;
}

void Animais::addFoodHistory(Alimentos *food) {
    Alimentos* tmp = new Alimentos(food);

    // Cast for realloc is necessary because realloc doesn't really know what type of pointer it is that is redimensioning
    Alimentos* aux = (reinterpret_cast<Alimentos *>(std::realloc(foodHistory, sizeof(Alimentos) * (foodHistorySize + 1))));
    if(aux != nullptr){
        foodHistory = aux; // Buttlet proof typa shit
        foodHistorySize++;
        foodHistory[foodHistorySize-1] = tmp;
    }
}

int Animais::getBirthInstant() const {
    return birthInstant;
}

int Animais::getId() const {
    return id;
}

string Animais::getInfo() {
    string info;
    info += "\t\t[~] ID: " + to_string(getId()) + "\n";
    info += "\t[~] Specie: " + especie + "\n";
    info += "\t[~] Weight: " + to_string(peso) + "\n";
    info += "\t[~] Health: " + to_string(saude) + "\n",
    info += "\t[~] Life: " + to_string(vida) + "\n";
    info += "\t[~] Hunger: " + to_string(fome) + "\n";
    //Display food history
    if(foodHistory != nullptr){
        info += "\t[~] Food History: ";
        for(int i = 0; i < foodHistorySize; i++){
            info += foodHistory[i].getNome() + " ";
        }
        info += "\n";
    }
    return info;
}

void Animais::feed(int idFood,string foodType, int nutritionPoints, int toxicityPoints){
    Alimentos* tmp = new Alimentos(idFood, foodType, 30, nutritionPoints, toxicityPoints, "User");
    addFoodHistory(tmp);
    setSaude(getSaude() + nutritionPoints - toxicityPoints);
    setFome(getFome() - nutritionPoints);
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

int Animais::getMotherID() const {
    return 0;
}

bool Animais::getInvisible() const {
    return false;
}

bool Animais::getHasChild()const{
    return false;
}
void Animais::setChildBd(int childBd){

}
int Animais::getChildBd() const {
    return 0;
}

void Animais::setInvisible(bool invisible) {

}

int Animais::getInvisibleTime() const {
    return 0;
}

void Animais::setInvisibleTime(int invisibleTime) {

}
