
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

class Coelho : public Animais {
private:
    // TODO: Specific attributes
public:
    Coelho(string n, int v, float p, int s, int f,int Id);
};

class Ovelha : public Animais {
private:
    // TODO: Specific attributes
public:
    Ovelha(string n, int v, float p, int s, int f,int Id);
};

class Lobo : public Animais {
private:
    // TODO: Specific attributes
public:
    Lobo(string n, int v, float p, int s, int f,int Id);
};

class Caranguejo : public Animais {
private:
    // TODO: Specific attributes
public:
    Caranguejo(string n, int v, float p, int s, int f,int Id);
};

class Preguiça : public Animais {
private:
    // TODO: Specific attributes
public:
    Preguiça(string n, int v, float p, int s, int f,int Id);
};


#endif //TP_POO_2022_2023_ANIMAIS_H
