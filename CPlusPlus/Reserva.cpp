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
    vector<Cell *> tmp;

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
        while (getline(readData, aux)) {
            istringstream iss(aux);
            int iAux;
            float fAux;
            string specie;
            iss >> specie;
            if (specie[0] == 'S') {
                if (specie == "SCoelho") {
                    iss >> iAux;
                    SCoelho = iAux;
                } else if (specie == "SOvelha") {
                    iss >> iAux;
                    SOvelha = iAux;
                } else if (specie == "SLobo") {
                    iss >> iAux;
                    SCoelho = iAux;
                } else if (specie == "SCaranguejo") {
                    iss >> iAux;
                    SCanguru = iAux;
                } else if (specie == "SPreguica") {
                    iss >> iAux;
                    SPreguica = iAux;
                }
            } else if (specie[0] == 'V') {
                if (specie == "VCoelho") {
                    iss >> iAux;
                    VCoelho = iAux;
                } else if (specie == "VOvelha") {
                    iss >> iAux;
                    VOvelha = iAux;
                } else if (specie == "VLobo") {
                    iss >> iAux;
                    VLobo = iAux;
                } else if (specie == "VCanguru") {
                    iss >> iAux;
                    VCanguru = iAux;
                } else if (specie == "VPreguica") {
                    iss >> iAux;
                    VPreguica = iAux;
                }
            } else if (specie[0] == 'F') {
                if (specie == "FCoelho") {
                    iss >> iAux;
                    FCoelho = iAux;
                } else if (specie == "FOvelha") {
                    iss >> iAux;
                    FOvelha = iAux;
                } else if (specie == "FLobo") {
                    iss >> iAux;
                    FLobo = iAux;
                } else if (specie == "FCanguru") {
                    iss >> iAux;
                    FCanguru = iAux;
                } else if (specie == "FPreguica") {
                    iss >> iAux;
                    FPreguica = iAux;
                }
            } else if (specie[0] == 'P') {
                if (specie == "PCoelho") {
                    iss >> fAux;
                    PCoelho = fAux;
                } else if (specie == "POvelha") {
                    iss >> fAux;
                    POvelha = fAux;
                } else if (specie == "PLobo") {
                    iss >> fAux;
                    PLobo = fAux;
                } else if (specie == "PCanguru") {
                    iss >> iAux;
                    PCanguru = iAux;
                } else if (specie == "PPreguica") {
                    iss >> fAux;
                    PPreguica = fAux;
                }
            }
        }
        readData.close();
        t << "\n\t[~] Default values loaded from file " << filename << "\n";
        sleep(5); // Just for debug
    }
}

Reserva::Reserva(Reserva &Reserva) : NL(Reserva.NL), NC(Reserva.NC), topLeftCornerX(Reserva.topLeftCornerX),
                                     topLeftCornerY(Reserva.topLeftCornerY), id(Reserva.id),
                                     simulatedTime(Reserva.simulatedTime),
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

