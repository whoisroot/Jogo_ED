#pragma once
#include <iostream>
//#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

//srand(time(0));

class Hamburguer{
private:
	int Ingredientes[8];
public:
	Hamburguer();
	int retornaIngrediente(int i);
	void vazio();
	void poeIngrediente(int i);
};
