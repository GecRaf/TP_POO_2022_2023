
#ifndef TP_POO_2022_2023_ANIMAIS_H
#define TP_POO_2022_2023_ANIMAIS_H

#include "utils.h"

class Animais {
private:
    int id;
    string nome;
    string especie;
    int vida;
    int saude;
    int fome;
    float peso;
public:
    Animais(string n,string e, int v,float p, int s, int f=1,int Id = 1):id(Id),nome(n),especie(e),vida(v),saude(s),fome(f),peso(p){}
    int getId();
    float getPeso() const {return peso;}
    bool vivo(int saude);
    void aumentaFome(int fome);
    void diminuiFome(int fome);
    void aumentaSaude(int saude);
    void diminuiSaude(int saude);
};


#endif //TP_POO_2022_2023_ANIMAIS_H