Reserva::~Reserva() {
    for (int i = 0; i < NL; i++) {
        for (int j = 0; j < NC; j++) {
            delete area[i][j];
        }
        area[i].clear();
    }
    area.clear();
}

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
    Terminal &t = Terminal::instance();

    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if(!r.getArea()[i][j]->getAnimals()[k]->FicaVivo(r.getSimulatedTime())){
                    if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O"){
                        r.getArea()[i][j]->setFood("O",r.getId());
                        r.getArea()[i][j]->getFood()->setToxicidade(0);
                        r.getArea()[i][j]->getFood()->setValotNutritivo(r.getArea()[i][j]->getAnimals()[k]->getPeso());
                    }
                    else if(r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "G"){
                        r.getArea()[i][j]->setFood("G",r.getId());
                        r.getArea()[i][j]->getFood()->setToxicidade(5);
                        r.getArea()[i][j]->getFood()->setValotNutritivo(15);
                    }
                    r.addDeadElements(r.getArea()[i][j]->getAnimals()[k]->getId());
                    r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());

                }
            }
        }
    }

    // Start by increasing the fome of all animals
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C" ||
                    r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O" ||
                    r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "M") {
                    r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() + 1);
                } else if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "L") {
                    r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() + 2);
                }
            }
        }
    }

    // Now, check again all animals and see how much fome they have
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C") {
                    if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 10) {
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(random() % 3 + 1);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    } else if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 20) {
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(random() % 4 + 1);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                } else if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O") {
                    if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 15) {
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(random() % 2 + 1);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    } else if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 20) {
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                } else if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "L") {
                    if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 15) {
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(2);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    } else if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 25) {
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                } else if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "G") {
                    if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 15) {
                        r.getArea()[i][j]->getAnimals()[k]->setSpeed(2);
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 1);
                    } else if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 25) {
                        r.getArea()[i][j]->getAnimals()[k]->setVida(r.getArea()[i][j]->getAnimals()[k]->getVida() - 2);
                    }
                }
            }
        }
    }

    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C") {
                    int perception = r.getArea()[i][j]->getAnimals()[k]->getPerception();
                    int speed = r.getArea()[i][j]->getAnimals()[k]->getSpeed();
                    int eaten = 0, animalSpotted = 0;

                    if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getAnimals()[k] != nullptr &&
                        r.getArea()[i][j]->getFood()->getCheiro() == "Verdura") {
                        r.getArea()[i][j]->getAnimals()[k]->setSaude(r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                                     r.getArea()[i][j]->getFood()->getValorNutritivo() -
                                                                     r.getArea()[i][j]->getFood()->getToxicidade());
                        r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                                    r.getArea()[i][j]->getFood()->getValorNutritivo());
                        r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[i][j]->getFood());
                        r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                        r.getArea()[i][j]->setFood("none", 0);
                        eaten = 1;
                    }

                    if (eaten == 0) {
                        // Check if there is another animal in the perception area
                        for (int l = i - perception; l <= i + perception; l++) {
                            for (int m = j - perception; m <= j + perception; m++) {
                                if (l >= 0 && l < r.getNL() && m >= 0 && m < r.getNC()) {
                                    for (int n = 0; n < r.getArea()[l][m]->getAnimals().size(); n++) {
                                        if (r.getArea()[l][m]->getAnimals()[n]->getPeso() > 10) {
                                            // Run away from the animal
                                            if (l < i) {
                                                if (m < j) {
                                                    if (i + speed < r.getNL() && j + speed < r.getNC()) {
                                                        t << "Estou a correr para a direita e para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i + speed][j + speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i + speed << " " << j + speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else if (m > j) {
                                                    if (i + speed < r.getNL() && j - speed >= 0) {
                                                        t << "Estou a correr para a esquerda e para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i + speed][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i + speed << " " << j - speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else {
                                                    if (i + speed < r.getNL()) {
                                                        t << "Estou a correr para a direita" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i + speed][j]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i + speed << " " << j << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                }
                                            } else if (l > i) {
                                                if (m < j) {
                                                    if (i - speed >= 0 && j + speed < r.getNC()) {
                                                        t << "Estou a correr para a esquerda e para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i - speed][j + speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i - speed << " " << j + speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else if (m > j) {
                                                    if (i - speed >= 0 && j - speed >= 0) {
                                                        t << "Estou a correr para a esquerda e para cima" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i - speed][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i - speed << " " << j - speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else {
                                                    if (j - speed >= 0) {
                                                        t << "Estou a correr para a esquerda" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i - speed << " " << j << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                }
                                            } else {
                                                if (m < j) {
                                                    if (j + speed < r.getNC()) {
                                                        t << "Estou a correr para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i][j + speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i << " " << j + speed << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else if (m > j) {
                                                    if (j - speed >= 0) {
                                                        t << "Estou a correr para cima" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i << " " << j - speed << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (animalSpotted == 1) {
                                        break;
                                    }
                                }
                            }
                            if (animalSpotted == 1) {
                                break;
                            }
                        }
                    }

                    if (eaten == 0 && animalSpotted == 0) {
                        for (int l = i; l < i + perception; l++) {
                            for (int m = j; m < j + perception; m++) {
                                if (i + l < r.getNL() && j + m < r.getNC()) {
                                    if (r.getArea()[l][m]->getFood() != nullptr &&
                                        r.getArea()[l][m]->getFood()->getCheiro() == "Verdura") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l <= i + perception && m <= j + perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l <= i + speed && m <= j + speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                                        r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo() -
                                                        r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(
                                                        r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(
                                                        r.getArea()[i][j]->getAnimals()[k]->getId());
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

                    // for cycle to check in the inverse direction of the previous one if eaten is 0
                    if (eaten == 0 && animalSpotted == 0) {
                        for (int l = i; l > i - perception; l--) {
                            for (int m = j; m > j - perception; m--) {
                                if (l >= 0 && m >= 0) {
                                    if (r.getArea()[l][m]->getFood() != nullptr &&
                                        r.getArea()[l][m]->getFood()->getCheiro() == "Verdura") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l >= i - perception && m >= j - perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l >= i - speed && m >= j - speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                                        r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo() -
                                                        r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(
                                                        r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(
                                                        r.getArea()[i][j]->getAnimals()[k]->getId());
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
                    if (eaten == 0 && animalSpotted == 0) {
                        // Random to choose the direction
                        int direction = rand() % 2;
                        int moved = 0;

                        // Move to a random cell limited by his perception and speed in the positive direction
                        do {
                            if (direction == 0) {
                                int l = i + rand() % (speed + 1);
                                int m = j + rand() % (speed + 1);
                                if (l < r.getNL() && m < r.getNC()) {
                                    if (l <= i + perception && m <= j + perception) {
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            } else {
                                // Move to a random cell limited by his perception and speed in the negative direction
                                int l = i - rand() % (speed + 1);
                                int m = j - rand() % (speed + 1);
                                if (l >= 0 && m >= 0) {
                                    if (l >= i - perception && m >= j -
                                                                    perception) { // Don't know if when i - perception is negative it doesn't segfault
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            }
                        } while (moved == 0);
                    }
                }
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O") {
                    int perception = r.getArea()[i][j]->getAnimals()[k]->getPerception();
                    int speed = r.getArea()[i][j]->getAnimals()[k]->getSpeed();
                    int eaten = 0, animalSpotted = 0;

                    if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getAnimals()[k] != nullptr &&
                        r.getArea()[i][j]->getFood()->getCheiro() == "Erva") {
                        r.getArea()[i][j]->getAnimals()[k]->setSaude(r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                                     r.getArea()[i][j]->getFood()->getValorNutritivo() -
                                                                     r.getArea()[i][j]->getFood()->getToxicidade());
                        r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                                    r.getArea()[i][j]->getFood()->getValorNutritivo());
                        r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[i][j]->getFood());
                        r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                        r.getArea()[i][j]->setFood("none", 0);
                        eaten = 1;
                    }

                    if (eaten == 0) {
                        // Check if there is another animal in the perception area
                        for (int l = i - perception; l <= i + perception; l++) {
                            for (int m = j - perception; m <= j + perception; m++) {
                                if (l >= 0 && l < r.getNL() && m >= 0 && m < r.getNC()) {
                                    for (int n = 0; n < r.getArea()[l][m]->getAnimals().size(); n++) {
                                        if (r.getArea()[l][m]->getAnimals()[n]->getPeso() > 15) {
                                            // Run away from the animal
                                            if (l < i) {
                                                if (m < j) {
                                                    if (i + speed < r.getNL() && j + speed < r.getNC()) {
                                                        t << "Estou a correr para a direita e para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i + speed][j + speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i + speed << " " << j + speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else if (m > j) {
                                                    if (i + speed < r.getNL() && j - speed >= 0) {
                                                        t << "Estou a correr para a esquerda e para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i + speed][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i + speed << " " << j - speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else {
                                                    if (i + speed < r.getNL()) {
                                                        t << "Estou a correr para a direita" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i + speed][j]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i + speed << " " << j << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                }
                                            } else if (l > i) {
                                                if (m < j) {
                                                    if (i - speed >= 0 && j + speed < r.getNC()) {
                                                        t << "Estou a correr para a esquerda e para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i - speed][j + speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i - speed << " " << j + speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else if (m > j) {
                                                    if (i - speed >= 0 && j - speed >= 0) {
                                                        t << "Estou a correr para a esquerda e para cima" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i - speed][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i - speed << " " << j - speed
                                                          << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else {
                                                    if (j - speed >= 0) {
                                                        t << "Estou a correr para a esquerda" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i - speed << " " << j << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                }
                                            } else {
                                                if (m < j) {
                                                    if (j + speed < r.getNC()) {
                                                        t << "Estou a correr para baixo" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i][j + speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i << " " << j + speed << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                } else if (m > j) {
                                                    if (j - speed >= 0) {
                                                        t << "Estou a correr para cima" << "\n";
                                                        t << "Estou na posicao " << i << " " << j << "\n";
                                                        r.getArea()[i][j - speed]->copyNewAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                        r.getArea()[i][j]->removeAnimal(
                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                        t << "Vou para a posicao " << i << " " << j - speed << "\n";
                                                        animalSpotted = 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (animalSpotted == 1) {
                                        break;
                                    }
                                }
                            }
                            if (animalSpotted == 1) {
                                break;
                            }
                        }
                    }

                    if (eaten == 0 && animalSpotted == 0) {
                        for (int l = i; l < i + perception; l++) {
                            for (int m = j; m < j + perception; m++) {
                                if (i + l < r.getNL() && j + m < r.getNC()) {
                                    if (r.getArea()[l][m]->getFood() != nullptr &&
                                        r.getArea()[l][m]->getFood()->getCheiro() == "Erva") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l <= i + perception && m <= j + perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l <= i + speed && m <= j + speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                                        r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo() -
                                                        r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(
                                                        r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(
                                                        r.getArea()[i][j]->getAnimals()[k]->getId());
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

                    // for cycle to check in the inverse direction of the previous one if eaten is 0
                    if (eaten == 0 && animalSpotted == 0) {
                        for (int l = i; l > i - perception; l--) {
                            for (int m = j; m > j - perception; m--) {
                                if (l >= 0 && m >= 0) {
                                    if (r.getArea()[l][m]->getFood() != nullptr &&
                                        r.getArea()[l][m]->getFood()->getCheiro() == "Erva") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l >= i - perception && m >= j - perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l >= i - speed && m >= j - speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                                        r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo() -
                                                        r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(
                                                        r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(
                                                        r.getArea()[i][j]->getAnimals()[k]->getId());
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
                    if (eaten == 0 && animalSpotted == 0) {
                        // Random to choose the direction
                        int direction = rand() % 2;
                        int moved = 0;

                        // Move to a random cell limited by his perception and speed in the positive direction
                        do {
                            if (direction == 0) {
                                int l = i + rand() % (speed + 1);
                                int m = j + rand() % (speed + 1);
                                if (l < r.getNL() && m < r.getNC()) {
                                    if (l <= i + perception && m <= j + perception) {
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            } else {
                                // Move to a random cell limited by his perception and speed in the negative direction
                                int l = i - rand() % (speed + 1);
                                int m = j - rand() % (speed + 1);
                                if (l >= 0 && m >= 0) {
                                    if (l >= i - perception && m >= j -
                                                                    perception) { // Don't know if when i - perception is negative it doesn't segfault
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            }
                        } while (moved == 0);
                    }
                }
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "L") {
                    int perception = r.getArea()[i][j]->getAnimals()[k]->getPerception();
                    int speed = r.getArea()[i][j]->getAnimals()[k]->getSpeed();
                    int eaten = 0, animalSpotted = 0;

                    if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getAnimals()[k] != nullptr &&
                        r.getArea()[i][j]->getFood()->getCheiro() == "Carne") {
                        r.getArea()[i][j]->getAnimals()[k]->setSaude(r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                                     r.getArea()[i][j]->getFood()->getValorNutritivo() -
                                                                     r.getArea()[i][j]->getFood()->getToxicidade());
                        r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                                    r.getArea()[i][j]->getFood()->getValorNutritivo());
                        r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[i][j]->getFood());
                        r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                        r.getArea()[i][j]->setFood("none", 0);
                        eaten = 1;
                    }

                    if (eaten == 0 && animalSpotted == 0) {
                        if (r.getArea()[i][j]->getAnimals().size() > 1) {
                            for (int l = 0; l < r.getArea()[i][j]->getAnimals().size(); l++) {
                                if (r.getArea()[i][j]->getAnimals()[l]->getPeso() <
                                    r.getArea()[i][j]->getAnimals()[k]->getPeso()) {
                                    t << "Killed animal because it was smaller" << "\n";
                                    r.addDeadElements(r.getArea()[i][j]->getAnimals()[l]->getId());
                                    r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[l]->getId());
                                    // Check this later. Animal is being killed but ID not removed.
                                    t << "Animal killed" << "\n";
                                    eaten = 1;
                                    break;
                                } else if (r.getArea()[i][j]->getAnimals()[l]->getPeso() >
                                           r.getArea()[i][j]->getAnimals()[k]->getPeso()) {
                                    // One of the animals dies randomly
                                    int random = rand() % 2;
                                    if (random == 0) {
                                        t << "Killed animal bigger than me" << "\n";
                                        r.addDeadElements(r.getArea()[i][j]->getAnimals()[l]->getId());
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[l]->getId());
                                        t << "Animal killed" << "\n";
                                        eaten = 1;
                                        break;
                                    } else {
                                        t << "Wolf died" << "\n";
                                        r.addDeadElements(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        r.getArea()[i][j]->setFood("p",r.getId());
                                        r.getArea()[i][j]->getFood()->setToxicidade(0);
                                        r.getArea()[i][j]->getFood()->setValotNutritivo(10);
                                        t << "Animal killed" << "\n";
                                        eaten = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    if (eaten == 0 && animalSpotted == 0) {
                        // Check if there is another animal in the perception area
                        for (int l = i - perception; l <= i + perception; l++) {
                            for (int m = j - perception; m <= j + perception; m++) {
                                if (l >= 0 && l < r.getNL() && m >= 0 && m < r.getNC()) {
                                    for (int n = 0; n < r.getArea()[l][m]->getAnimals().size(); n++) {
                                        // If the Wolf spots another animal in the perception area, it will attack it at a speed of 2 (Or if he is with fome > 15, he will attack it at a speed of 3)
                                        // Move to the cell where the animal is limited by his speed
                                        if (r.getArea()[i][j]->getAnimals()[k]->getFome() > 15) {
                                            r.getArea()[i][j]->getAnimals()[k]->setSpeed(3);
                                            // Move closer to the animal only choosing the cells that are closer to the animal
                                            if (l < i && m < j) {
                                                if (i - speed >= 0 && j - speed >= 0) {
                                                    r.getArea()[i - speed][j - speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l < i && m > j) {
                                                if (i - speed >= 0 && j + speed < r.getNC()) {
                                                    r.getArea()[i - speed][j + speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }

                                            } else if (l > i && m < j) {
                                                if (i + speed < r.getNL() && j - speed >= 0) {
                                                    r.getArea()[i + speed][j - speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l > i && m > j) {
                                                if (i + speed < r.getNL() && j + speed < r.getNC()) {
                                                    r.getArea()[i + speed][j + speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l < i && m == j) {
                                                if (i - speed >= 0) {
                                                    r.getArea()[i - speed][j]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l > i && m == j) {
                                                if (i + speed < r.getNL()) {
                                                    r.getArea()[i + speed][j]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l == i && m < j) {
                                                if (j - speed >= 0) {
                                                    r.getArea()[i][j - speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l == i && m > j) {
                                                if (j + speed < r.getNC()) {
                                                    r.getArea()[i][j + speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            }
                                        } else {
                                            r.getArea()[i][j]->getAnimals()[k]->setSpeed(2);
                                            // Move closer to the animal only choosing the cells that are closer to the animal
                                            if (l < i && m < j) {
                                                if (i - speed >= 0 && j - speed >= 0) {
                                                    r.getArea()[i - speed][j - speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l < i && m > j) {
                                                if (i - speed >= 0 && j + speed < r.getNC()) {
                                                    r.getArea()[i - speed][j + speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l > i && m < j) {
                                                if (i + speed < r.getNL() && j - speed >= 0) {
                                                    r.getArea()[i + speed][j - speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l > i && m > j) {
                                                if (i + speed < r.getNL() && j + speed < r.getNC()) {
                                                    r.getArea()[i + speed][j + speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l < i && m == j) {
                                                if (i - speed >= 0) {
                                                    r.getArea()[i - speed][j]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l > i && m == j) {
                                                if (i + speed < r.getNL()) {
                                                    r.getArea()[i + speed][j]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l == i && m < j) {
                                                if (j - speed >= 0) {
                                                    r.getArea()[i][j - speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            } else if (l == i && m > j) {
                                                if (j + speed < r.getNC()) {
                                                    r.getArea()[i][j + speed]->copyNewAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]);
                                                    r.getArea()[i][j]->removeAnimal(
                                                            r.getArea()[i][j]->getAnimals()[k]->getId());
                                                    animalSpotted = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    if (animalSpotted == 1) {
                                        break;
                                    }
                                }
                            }
                            if (animalSpotted == 1) {
                                break;
                            }
                        }
                    }

                    if (eaten == 0 && animalSpotted == 0) {
                        for (int l = i; l < i + perception; l++) {
                            for (int m = j; m < j + perception; m++) {
                                if (i + l < r.getNL() && j + m < r.getNC()) {
                                    if (r.getArea()[l][m]->getFood() != nullptr &&
                                        r.getArea()[l][m]->getFood()->getCheiro() == "Carne") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l <= i + perception && m <= j + perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l <= i + speed && m <= j + speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                                        r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo() -
                                                        r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(
                                                        r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(
                                                        r.getArea()[i][j]->getAnimals()[k]->getId());
                                                r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(
                                                        r.getArea()[l][m]->getFood());
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

                    // for cycle to check in the inverse direction of the previous one if eaten is 0
                    if (eaten == 0 && animalSpotted == 0) {
                        for (int l = i; l > i - perception; l--) {
                            for (int m = j; m > j - perception; m--) {
                                if (l >= 0 && m >= 0) {
                                    if (r.getArea()[l][m]->getFood() != nullptr &&
                                        r.getArea()[l][m]->getFood()->getCheiro() == "Carne") {
                                        //Check if the cell in question is within the animal's perception
                                        if (l >= i - perception && m >= j - perception) {
                                            // Check if the cell in question is within the animal's speed
                                            if (l >= i - speed && m >= j - speed) {
                                                r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                                        r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo() -
                                                        r.getArea()[l][m]->getFood()->getToxicidade());
                                                r.getArea()[i][j]->getAnimals()[k]->setFome(
                                                        r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                        r.getArea()[l][m]->getFood()->getValorNutritivo());
                                                r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                                r.getArea()[i][j]->removeAnimal(
                                                        r.getArea()[i][j]->getAnimals()[k]->getId());
                                                r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(
                                                        r.getArea()[l][m]->getFood());
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
                    if (eaten == 0 && animalSpotted == 0) {
                        // Random to choose the direction
                        int direction = rand() % 2;
                        int moved = 0;

                        // Move to a random cell limited by his perception and speed in the positive direction
                        do {
                            if (direction == 0) {
                                int l = i + rand() % (speed + 1);
                                int m = j + rand() % (speed + 1);
                                if (l < r.getNL() && m < r.getNC()) {
                                    if (l <= i + perception && m <= j + perception) {
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            } else {
                                // Move to a random cell limited by his perception and speed in the negative direction
                                int l = i - rand() % (speed + 1);
                                int m = j - rand() % (speed + 1);
                                if (l >= 0 && m >= 0) {
                                    if (l >= i - perception && m >= j -
                                                                    perception) { // Don't know if when i - perception is negative it doesn't segfault
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            }
                        } while (moved == 0);
                    }
                }
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "G") {
                    int perception = r.getArea()[i][j]->getAnimals()[k]->getPerception();
                    int speed = r.getArea()[i][j]->getAnimals()[k]->getSpeed();
                    int animalSpotted = 0;

                    if (r.getArea()[i][j]->getAnimals()[k]->getInvisible() != 0) {
                        r.getArea()[i][j]->getAnimals()[k]->setInvisibleTime(
                                r.getArea()[i][j]->getAnimals()[k]->getInvisible() - 1);
                        // If the mother moves, the baby moves with her
                        // Check where the mother is
                        for (int l = 0; l < r.getNL(); l++) {
                            for (int m = 0; m < r.getNC(); m++) {
                                if (r.getArea()[l][m]->getAnimals().size() != 0) {
                                    for (int n = 0; n < r.getArea()[l][m]->getAnimals().size(); n++) {
                                        if (r.getArea()[l][m]->getAnimals()[n]->getId() ==
                                            r.getArea()[i][j]->getAnimals()[k]->getMotherID()) {
                                            r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                            r.getArea()[i][j]->removeAnimal(
                                                    r.getArea()[i][j]->getAnimals()[k]->getId());
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        r.getArea()[i][j]->getAnimals()[k]->setInvisible(false);
                    }
                    // If the Canguru has less than 10 instants of life, he always stays maximum 4 cells away from his mother
                    if (r.getSimulatedTime() - r.getArea()[i][j]->getAnimals()[k]->getBirthInstant() < 10) {
                        if (r.getArea()[i][j]->getAnimals()[k]->getMotherID() != 0) {
                            // Check if the are any other animals in his perception, if so, runs to his mother
                            for (int l = i - perception; l <= i + perception; l++) {
                                for (int m = j - perception; m <= j + perception; m++) {
                                    if (l >= 0 && l < r.getNL() && m >= 0 && m < r.getNC()) {
                                        for (int n = 0; n < r.getArea()[l][m]->getAnimals().size(); n++) {
                                            // If he sees another animal, he runs to his mother
                                            if (r.getArea()[l][m]->getAnimals()[n]->getId() !=
                                                r.getArea()[i][j]->getAnimals()[k]->getMotherID()) {
                                                animalSpotted = 1;
                                                speed = 2;
                                                for (int l = 0; l < r.getNL(); l++) {
                                                    for (int m = 0; m < r.getNC(); m++) {
                                                        for (int n = 0;
                                                             n < r.getArea()[l][m]->getAnimals().size(); n++) {
                                                            if (r.getArea()[l][m]->getAnimals()[n]->getId() ==
                                                                r.getArea()[i][j]->getAnimals()[k]->getMotherID()) {
                                                                // Check if he is already in the same cell as his mother
                                                                if (l == i && m == j) {
                                                                    r.getArea()[i][j]->getAnimals()[k]->setInvisible(
                                                                            true);
                                                                    r.getArea()[i][j]->getAnimals()[k]->setInvisibleTime(
                                                                            r.getSimulatedTime());
                                                                    break;
                                                                }
                                                                // Check if the mother is within the Canguru's perception
                                                                if (l >= i - perception && l <= i + perception &&
                                                                    m >= j - perception && m <= j + perception) {
                                                                    // Check if the mother is within the Canguru's speed
                                                                    if (l >= i - speed && l <= i + speed &&
                                                                        m >= j - speed && m <= j + speed) {
                                                                        r.getArea()[l][m]->copyNewAnimal(
                                                                                r.getArea()[i][j]->getAnimals()[k]);
                                                                        r.getArea()[i][j]->removeAnimal(
                                                                                r.getArea()[i][j]->getAnimals()[k]->getId());
                                                                        animalSpotted = 1;
                                                                        break;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        if (animalSpotted == 1) {
                                                            break;
                                                        }
                                                    }
                                                    if (animalSpotted == 1) {
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (animalSpotted == 1) {
                                break;
                            }
                        } else {
                            // If the Canguru has no mother (sad :( xD), he can move freely
                            // Random to choose the direction
                            int direction = rand() % 2;
                            int moved = 0;

                            // Move to a random cell limited by his perception and speed in the positive direction
                            do {
                                if (direction == 0) {
                                    int l = i + rand() % (speed + 1);
                                    int m = j + rand() % (speed + 1);
                                    if (l < r.getNL() && m < r.getNC()) {
                                        if (l <= i + perception && m <= j + perception) {
                                            r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                            r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                            moved = 1;
                                        }
                                    }
                                } else {
                                    // Move to a random cell limited by his perception and speed in the negative direction
                                    int l = i - rand() % (speed + 1);
                                    int m = j - rand() % (speed + 1);
                                    if (l >= 0 && m >= 0) {
                                        if (l >= i - perception && m >= j -
                                                                        perception) { // Don't know if when i - perception is negative it doesn't segfault
                                            r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                            r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                            moved = 1;
                                        }
                                    }
                                }
                            } while (moved == 0);
                        }
                    }
                    else {
                        // If the Canguru has more than 10 instants of life, he can move freely
                        // Random to choose the direction
                        int direction = rand() % 2;
                        int moved = 0;

                        // Move to a random cell limited by his perception and speed in the positive direction
                        do {
                            if (direction == 0) {
                                int l = i + rand() % (speed + 1);
                                int m = j + rand() % (speed + 1);
                                if (l < r.getNL() && m < r.getNC()) {
                                    if (l <= i + perception && m <= j + perception) {
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            } else {
                                // Move to a random cell limited by his perception and speed in the negative direction
                                int l = i - rand() % (speed + 1);
                                int m = j - rand() % (speed + 1);
                                if (l >= 0 && m >= 0) {
                                    if (l >= i - perception && m >= j -
                                                                    perception) { // Don't know if when i - perception is negative it doesn't segfault
                                        r.getArea()[l][m]->copyNewAnimal(r.getArea()[i][j]->getAnimals()[k]);
                                        r.getArea()[i][j]->removeAnimal(r.getArea()[i][j]->getAnimals()[k]->getId());
                                        moved = 1;
                                    }
                                }
                            }
                        } while (moved == 0);
                    }
                }
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "M") {
                    // Since this animal is a Sloth, it only eats if food is in the same cell
                    if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getAnimals()[k] != nullptr) {
                        if (r.getArea()[i][j]->getFood()->getCheiro() == "Verdura" ||
                            r.getArea()[i][j]->getFood()->getCheiro() == "Fruta") {
                            r.getArea()[i][j]->getAnimals()[k]->setSaude(
                                    r.getArea()[i][j]->getAnimals()[k]->getSaude() +
                                    r.getArea()[i][j]->getFood()->getValorNutritivo() -
                                    r.getArea()[i][j]->getFood()->getToxicidade());
                            r.getArea()[i][j]->getAnimals()[k]->setFome(r.getArea()[i][j]->getAnimals()[k]->getFome() -
                                                                        r.getArea()[i][j]->getFood()->getValorNutritivo());
                            r.getArea()[i][j]->getAnimals()[k]->Animais::addFoodHistory(r.getArea()[i][j]->getFood());
                            r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                            r.getArea()[i][j]->setFood("none", 0);
                        }
                    }
                }
            }
        }
    }
}

const vector<int> &Reserva::getDeadElements() const {
    return deadElements;
}

void Reserva::foodActions(Reserva &r) {

    Terminal &t = Terminal::instance();

    //remover bife quando a sua duraçao chega a 30
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            if (r.getArea()[i][j]->getFood() != nullptr  && r.getArea()[i][j]->getFood()->getNome() == "B") {
                if (r.getArea()[i][j]->getFood()->getDuracao() >= 30) {
                    r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                    r.getArea()[i][j]->setFood("none",0);
                }
            }
        }
    }

    int moved = 0;
    //aparecer outra relva
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getFood()->getNome() == "R") {
                if (r.getArea()[i][j]->getFood()->getDuracao() == 5) {
                    int direction = rand() % 2;
                    // Move to a random cell limited by his perception and speed in the positive direction
                    do {
                        if (direction == 0) {
                            int x = i + random() % 5 + 4;
                            int y = j + random() % 5 + 4;
                            if (x < r.getNL() && y < r.getNC()) {
                                if (r.getArea()[x][y]->getFood() == nullptr) {
                                    r.getArea()[x][y]->adicionaRelva(r.getId());
                                }
                                moved = 1;
                            }
                        }else{
                            int x = i - random() % 5 + 4;
                            int y = j - random() % 5 + 4;
                            if (x < r.getNL() && y < r.getNC()) {
                                if (r.getArea()[x][y]->getFood() == nullptr) {
                                    r.getArea()[x][y]->adicionaRelva(r.getId());
                                }
                                moved = 1;
                            }
                        }
                    }while (moved == 0);
                }
            }
        }
        if(moved == 1){
            break;
        }
    }

    //diminuir valor nutritivo
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            if (r.getArea()[i][j]->getFood() != nullptr && (r.getArea()[i][j]->getFood()->getNome() == "P" ||
                r.getArea()[i][j]->getFood()->getNome() == "B")) {
                while (r.getArea()[i][j]->getFood()->getValorNutritivo() < 0) {
                    r.getArea()[i][j]->getFood()->setValotNutritivo(
                            r.getArea()[i][j]->getFood()->getValorNutritivo() - 1);
                }
            }
        }
    }
    //aumenta toxicidade
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); ++j) {
            if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getFood()->getNome() == "T") {
                while (r.getArea()[i][j]->getFood()->getToxicidade() <= 3) {
                    if (r.getArea()[i][j]->getFood()->getGenerate() - r.getSimulatedTime() == 10 ||
                        r.getArea()[i][j]->getFood()->getGenerate() - r.getSimulatedTime() == 20 ||
                        r.getArea()[i][j]->getFood()->getGenerate() - r.getSimulatedTime() == 30) {
                        r.getArea()[i][j]->getFood()->setToxicidade(
                                r.getArea()[i][j]->getFood()->getToxicidade() + 1);
                    }
                }
            } else if (r.getArea()[i][j]->getFood() != nullptr && r.getArea()[i][j]->getFood()->getNome() == "P") {
                while (r.getArea()[i][j]->getFood()->getToxicidade() == 2 * 15) {
                    r.getArea()[i][j]->getFood()->setToxicidade(r.getArea()[i][j]->getFood()->getToxicidade() + 1);
                }
            }
        }
    }

    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            if (r.getArea()[i][j]->getFood() != nullptr) {
                if(r.getArea()[i][j]->getFood()->getDuracao() == 0){
                    r.addDeadElements(r.getArea()[i][j]->getFood()->getId());
                    r.getArea()[i][j]->setFood("none",0);
                }else{
                    r.getArea()[i][j]->getFood()->setDuracao(r.getArea()[i][j]->getFood()->getDuracao() - 1);
                }
            }
        }
    }
}

void nascerAnimais(Reserva & r) {
    int moved = 0;
    //faz nascer ovelha
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "O") {
                    if (r.getSimulatedTime() - r.getArea()[i][j]->getAnimals()[k]->getBirthInstant() == 15) {
                        int direction = rand() % 2;
                        // Move to a random cell limited by his perception and speed in the positive direction
                        do {
                            if (direction == 0) {
                                int x = i + random() % 12 + 1;
                                int y = j + random() % 12 + 1;
                                if (x < r.getNL() && y < r.getNC()) {
                                    r.getArea()[x][y]->setAnimal("0",r.getSimulatedTime(),r.getId(),r.getArea()[i][j]->getAnimals()[k]->getSaude(),0,0,0);
                                    moved = 1;
                                }
                            } else {
                                int x = i + random() % 12 + 1;
                                int y = j + random() % 12 + 1;
                                if (x < r.getNL() && y < r.getNC()) {
                                    r.getArea()[x][y]->setAnimal("0",r.getSimulatedTime(),r.getId(),r.getArea()[i][j]->getAnimals()[k]->getSaude(),0,0,0);
                                    moved = 1;
                                }
                            }
                        }while(moved == 0);
                    }
                }
            }
        }
    }

    //faz nascer canguro
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "G") {
                    if (r.getSimulatedTime() - r.getArea()[i][j]->getAnimals()[k]->getBirthInstant() == 30) {
                        int direction = rand() % 2;

                        do {
                            if (direction == 0) {
                                int x = i + random() % 3 + 1;
                                int y = j + random() % 3 + 1;
                                if (x < r.getNL() && y < r.getNC()) {
                                    r.getArea()[x][y]->setAnimal("G",r.getSimulatedTime(),r.getId(),0,0,0,0);
                                    moved = 1;
                                }
                            } else {
                                int x = i + random() % 3 + 1;
                                int y = j + random() % 3 + 1;
                                if (x < r.getNL() && y < r.getNC()) {
                                    r.getArea()[x][y]->setAnimal("G",r.getSimulatedTime(),r.getId(),0,0,0,0);
                                    moved = 1;
                                }
                            }
                        }while(moved == 0);
                    }
                }
            }
        }
    }
    //faz nascer lobo
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "L") {
                    if (!r.getArea()[i][j]->getAnimals()[k]->getHasChild()) {
                       if(r.getArea()[i][j]->getAnimals()[k]->getBirthInstant() == r.getArea()[i][j]->getAnimals()[k]->getChildBd()) {//esta mal
                           int direction = rand() % 2;

                           do {
                               if (direction == 0) {
                                   int x = i + random() % 15 + 1;
                                   int y = j + random() % 15 + 1;
                                   if (x < r.getNL() && y < r.getNC()) {
                                       r.getArea()[x][y]->setAnimal("L", r.getSimulatedTime(), r.getId(), 0, 0, 0, 0);
                                       moved = 1;
                                   }
                               } else {
                                   int x = i + random() % 15 + 1;
                                   int y = j + random() % 15 + 1;
                                   if (x < r.getNL() && y < r.getNC()) {
                                       r.getArea()[x][y]->setAnimal("L", r.getSimulatedTime(), r.getId(), 0, 0, 0, 0);
                                       moved = 1;
                                   }
                               }
                           } while (moved == 0);
                       }
                    }
                }
            }
        }
    }
    //faz nascer um coelho
    for (int i = 0; i < r.getNL(); i++) {
        for (int j = 0; j < r.getNC(); j++) {
            for (int k = 0; k < r.getArea()[i][j]->getAnimals().size(); k++) {
                if (r.getArea()[i][j]->getAnimals()[k]->getEspecie() == "C") {
                    if (r.getSimulatedTime() - r.getArea()[i][j]->getAnimals()[k]->getBirthInstant() == 8 && r.getArea()[i][j]->getAnimals()[k]->getProbabilidade() <= 50) {
                        int direction = rand() % 2;

                        do {
                            if (direction == 0) {
                                int x = i + random() % 10 + 1;
                                int y = j + random() % 10 + 1;
                                if (x < r.getNL() && y < r.getNC()) {
                                    r.getArea()[x][y]->setAnimal("C",r.getSimulatedTime(),r.getId(),0,0,0,0);
                                    moved = 1;
                                }
                            } else {
                                int x = i + random() % 10 + 1;
                                int y = j + random() % 10 + 1;
                                if (x < r.getNL() && y < r.getNC()) {
                                    r.getArea()[x][y]->setAnimal("C",r.getSimulatedTime(),r.getId(),0,0,0,0);
                                    moved = 1;
                                }
                            }
                        }while(moved == 0);
                    }
                }
            }
        }
    }
}

int Reserva::getSCoelho() const {
    return SCoelho;
}

int Reserva::getSOvelha() const {
    return SOvelha;
}

int Reserva::getSLobo() const {
    return SLobo;
}

int Reserva::getSCanguru() const {
    return SCanguru;
}

int Reserva::getSPreguica() const {
    return SPreguica;
}

int Reserva::getVCoelho() const {
    return VCoelho;
}

int Reserva::getVOvelha() const {
    return VOvelha;
}

int Reserva::getVLobo() const {
    return VLobo;
}

int Reserva::getVCanguru() const {
    return VCanguru;
}

int Reserva::getVPreguica() const {
    return VPreguica;
}

int Reserva::getFCoelho() const {
    return FCoelho;
}

int Reserva::getFOvelha() const {
    return FOvelha;
}

int Reserva::getFLobo() const {
    return FLobo;
}

int Reserva::getFCanguru() const {
    return FCanguru;
}

int Reserva::getFPreguica() const {
    return FPreguica;
}

float Reserva::getPCoelho() const {
    return PCoelho;
}

float Reserva::getPOvelha() const {
    return POvelha;
}

float Reserva::getPLobo() const {
    return PLobo;
}

float Reserva::getPCanguru() const {
    return PCanguru;
}

float Reserva::getPPreguica() const {
    return PPreguica;
}
