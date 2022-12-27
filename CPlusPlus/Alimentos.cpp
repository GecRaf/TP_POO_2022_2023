//
// TP_2223_POO || Rafael Couto 2019142454 || Rafaela Oliveira 2019127935
//

#include "../Headers/Alimentos.h"

void Alimentos::aumentaToxicidade() {}
void Alimentos::diminuiValorNutritivo() {}

Alimentos::Alimentos(Alimentos &alimentos) : nome(alimentos.nome), duracao(alimentos.duracao),
                                                            valorNutritivo(alimentos.valorNutritivo), toxicidade(alimentos.toxicidade),
                                                            cheiro(alimentos.cheiro) {
    AnimaisMortos = alimentos.AnimaisMortos;
}

void Alimentos::operator=(Alimentos &alimentos) {
    nome = alimentos.nome;
    duracao = alimentos.duracao;
    valorNutritivo = alimentos.valorNutritivo;
    toxicidade = alimentos.toxicidade;
    cheiro = alimentos.cheiro;
    AnimaisMortos = alimentos.AnimaisMortos;
}

int Alimentos::getId() const {
    return id;
}
