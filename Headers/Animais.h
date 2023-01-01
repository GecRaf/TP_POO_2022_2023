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
    bool vivo;
public:
    Animais(int id,int b,int v,int f,float p=0, string e= " ",int s=0, bool vivo = true): id(id),vida(v),peso(p),especie(e), saude(s), fome(f),vivo(vivo){}
    int getVida() const {return vida;}
    int getSaude() const {return saude;}
    int getFome() const {return fome;}
    float getPeso() const {return peso;}
    string getEspecie() const{return especie;}
    void addFoodHistory(Alimentos &food);
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
private:
    int const visaoPeriferica = 3; // Perceciona 3 celulas a sua volta
    int const velocidade = 1; // Move-se 1 celula por instancia de tempo
    // A cada instante aumenta a fome em 1.
    // Se fome > 15, perde 1 de saude e move-se de 1 a 2 celulas de cada vez (efeito coelho).
    // Se fome > 20, perde 2 de saude a cada instante.
public:
    Ovelha(int id,int b,int v,int f): Animais(id,b,v,f, random() % 5 + 4,"O",30){};//PESO NUMERO RAND ENTRE 4 E 8
};

class Lobo : public Animais{
private:
    int const visaoPeriferica = 5; // Perceciona 5 celulas a sua volta
    int const velocidade = 1; // Move-se 1 celula por instancia de tempo (a não ser que veja algo interessante)
    // A cada instante aumenta a fome em 2.
    // Se fome > 15, perde 1 de saude e move-se de 2 celulas de cada vez.
    // Se fome > 25, perde 2 de saude a cada instante.
public:
    Lobo(int id,int b,int v, int f): Animais(id,b,v,f,15,"L",25){};
};

class Canguru : public Animais {
private:
    int const visaoPeriferica = 7; // Perceciona 7 celulas a sua volta
    int const velocidade = 1; // Move-se 1 celula por instancia de tempo
    // Se tiver menos de 10 instantes de idade, fica sempre 4 ou menos posições de distância do canguru mãe.
    // Se tiver menos de 10 instantes de idade e encontrar um canguru que não seja a mãe, foge a velocidade 2 para perto da mãe.
    // Quando chega à mãe, fica 5 instantes na bolsa da mãe. (Fica parado 5 instantes, basicamente)
    // Ao fim de 20 instantes é adulto e passa a ter 20kg.
public:
    Canguru(int id,int b,int v, int f): Animais(id,b,v,f,10,"G",20){};
};

class Preguica : public Animais {
private:
    int const visaoPeriferica = 1;
    int const velocidade = 0; // Não se move, pois é uma preguiça
    // A cada instante aumenta a fome em 1.
public:
    Preguica(int id,int b,int v, int f): Animais(id,b,v,f,5,"M",35){};
};
#endif //TPPOO2223_ANIMAIS_H
