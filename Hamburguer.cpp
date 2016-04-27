#include <iostream>
#include "Hamburguer.h"

using namespace std;

Hamburguer::Hamburguer(){
	// Parte de baixo do pão
	Ingredientes[0] = 1;
	// Parte de cima do pão
	Ingredientes[7] = 1;
	// Hamburguer(es)
	Ingredientes[1] = rand() %3+1;
	// Queijo
	Ingredientes[2] = rand() %3;
	// Presunto
	Ingredientes[3] = rand() %3;
	// Alface
	Ingredientes[4] = rand() %2;
	// Tomate
	Ingredientes[5] = rand() %2;
	// Cebola
	Ingredientes[6] = rand() %2;
}

int Hamburguer::retornaIngrediente(int i){
    return Ingredientes[i];
}

void Hamburguer::vazio(){
    int i;
    for(i = 0; i < 8; i++){
        Ingredientes[i] = 0;
    }
}

void Hamburguer::poeIngrediente(int i){
    int X = Ingredientes[i];
    X++;
    cout << "Antes: " << i << " = " << Ingredientes[i] << "\n X = " << X << endl;
    Ingredientes[i] = X;
    cout << "Depois: " << i << " = " << Ingredientes[i]<< endl;
}
