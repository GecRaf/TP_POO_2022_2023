//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#ifndef TPPOO2223_RESERVA_H
#define TPPOO2223_RESERVA_H

#include "Utils.h"
#include "Cell.h"

class Reserva {
private:
    int NL,NC;                                                  //Number of lines and columns
    int viewWindow = 5;                                         //Terminal View window
    int topLeftCornerX = 0, topLeftCornerY = 0;                 //Top left corner of the view window start position
    int id = 0;                                                 //ID of the elements in the reserve
    int simulatedTime = 0;                                      //Simulated time
    string name;                                                //Name of the reserve [Storage Name]
    vector<Reserva *> history;                                  // Vector to store game states
    vector< vector<Cell*>> area;                                // Vector to store the cells
    vector<int> deadElements;                                   // Vector to store the dead elements

    int SCoelho = 0;
    int SOvelha = 0;
    int SLobo = 0;
    int SCanguru = 0;
    int SPreguica = 0;

    int VCoelho = 0;
    int VOvelha = 0;
    int VLobo = 0;
    int VCanguru = 0;
    int VPreguica = 0;

    int FCoelho = 0;
    int FOvelha = 0;
    int FLobo = 0;
    int FCanguru = 0;
    int FPreguica = 0;

    float PCoelho = 0.0;
    float POvelha = 0.0;
    float PLobo = 0.0;
    float PCanguru = 0.0;
    float PPreguica = 0.0;
public:

    Reserva()=default;                                          // Default constructor, applies predefined size
    Reserva(int Id=0):id(Id){}
    Reserva(Reserva &Reserva);                                  // Copy constructor
    Reserva(int NL, int NC, string filename = "");              // Constructor with size and filename

    int getNL() const;
    int getNC() const;
    int getViewWindow() const;
    int getTopLeftCornerX() const;
    void setTopLeftCornerX(int topLeftCornerX);
    int getTopLeftCornerY() const;
    void setTopLeftCornerY(int topLeftCornerY);
    int getId(){id++; return id;}
    int getRawId(){return id;}
    int getSimulatedTime() const;
    void setSimulatedTime(int simulatedTime);
    string getCellInfo(int lin, int col);
    const string &getName() const;
    void setName(const string &name);
    void addHistory(Reserva *r);
    const vector<Reserva *> &getHistory() const;
    const vector<vector<Cell *>> &getArea() const;
    const vector<int> &getDeadElements() const;
    void addDeadElements(int deadElement);
    void animalActions(Reserva &r);
    void foodActions(Reserva &r);
    void growAnimals(Reserva &r);
    int getSCoelho() const;
    int getSOvelha() const;
    int getSLobo() const;
    int getSCanguru() const;
    int getSPreguica() const;
    int getVCoelho() const;
    int getVOvelha() const;
    int getVLobo() const;
    int getVCanguru() const;
    int getVPreguica() const;
    int getFCoelho() const;
    int getFOvelha() const;
    int getFLobo() const;
    int getFCanguru() const;
    int getFPreguica() const;
    float getPCoelho() const;
    float getPOvelha() const;
    float getPLobo() const;
    float getPCanguru() const;
    float getPPreguica() const;

    ~Reserva(); // Destructor
};


#endif //TPPOO2223_RESERVA_H
