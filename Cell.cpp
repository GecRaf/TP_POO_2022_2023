
#include "Cell.h"
#include "Terminal.h"

using namespace term;

Terminal &t = Terminal::instance();

Cell::Cell(int Lin, int Col) {
    this->Lin = Lin;
    this->Col = Col;
    this->food = nullptr;
}

void Cell::setAnimal(string specie) {
    this->animais.push_back(new Animais(specie,1,1,1,1));
}

void Cell::setFood(string type) {
    this->food = new Alimentos(type,1,1,1,"comida");
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
            if(i < 3)
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
        return info = "Empty\n";
    }
    for (int i = 0; i < animais.size(); i++) {
        info += "\t\t[~] Specie: " + animais[i]->getEspecie() + "\n";
        info += "\t[~] Weight" + to_string(animais[i]->getPeso()) + "\n";
        info += "\t[~] Health: " + to_string(animais[i]->getSaude()) + "\n",
        info += "\t[~] Life: " + to_string(animais[i]->getSaude()) + "\n";
        info += "\t[~] Hunger: " + to_string(animais[i]->getFome()) + "\n";
    }
    return info;
}

string Cell::getFood(Cell *c) {
    string info;
    if(c->food != nullptr) {
        info += "\t\t[~] Name: " + food->getNome() + "\n";
        info += "\t[~] Duration: " + to_string(food->getDuracao()) + "\n";
        info += "\t[~] Nutritional value: " + to_string(food->getValorNutritivo()) + "\n";
        info += "\t[~] Toxicity: " + to_string(food->getToxicidade()) + "\n";
        info += "\t[~] Smell: " + food->getCheiro() + "\n";
    }else{
        return info += "Empty\n";
    }
    return info;
}