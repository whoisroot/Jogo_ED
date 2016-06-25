#pragma once
#include <iostream>
#include "Hamburguer.h"

using namespace std;

typedef struct No{
    int ingrediente;
    No *abaixo;
    No *acima;
}No;

class Pilha{
private:
    No *Topo;
    No *Base;
    No *Atual;
    int tam;
public:
    Pilha();
    bool Inserir(int x);
    bool Remover(int x);
    bool Vazia();
    bool Cheia();
    int Percorre();
};
