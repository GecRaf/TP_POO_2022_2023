
#ifndef TPPOO2223_ANIMAIS_H
#define TPPOO2223_ANIMAIS_H

#include "Utils.h"

class Animais {
private:
    string const especie;
    int vida;
    int saude;
    int fome;
    float peso;
public:
    Animais(string e,int v,float p,int s,int f=1):especie(e),vida(v),saude(s),fome(f),peso(p){}
    int getVida() const {return vida;}
    int getSaude() const {return saude;}
    int getFome() const {return fome;}
    float getPeso() const {return peso;}
    string getEspecie() const{return especie;}

    void setVida(int vida);

    void setSaude(int saude);

    void setFome(int fome);

    void setPeso(float peso);

    bool vivo();
    void aumentaFome();
    void diminuiFome();
    void aumentaSaude();
    void diminuiSaude();
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

class Preguica : public Animais {
private:
    // TODO: Specific attributes
public:
    Preguica(string n, int v, float p, int s, int f,int Id);
};


#endif //TPPOO2223_ANIMAIS_H
