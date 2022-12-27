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
