#include <iostream>
#include "Fila.h"

using namespace std;

Fila::Fila(){
	Primeiro = NULL;
	Atual = NULL;
	tam = 0;
}

bool Fila::Vazia(){
	if (Primeiro/*->next*/ == NULL)
		return true;
	else
		return false;
}

bool Fila::Cheia(){
	if (tam > 10)
		return true;
	else
		return false;
}

bool Fila::Inserir(Hamburguer x){
	Node *q;
	if (Cheia())
		return false;
	else{
		tam++;
		q = new Node;
		q->h = x;
		q->next = NULL;
		if (Vazia()){
			Primeiro = q;
			Atual = q;
		}
		else{
			Atual->next = q;
			Atual = q;
		}
		return true;
	}
}

bool Fila::Remover(Hamburguer x){
	Node *q;
	if (Vazia())
		return false;
	else{
		tam--;
		q = Primeiro;
		x = Primeiro->h;
		Primeiro = Primeiro->next;
		delete q;
		return true;
	}
}
