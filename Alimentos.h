
#ifndef TP_POO_2022_2023_ALIMENTOS_H
#define TP_POO_2022_2023_ALIMENTOS_H

#include "Animais.h"
#include "Reserva.h"

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
    string getName(){return nome;}
    int getDuracao(){return duracao;}
    string getCheiro(){return cheiro;}
    void aumentaToxicidade(int toxicidade);
    void diminuiValorNutritivo(int valorNutritivo);
};


#endif //TP_POO_2022_2023_ALIMENTOS_H
