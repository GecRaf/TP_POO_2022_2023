//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Reserva.h"
#include "../Terminal/Terminal.h"

using namespace term;


Reserva::Reserva(int nLin, int nCol, string filename) {
    Terminal &t = Terminal::instance();
    NL = nLin;
    NC = nCol;
    vector<Cell*> tmp;

    for (int i = 0; i < NL; i++) {
        for (int j = 0; j < NC; j++) {
            tmp.push_back(new Cell(i, j));
        }
        area.push_back(tmp);
        tmp.clear();
    }

    if (!filename.empty()) {
        ifstream readData;
        string aux;
        Animais *a;

        readData.open(filename);
        while(getline(readData,aux)){

            istringstream iss(aux);
            t << "\nAUX: " << aux << "\n";
            int iAux;
            float fAux;
            string specie;
            iss >> specie;
            t << "SPECIE: " << specie << "\n";
            if(specie[0] == 'S'){
                if(specie == "SCoelho"){
                    iss >> iAux;
                    // TODO: Apply default health value for Coelho
                    t << "iAux SCoelho: " << iAux << "\n";
                }else if(specie == "SOvelha"){
                    iss >> iAux;
                    // TODO: Apply default health value for Ovelha
                    t << "iAux SOvelha: " << iAux << "\n";
                }else if(specie == "SLobo"){
                    iss >> iAux;
                    // TODO: Apply default health value for Lobo
                    t << "iAux SLobo: " << iAux << "\n";
                }else if(specie == "SCaranguejo"){
                    iss >> iAux;
                    // TODO: Apply default health value for Canguru
                    t << "iAux SCanguru: " << iAux << "\n";
                }else if(specie == "SPreguica"){
                    iss >> iAux;
                    // TODO: Apply default health value for Preguica
                    t << "iAux SPreguica: " << iAux << "\n";
                }
            }
            else if(specie[0] == 'V') {
                if(specie == "VCoelho"){
                    iss >> iAux;
                    // TODO: Apply default life value for Coelho
                    t << "iAux VCoelho: " << iAux << "\n";
                }else if(specie == "VOvelha"){
                    iss >> iAux;
                    // TODO: Apply default life value for Ovelha
                    t << "iAux VOvelha: " << iAux << "\n";
                }else if(specie == "VLobo"){
                    iss >> iAux;
                    // TODO: Apply default life value for Lobo
                    t << "iAux VLobo: " << iAux << "\n";
                }else if(specie == "VCaranguejo"){
                    iss >> iAux;
                    // TODO: Apply default life value for Canguru
                    t << "iAux VCanguru: " << iAux << "\n";
                }else if(specie == "VPreguica"){
                    iss >> iAux;
                    // TODO: Apply default life value for Preguica
                    t << "iAux VPreguica: " << iAux << "\n";
                }
            }
            else if(specie[0] == 'F') {
                if(specie == "FCoelho"){
                    iss >> iAux;
                    // TODO: Apply default hunger value for Coelho
                    t << "iAux FCoelho: " << iAux << "\n";
                }else if(specie == "FOvelha"){
                    iss >> iAux;
                    // TODO: Apply default hunger value for Ovelha
                    t << "iAux FOvelha: " << iAux << "\n";
                }else if(specie == "FLobo"){
                    iss >> iAux;
                    // TODO: Apply default hunger value for Lobo
                    t << "iAux FLobo: " << iAux << "\n";
                }else if(specie == "FCaranguejo"){
                    iss >> iAux;
                    // TODO: Apply default hunger value for Canguru
                    t << "iAux FCanguru: " << iAux << "\n";
                }else if(specie == "FPreguica"){
                    iss >> iAux;
                    // TODO: Apply default hunger value for Preguica
                    t << "iAux FPreguica: " << iAux << "\n";
                }
            }
            else if(specie[0] == 'P') {
                if(specie == "PCoelho"){
                    iss >> fAux;
                    // TODO: Apply default weight value for Coelho
                    t << "fAux PCoelho: " << fAux << "\n";
                }else if(specie == "POvelha"){
                    iss >> fAux;
                    // TODO: Apply default weight value for Ovelha
                    t << "fAux POvelha: " << fAux << "\n";
                }else if(specie == "PLobo"){
                    iss >> fAux;
                    // TODO: Apply default weight value for Lobo
                    t << "fAux PLobo: " << fAux << "\n";
                }else if(specie == "PCaranguejo"){
                    iss >> iAux;
                    // TODO: Apply default weight value for Canguru
                    t << "fAux PCanguru: " << fAux << "\n";
                }else if(specie == "PPreguica"){
                    iss >> fAux;
                    // TODO: Apply default weight value for Preguica
                    t << "fAux PPreguica: " << fAux << "\n";
                }
            }
        }
        readData.close();
        sleep(5); // Just for debug
    }
}

Reserva::Reserva(Reserva &Reserva) : NL(Reserva.NL), NC(Reserva.NC), topLeftCornerX(Reserva.topLeftCornerX),
                    topLeftCornerY(Reserva.topLeftCornerY), id(Reserva.id), simulatedTime(Reserva.simulatedTime),
                    name(Reserva.name), history(Reserva.history) {
    area.clear();
    for (int i = 0; i < NL; i++) {
        vector<Cell *> tmp;
        for (int j = 0; j < NC; j++) {
            tmp.push_back(new Cell(*Reserva.area[i][j]));
        }
        area.push_back(tmp);
        tmp.clear();
    }
}

Reserva::~Reserva() {}

int Reserva::getNL() const {
    return NL;
}

int Reserva::getNC() const {
    return NC;
}

int Reserva::getSimulatedTime() const {
    return simulatedTime;
}

string Reserva::getCellInfo(int lin, int col) {
    std::ostringstream oss;
    oss << area[lin][col]->getInfo(area[lin][col]) << endl;
    return oss.str();
}

