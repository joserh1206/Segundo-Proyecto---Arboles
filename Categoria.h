#include <iostream>
#include <sstream>
#pragma once

using namespace std;

class Categoria {
public:
	string toString();
private:
	int idCategoria;
	int tipo;
	string origen;
	string destino;
	string fechaSalida;
	string horaSalida;
	string fechaLlegada;
	string horaLlegada;
	string compa�ia;
	int numeroPlazas;
	double precio;
	int cantidadCategorias;

	string toString(int num);
	string toString(double num);

	friend class logica;
	friend class nodoCategoria;
	friend class ArbolCategorias;
};
