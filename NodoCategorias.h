#pragma once
#include <iostream>
#include "Categoria.h"
using namespace std;

class nodoCategoria {
public:

	nodoCategoria(Categoria pCategoria, char pColor, nodoCategoria *ant) {
		value = pCategoria;
		color = pColor;
		anterior = ant;
		Hder = NULL;
		Hizq = NULL;
		siguiente = NULL;
	}

	Categoria value;
	char color;
	nodoCategoria *Hizq, *Hder, *siguiente, *anterior;

	friend class RojiNegro;

	void InsertaRojiNegro(Categoria pCategoria, char col);
};

typedef nodoCategoria *pnodoCategoria;


void nodoCategoria::InsertaRojiNegro(Categoria pCategoria, char col)
{
	if (pCategoria.idCategoria<value.idCategoria) {
		if (Hizq == NULL) {
			Hizq = new nodoCategoria(pCategoria, col, this);
		}
		else {
			Hizq->InsertaRojiNegro(pCategoria, col);
		}
	}
	else {
		if (Hder == NULL) {
			Hder = new nodoCategoria(pCategoria, col, this);
		}
		else {
			Hder->InsertaRojiNegro(pCategoria, col);
		}
	}
}
