//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Alimentos.h"
#include "../Headers/Cell.h"
#include "../Headers/Reserva.h"


Alimentos::Alimentos(Alimentos &alimentos) : nome(alimentos.nome), duracao(alimentos.duracao),
                                                            valorNutritivo(alimentos.valorNutritivo), toxicidade(alimentos.toxicidade),
                                                            cheiro(alimentos.cheiro) {
    //AnimaisMortos = alimentos.AnimaisMortos;
}

void Alimentos::operator=(Alimentos &alimentos) {
    nome = alimentos.nome;
    duracao = alimentos.duracao;
    valorNutritivo = alimentos.valorNutritivo;
    toxicidade = alimentos.toxicidade;
    cheiro = alimentos.cheiro;
   // AnimaisMortos = alimentos.AnimaisMortos;
}

int Alimentos::getId() const {
    return id;
}

/*void Alimentos::elimina(Alimentos &alimento){
    // Verificar se o nome do alimento atual é "b"
    if (getNome() == "b") {
        // Verificar se a duração do alimento atual é maior ou igual a 30
        if (getDuracao() >= 30) {
            //eliminar a relva
        }
    }
}*/

//apos 75% da sua vida gera uma relva nova
void Alimentos::AddRelva(string &type,Reserva &r){
    if(type == "r") {
        if (getDuracao() % 75) {

            new Relva(id);
        }
    }
}

void Alimentos::aumentaToxicidade(Animais a, Reserva r, int simulatedTime) {
    if(getNome() == "t")
    {
       while(getToxicidade() <= 3){
           if(generate-simulatedTime == 10 || generate-simulatedTime == 20 || generate-simulatedTime == 30){
               setToxicidade(getToxicidade()+1);
           }
       }
    }
    else if(getNome() == "p")
    {
        while(getToxicidade() == 2  /* * valor nutritivo inicial*/) {
                setToxicidade(getToxicidade()+1);
        }
    }
}

void Alimentos::diminuiValorNutritivo() {
    if(getNome() == "p" || getNome() == "b")
    {
        while(getValorNutritivo() < 0) {
            setValotNutritivo(getValorNutritivo() - 1);
        }
    }
}

void Alimentos::setToxicidade(int t) {
    Alimentos::toxicidade = t;
}

void Alimentos::setValotNutritivo(int vn) {
    Alimentos::valorNutritivo = vn;
}
