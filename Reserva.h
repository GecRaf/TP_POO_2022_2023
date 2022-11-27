//
// Created by olive on 22/11/2022.
//

#ifndef TPPOO2223_RESERVA_H
#define TPPOO2223_RESERVA_H

#include "Utils.h"
#include "Cell.h"

class Reserva {
private:
    int NL,NC;
    int viewWindow = 5;
    int topLeftCornerX = 0, topLeftCornerY = 0;
    int id = 1;
    int simulatedTime{};
    vector<Reserva *> reservas; // Vector to store game states
    vector< vector<Cell*>> area; // Vector to store the cells
public:
    Reserva()=default; // Default constructor, applies predefined size
    Reserva(int Id=0):id(Id){}
    Reserva(Reserva *Reserva); // Copy constructor
    Reserva(int NL, int NC, string filename = ""); // Constructor with size and filename

    int getNL() const;
    int getNC() const;
    int getViewWindow() const;
    int getTopLeftCornerX() const;
    void setTopLeftCornerX(int topLeftCornerX);
    int getTopLeftCornerY() const;
    void setTopLeftCornerY(int topLeftCornerY);
    int getId(){id++; return id;}
    int getSimulatedTime() const;
    string getCellInfo(int lin, int col);
    const vector<vector<Cell *>> &getArea() const;


    ~Reserva(); // Destructor
};


#endif //TPPOO2223_RESERVA_H
