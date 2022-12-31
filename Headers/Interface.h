//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#ifndef TPPOO2223_INTERFACE_H
#define TPPOO2223_INTERFACE_H
#include "Utils.h"
#include "Reserva.h"
#include "Cell.h"

class Interface {

public:
    static void ASCII();
    static void initInterface();
    static void showMatrix(Reserva &r);
    static void commandReader(Reserva &r, string fileCommand = "");
    static void increaseSimulatedTime(Reserva &r, int instances = 1, int interval = 1);
    static int checkID(Reserva &r, int id);
    static void createAnimal(Reserva &r, string specie, int lin, int col);
    static void killAnimal(Reserva &r,int lin, int col);
    static void killAnimalById(Reserva &r, int id);
    static void createFood(Reserva &r, string type, int lin, int col);
    static void feedAnimal(Reserva &r, int lin, int col, string foodType, int nutritionPoints, int toxicityPoints);
    static void feedAnimalById(Reserva &r, int id, string foodType,  int nutritionPoints, int toxicityPoints);
    static void noFood(Reserva &r, int lin, int col);
    static void empty(Reserva &r, int lin, int col);
    static void showIdInfo(Reserva &r, int id);
};


#endif //TPPOO2223_INTERFACE_H