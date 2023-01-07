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
    Alimentos* foodHistory;
    int foodHistorySize = 0;
    int birthInstant;
    bool vivo;
    int perception;
    int speed;
public:
    Animais(int id,int b,int v,int f,float p=0, string e= " ",int s=0, bool vivo = true, int perception = 0, int speed = 0): id(id),birthInstant(b), vida(v),peso(p),especie(e), saude(s), fome(f),vivo(vivo), perception(perception), speed(speed){foodHistory = nullptr;}
    Animais(Animais &a);
    int getVida() const {return vida;}
    int getSaude() const {return saude;}
    int getFome() const {return fome;}
    float getPeso() const {return peso;}
    string getEspecie() const{return especie;}
    void addFoodHistory(Alimentos *food);
    bool FicaVivo(int simulatedTime);
    void aumentaFome(int simulatedTime);
    void diminuiFome(int simulatedTime);
    void aumentaSaude();
    void diminuiSaude(int simulatedTime);
    void aumentaPeso(int simulatedTime);
    void feed(int id, string foodType, int nutritionPoints, int toxicityPoints);
    int getBirthInstant() const;
    int getId() const;
    string getInfo();
    bool getVivo(){return true;}
    void setVida(int vida);
    void setSaude(int saude);
    void setFome(int fome);
    void setPeso(float peso);
    void setVivo(bool Vivo);
    int getPerception() const;
    void setPerception(int perception);
    int getSpeed() const;
    void setSpeed(int speed);
    virtual int getMotherID() const;
    virtual bool getInvisible() const;
    virtual void setInvisible(bool invisible);
    virtual int getInvisibleTime() const;
    virtual void setInvisibleTime(int invisibleTime);
};

class Coelho : public Animais {
private:
    // A cada instante aumenta a fome em 1.
    // Se fome > 10, perde 1 de saude e move-se de 1 a 3 celulas.
    // Se fome > 20, perde 2 de saude e move-se de 1 a 4 celulas.
public:
    Coelho(int id,int b,int s = 20, int v = 100,int f = 0, float p = random() % 4 + 1):Animais(id,b,v,f, p,"C",s, true, 4,random() % 2 + 1){};//PESO NUMERO RAND ENTRE 1 E 4
};

class Ovelha : public Animais {
private:
    // A cada instante aumenta a fome em 1.
    // Se fome > 15, perde 1 de saude e move-se de 1 a 2 celulas de cada vez.
    // Se fome > 20, perde 2 de saude a cada instante.
public:
    Ovelha(int id,int b,int s = 20, int v = 100,int f = 0, float p = random() % 5 + 4): Animais(id,b,v,f, p,"O",s, true,3,1){};//PESO NUMERO RAND ENTRE 4 E 8
};

class Lobo : public Animais{
private:
    // A cada instante aumenta a fome em 2.
    // Se fome > 15, perde 1 de saude e move-se de 2 celulas de cada vez.
    // Se fome > 25, perde 2 de saude a cada instante.
public:
    Lobo(int id,int b,int s = 25, int v = 100, int f = 0, float p = 15): Animais(id,b,v,f,p,"L",s, true, 5, 1){};
};

class Canguru : public Animais {
private:
    int motherID;
    bool invisible;
    int invisibleTime;
    // Se tiver menos de 10 instantes de idade, fica sempre 4 ou menos posições de distância do canguru mãe.
    // Se tiver menos de 10 instantes de idade e encontrar um canguru que não seja a mãe,
    // foge a velocidade 2 para perto da mãe.
    // Quando chega à mãe, fica 5 instantes na bolsa da mãe. (Fica parado 5 instantes, basicamente)
    // Ao fim de 20 instantes é adulto e passa a ter 20kg.
public:
    Canguru(int id,int b,int s = 20, int v = 100, int f = 0, int motherID = 0, float p = 10): Animais(id,b,v,f,p,"G",s, true, 7,1){invisible = false;};
    int getMotherID() {return motherID;}
    bool getInvisible() {return invisible;}
    void setInvisible(bool invisible) {Canguru::invisible = invisible;}
    int getInvisibleTime() const{return invisibleTime;}
    void setInvisibleTime(int invisibleTime){Canguru::invisibleTime = invisibleTime;}
};

class Preguica : public Animais {
private:
    // A cada instante aumenta a fome em 1.
public:
    Preguica(int id,int b,int s = 35, int v = 100, int f = 0, float p = 5): Animais(id,b,v,f,p,"M",s, true, 1,0){};
};
#endif //TPPOO2223_ANIMAIS_H
