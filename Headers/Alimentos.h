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
    int generate;
public:
    Alimentos(int id,string n,int d,int vn,int t,string c):id(id),nome(n),duracao(d),valorNutritivo(vn),toxicidade(t),cheiro(c){}
    Alimentos(Alimentos *alimentos);
    string getNome() const{return nome;}
    string getCheiro() const{return cheiro;}
    int getDuracao() const{return duracao;}
    int getValorNutritivo() const{return valorNutritivo;}
    int getToxicidade() const {return toxicidade;}
    //void aumentaToxicidade(Animais a,Reserva r, int simulatedTime);
    void diminuiValorNutritivo();
    void operator= (Alimentos *alimentos);
    //Alimentos(Alimentos *pAlimentos);
    int getId() const;
    //void AddRelva(string &type,Reserva &r);
    void setToxicidade(int toxicidade);
    void setValotNutritivo(int vn);
    void elimina(Alimentos &alimento);
};

class Relva : public Alimentos {
public:
    Relva(int id):Alimentos(id,"R",20,3,0,{"Erva", "Verdura"}){};
    //faz aparecer outra relva 75% numa posicao proximo entre 4 e 8, se ja estiver la algum alimento tenta again no instante seguinte
};

class Cenoura : public Alimentos {
public:
    Cenoura(int id,int duracao):Alimentos(id,"T",duracao,4,0,"Verdura"){};
    //toxicidade aumenta 1 ponto a cada 10 instantes até ao máximo de 3
};

class Corpo : public Alimentos {
public:
    Corpo(int id,int duracao, int vn):Alimentos(id,"P",duracao,vn,0,"Carne"){};
    //cada instante diminui o seu valor nutritivo em 1 unidade e aumenta o seu valor de toxicidade em 1.
    // O valor de toxicidade pára de aumentar quando passarem tantos instantes como duas vezes o valor nutritivo inicial
};

class Bife : public Alimentos {
public:
    Bife(int id):Alimentos(id,"B",30,10,2,{"Carne", "Ketchup"}){};
    //Duração: 30. Passados estes instantes desaparece.
    //A cada instante diminui o seu valor nutritivo em 1 unidade até chegar a zero.

};

class Fruta : public Alimentos {
public:
    Fruta(int id):Alimentos(id,"A",10,5,0,"Fruta"){};
};
#endif //TPPOO2223_ALIMENTOS_H
