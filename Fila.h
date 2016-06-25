#pragma once
#include <iostream>
#include "Hamburguer.h"

using namespace std;

typedef struct Node{
	Hamburguer h;
	Node *next;
}Node;

class Fila{
private:
	Node *Primeiro;
	Node *Atual;
	int tam;
public:
	Fila();
	bool Inserir(Hamburguer x);
	Hamburguer Remover(bool fun);
	bool Vazia();
	bool Cheia();
	int atualRetornaIngrediente(int i);
};
