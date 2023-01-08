//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Cell.h"
#include "../Terminal/Terminal.h"

using namespace term;

Terminal &t = Terminal::instance();

Cell::Cell(int Lin, int Col) {
    this->Lin = Lin;
    this->Col = Col;
    this->food = nullptr;
}

void Cell::setAnimal(string specie, int instant, int id, int saude, int vida, int fome, float peso) {
    if(specie == "c"){
        if(saude != 0 && fome != 0 && vida != 0 && peso != 0.0){
            animais.push_back(new Coelho(instant, id, saude, vida, fome, peso));
        }
        else{
            animais.push_back(new Coelho(id,instant));
        }
    }else if(specie == "o"){
        if(saude != 0 && fome != 0 && vida != 0 && peso != 0.0){
            animais.push_back(new Ovelha(instant, id, saude, vida, fome, peso));
        }
        else{
            animais.push_back(new Ovelha(id,instant));
        }
    }else if(specie == "l") {
        if(saude != 0 && fome != 0 && vida != 0 && peso != 0.0){
            animais.push_back(new Lobo(instant, id, saude, vida, fome, peso));
        }
        else{
            animais.push_back(new Lobo(id,instant));
        }
    }else if(specie == "g") {
        if(saude != 0 && fome != 0 && vida != 0 && peso != 0.0){
            animais.push_back(new Canguru(instant, id, saude, vida, fome, peso));
        }
        else{
            animais.push_back(new Canguru(id,instant));
        }
    }else if(specie == "m"){
        if(saude != 0 && fome != 0 && vida != 0 && peso != 0.0){
            animais.push_back(new Preguica(instant, id, saude, vida, fome, peso));
        }
        else{
            animais.push_back(new Preguica(id,instant));
        }
    }
}

void Cell::copyNewAnimal(Animais *a) {
    animais.push_back(a);
}

void Cell::removeAllEntities() {
    animais.clear();
    food = nullptr;
}

void Cell::setFood(string type, int id) {
    if(type == "r"){
        this->food = new Relva(id);
    }else if(type == "t"){
        this->food = new Cenoura(id,0);
    }else if(type == "p"){
        this->food = new Corpo(id,0,30);
    }else if(type == "b"){
        this->food = new Bife(id);
    }else if(type == "f"){
        this->food = new Fruta(id);
    }else if(type == "none"){
        this->food = nullptr;
    }
}

Cell::~Cell() {

}

string Cell::getInfo(Cell *c) {
    //Return the info of the cell
    string coords = " C:";
    string animals = " A:";
    string food = " F:";

    coords += "(" + to_string(c->Lin) + "," + to_string(c->Col) + ")";
    if(c->animais.size() == 0){
        animals += "Empty";
    }else{
        for (int i = 0; i < c->animais.size(); i++) {
            if(i < 3 && !c->animais[i]->getInvisible())
                animals += c->animais[i]->getEspecie();
        }
        if(c->animais.size() > 3){
            animals += "+";
        }
        if(animals.length() < 8){
            for(int i = animals.length(); i < 8; i++){
                animals += "-";
            }
        }
    }
    if (c->food != nullptr) {
        food += c->food->getNome();
        if(food.length() < 8){
            for(int i = food.length(); i < 8; i++){
                food += "-";
            }
        }
    }else{
        food += "Empty";
    }
    string info = coords + animals + food;
    info += "\n";

    return info;
}

string Cell::getAnimais(Cell *c){
    string info;
    if(c->animais.size() == 0) {
        return info = "\t[~] Empty";
    }
    for (int i = 0; i < animais.size(); i++) {
        info += "\t\t[~] ID: " + to_string(animais[i]->getId()) + "\n";
        info += "\t[~] Specie: " + animais[i]->getEspecie() + "\n";
        info += "\t[~] Weight: " + to_string(animais[i]->getPeso()) + "\n";
        info += "\t[~] Health: " + to_string(animais[i]->getSaude()) + "\n",
        info += "\t[~] Life: " + to_string(animais[i]->getSaude()) + "\n";
        info += "\t[~] Hunger: " + to_string(animais[i]->getFome()) + "\n";
    }
    return info;
}

string Cell::getFoodString(Cell *c) {
    string info;
    if(c->food != nullptr) {
        info += "\t\t[~] ID: " + to_string(c->food->getId()) + "\n";
        info += "\t[~] Name: " + food->getNome() + "\n";
        info += "\t[~] Duration: " + to_string(food->getDuracao()) + "\n";
        info += "\t[~] Nutritional value: " + to_string(food->getValorNutritivo()) + "\n";
        info += "\t[~] Toxicity: " + to_string(food->getToxicidade()) + "\n";
        // Iterate through the food smell array
        info += "\t[~] Smell: " + food->getCheiro() + "\n";
    }else{
        return info += "\t[~] Empty\n";
    }
    return info;
}

const vector<Animais *> &Cell::getAnimals() const {
    return animais;
}

Alimentos *Cell::getFood() {
    return food;
}

void Cell::removeAnimal(int id) {
    for (int i = 0; i < animais.size(); i++) {
        if(animais[i]->getId() == id){
            animais.erase(animais.begin() + i);
        }
    }
}

void Cell::adicionaRelva(int id) {
   this->food = new Relva(id);
}