int Reserva::getViewWindow() const {
    return viewWindow;
}

int Reserva::getTopLeftCornerX() const {
    return topLeftCornerX;
}

void Reserva::setTopLeftCornerX(int topLeftCornerX) {
    Reserva::topLeftCornerX = topLeftCornerX;
}

int Reserva::getTopLeftCornerY() const {
    return topLeftCornerY;
}

void Reserva::setTopLeftCornerY(int topLeftCornerY) {
    Reserva::topLeftCornerY = topLeftCornerY;
}

const vector<vector<Cell *>> &Reserva::getArea() const {
    return area;
}

void Reserva::setSimulatedTime(int simulatedTime) {
    Reserva::simulatedTime = simulatedTime;
}

const vector<Reserva *> &Reserva::getHistory() const {
    return history;
}

const string &Reserva::getName() const {
    return name;
}

void Reserva::addHistory(Reserva *r) {
    history.push_back(r);
}

void Reserva::setName(const string &name) {
    Reserva::name = name;
}

void Reserva::addDeadElements(int deadElement) {
    deadElements.push_back(deadElement);
}

void Reserva::animalActions(Reserva &r) {
    // Start by increasing the fome of all animals
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C" || r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O" ||
                   r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "M"){
                    r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() + 1);
                }
                else if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "L"){
                    r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() + 2);
                }
            }
        }
    }


    // Now, check again all animals and see how much fome they have
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C"){
                    if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 10){
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(random() % 3 + 1);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    }else if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 20){
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(random() % 4 + 1);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                }
                else if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O"){
                    if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 15){
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(random() % 2 + 1);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    }else if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 20){
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                }
                else if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "L"){
                    if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 15){
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(2);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    }else if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 25){
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                }
                else if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "G"){
                    if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 15){
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(2);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    }else if(r.getArea()[i][j]->getAnimals()[k]->getFome() > 25){
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                }
            }
        }
    }

    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C"){
                    int perception = r.getArea()[i][j]->getAnimals()[k]->getPerception();
                    int speed = r.getArea()[i][j]->getAnimals()[k]->getSpeed();
                    int eaten = 0;

                    if(r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getAnimals()[k] != nullptr && r.getArea()[i][j]->getFood()->getCheiro() == "Verdura"){
                            r.getArea()[i][j]->getAnimals()[k]->setSaude(r.getArea()[i][j]->getAnimals()[k]->getSaude() + r.getArea()[i][j]->getFood()->getValorNutritivo() - r.getArea()[i][j]->getFood()->getToxicidade());
                            r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() - r.getArea()[i][j]->getFood()->getValorNutritivo());
                            //r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[i][j]->getFood());
                            r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                            r.getArea()[i][j]->setFood("none", 0);
                            eaten = 1;
                    }

                    if(eaten == 0){
                        for (int l = i; l < i + perception; l++) {
                            for (int m = j; m < j + perception; m++) {
                                if(i + l < r.getNL() && j + m < r.getNC()){
                                    if(r.getArea()[l][m]->getFood() != nullptr && r.getArea()[l][m]->getFood()->getCheiro() == "Verdura"){
                                        //Check if the cell in question is within the animal's perception
                                        if(l <= i + perception && m <= j + perception){
                                            // Check if the cell in question is within the animal's speed
                                            if(l <= i + speed && m <= j + speed){
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(r.getArea()[i][j]->getAnimals()[k]->getSaude() + r.getArea()[l][m]->getFood()->getValorNutritivo() - r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() - r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                                //r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[l][m]->getFood());
                                                r.addDeadElements(r.getArea()[l][m]->getFood()->getId());
                                                r.getArea()[l][m]->setFood("none", 0);
                                                eaten = 1;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            if(eaten == 1){
                                break;
                            }
                        }
                    }

                    // for cycle to check in the inverse direction of the previous one if eaten is 0
                    if (eaten == 0) {
                        for(int l = i; l > i - perception; l--) {
                            for (int m = j; m > j - perception; m--) {
                                if (l >= 0 && m >= 0) {
                                    if (r.getArea()[l][m]->getFood() != nullptr && r.getArea()[l][m]->getFood()->getCheiro() == "Verdura") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l >= i - perception && m >= j - perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l >= i - speed && m >= j - speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(r.getArea()[i][j]->getAnimals()[k]->getSaude() + r.getArea()[l][m]->getFood()->getValorNutritivo() - r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() - r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                                //r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[l][m]->getFood());
                                                r.addDeadElements(r.getArea()[l][m]->getFood()->getId());
                                                r.getArea()[l][m]->setFood("none", 0);
                                                eaten = 1;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            if (eaten == 1) {
                                break;
                            }
                        }
                    }
                    // If there is no food, move to a random cell limited by his perception and speed
                    if (eaten == 0) {
                        // Random to choose the direction
                        int direction = rand() % 2;
                        int moved = 0;

                        // Move to a random cell limited by his perception and speed in the positive direction
                        do{
                            if(direction == 0){
                                int l = i + rand() % (speed + 1);
                                int m = j + rand() % (speed + 1);
                                if (l < r.getNL() && m < r.getNC()) {
                                    if (l <= i + perception && m <= j + perception) {
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            }else{
                                // Move to a random cell limited by his perception and speed in the negative direction
                                int l = i - rand() % (speed + 1);
                                int m = j - rand() % (speed + 1);
                                if (l >= 0 && m >= 0) {
                                    if (l >= i - perception && m >= j - perception) { // Don't know if when i - perception is negative it doesn't segfault
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            }
                        }while(moved == 0);
                    }
                }
            }
        }
    }
}

const vector<int> &Reserva::getDeadElements() const {
    return deadElements;
}

