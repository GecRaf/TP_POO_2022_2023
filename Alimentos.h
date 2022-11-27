
#ifndef TPPOO2223_ALIMENTOS_H
#define TPPOO2223_ALIMENTOS_H

#include "Utils.h"

class Alimentos {
private:
    string const nome;
    int duracao;
    int valorNutritivo;
    int toxicidade;
    string const cheiro;
    vector<string>AnimaisMortos;
public:
    Alimentos(string n,int d,int vn,int t,string c):nome(n),duracao(d),valorNutritivo(vn),toxicidade(t),cheiro(c){}
    string getNome() const{return nome;}
    string getCheiro() const{return cheiro;}
    int getDuracao() const{return duracao;}
    int getValorNutritivo() const{return valorNutritivo;}
    int getToxicidade() const {return toxicidade;}
    void aumentaToxicidade();
    void diminuiValorNutritivo();
};

class Relva : public Alimentos {
private:

public:
    Relva(string n,int d,int vn,int t,string c):Alimentos(n = "r",d = 20,vn = 3,t = 0,c = {"erva", "verdura"}){};
    // TODO: Create another Relva after 75% of lifetime in a random position, between 4 and 8 units away from the current one
};

class Cenoura : public Alimentos {
private:

public:
    Cenoura(string n,int d,int vn,int t,string c):Alimentos(n = "cout",d,vn = 4,t = 0,c = "verdura"){};
    // TODO: Increase toxicity 1 point every 10 instances until a max of 3.
};

class Corpo : public Alimentos {
private:

public:
    Corpo(string n,int d,int vn,int t,string c):Alimentos(n = "p",d,vn,t = 0,c = "carne"){};
    // TODO: Decrease nutrition value 1 point and increase toxicity 1 point every instance. Toxicity stops increasing after (instances > [2 * inicial nutrition value])
};

class Bife : public Alimentos {
private:

public:
    Bife(string n,int d,int vn,int t,string c):Alimentos(n = "b",d = 30,vn = 10,t = 2,c = {"carne", "ketchup"}){};
};

class Fruta : public Alimentos {
private:

public:
    Fruta(string n,int d,int vn,int t,string c):Alimentos(n = "f",d = 10,vn = 5,t = 0,c = "fruta"){};
};

#endif //TPPOO2223_ALIMENTOS_H
