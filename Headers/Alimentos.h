//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#ifndef TPPOO2223_ALIMENTOS_H
#define TPPOO2223_ALIMENTOS_H

#include "Utils.h"

class Alimentos {
private:
    int id;
    string nome;
    int duracao;
    int valorNutritivo;
    int toxicidade;
    string cheiro;
public:
    Alimentos(int id,string n,int d,int vn,int t,string c):id(id),nome(n),duracao(d),valorNutritivo(vn),toxicidade(t),cheiro(c){}
    Alimentos(Alimentos &alimentos);
    string getNome() const{return nome;}
    string getCheiro() const{return cheiro;}
    int getDuracao() const{return duracao;}
    int getValorNutritivo() const{return valorNutritivo;}
    int getToxicidade() const {return toxicidade;}
    void aumentaToxicidade();
    void diminuiValorNutritivo();
    void operator= (Alimentos &alimentos);
    Alimentos(Alimentos *pAlimentos);
    int getId() const;
};

class Relva : public Alimentos {
public:
    Relva(int id):Alimentos(id,"R",20,3,0,{"Erva", "Verdura"}){};
};

class Cenoura : public Alimentos {
public:
    Cenoura(int id,int duracao):Alimentos(id,"T",duracao,4,0,"Verdura"){};
};

class Corpo : public Alimentos {
public:
    Corpo(int id,int duracao, int vn):Alimentos(id,"P",duracao,vn,0,"Carne"){};
};

class Bife : public Alimentos {
public:
    Bife(int id):Alimentos(id,"B",30,10,2,{"Carne", "Ketchup"}){};
};

class Fruta : public Alimentos {
public:
    Fruta(int id):Alimentos(id,"A",10,5,0,"Fruta"){};
};
#endif //TPPOO2223_ALIMENTOS_H
