#include <iostream>
#include "Pilha.h"

using namespace std;

Pilha::Pilha(){
    Topo = NULL;
    Base = NULL;
    Atual = NULL;
    tam = 0;
}

bool Pilha::Vazia(){
    if (Topo == NULL)
        return true;
    else
        return false;
}

bool Pilha::Cheia(){
    if(tam > 14)
        return true;
    else
        return false;
}

bool Pilha::Inserir(int x){
    No *q;
    if(Cheia())
        return false;
    else if(tam == 0){
        tam++;
        q = new No;
        q->ingrediente = x;
        q->abaixo = NULL;
        q->acima = NULL;
        Topo = q;
        Base = q;
        return true;
    }
    else{
        tam++;
        q = new No;
        q->ingrediente = x;
        q->abaixo = Topo;
        q->acima = NULL;
        Topo->acima = q;
        Topo = q;
        return true;
    }
}

bool Pilha::Remover(int x){
    No *q;
    if(Vazia())
        return false;
    else{
        q = Topo;
        x = Topo->ingrediente;
        Topo->abaixo->acima = Topo->acima;
        Topo = Topo->abaixo;
        delete q;
        return true;
    }
}

int Pilha::Percorre(){
    int x;
    if(Atual == NULL){
        Atual = Base;
        return 0;
    }
    else{
        x = Atual->ingrediente;
        Atual = Atual->acima;
        return x+1;

    }
}
