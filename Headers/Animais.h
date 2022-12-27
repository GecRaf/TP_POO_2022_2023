//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#ifndef TPPOO2223_ANIMAIS_H
#define TPPOO2223_ANIMAIS_H

#include "Utils.h"
#include "Alimentos.h"

class Animais {
private:
    int id;
    string const especie;
    int vida;
    int saude;
    int fome;
    float peso;
    Alimentos* foodHistory = nullptr;
    int foodHistorySize = 0;
    int birthInstant;
public:
    Animais(int id,int b,int v,int f,float p=0, string e= " ",int s=0): id(id),vida(v),peso(p),especie(e), saude(s), fome(f){}
    int getVida() const {return vida;}
    int getSaude() const {return saude;}
    int getFome() const {return fome;}
    float getPeso() const {return peso;}
    string getEspecie() const{return especie;}
    void addFoodHistory(Alimentos &food);
    void setVida(int vida);
    void setSaude(int saude);
    void setFome(int fome);
    void setPeso(float peso);
    bool vivo(int simulatedTime);
    void aumentaFome(int simulatedTime);
    void diminuiFome(int simulatedTime);
    void aumentaSaude();
    void diminuiSaude(int simulatedTime);
    void aumentaPeso(int simulatedTime);
    int getBirthInstant() const;
    int getId() const;
    string getInfo();
};

class Coelho : public Animais {
private:
    int const visaoPeriferica = 4; // Perceciona 4 celulas a sua volta
    int const velocidade = random() % 2 + 1; // Move-se 1 ou 2 celulas por instancia de tempo
    // A cada instante aumenta a fome em 1.
    // Se fome > 10, perde 1 de saude e move-se de 1 a 3 celulas.
    // Se fome > 20, perde 2 de saude e move-se de 1 a 4 celulas.
public:
    Coelho(int id,int b,int v,int f):Animais(id,b,v,f, random() % 4 + 1,"C",20){};//PESO NUMERO RAND ENTRE 1 E 4
};

class Ovelha : public Animais {
public:
    Ovelha(int id,int b,int v,int f): Animais(id,b,v,f, random() % 5 + 4,"O",30){};//PESO NUMERO RAND ENTRE 4 E 8
};

class Lobo : public Animais{
public:
    Lobo(int id,int b,int v, int f): Animais(id,b,v,f,15,"L",25){};
};

class Canguru : public Animais {
public:
    Canguru(int id,int b,int v, int f): Animais(id,b,v,f,10,"G",20){};
};

class Preguica : public Animais {
public:
    Preguica(int id,int b,int v, int f): Animais(id,b,v,f,5,"M",35){};
};
#endif //TPPOO2223_ANIMAIS_H
