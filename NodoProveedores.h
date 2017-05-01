#pragma once
#include <iostream>
using namespace std;

class nodoProveedor {
public:

	nodoProveedor(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida, string pFechaLlegada,
		string pPrecio, string pNumPlazas, int pCantPaquetes,
		nodoProveedor *der = NULL, nodoProveedor *izq = NULL, nodoProveedor *sig = NULL,
		nodoProveedor *ant = NULL) :
		Hizq(izq), Hder(der), siguiente(sig), anterior(ant) {

		idDestino = pIdDestino;
		valor = num;
		idViaje = pIdViaje;
		origen = pOrigen;
		destino = pDestino;
		fechaSalida = pFechaSalida;
		fechaLlegada = pFechaLlegada;
		precio = pPrecio;
		numPlazas = pNumPlazas;
		cantPaquetes = pCantPaquetes;
	}

	string idDestino;
	int valor; // num
	string idViaje;
	string origen;
	string destino;
	string fechaSalida;
	string fechaLlegada;
	string precio;
	string numPlazas;
	int cantPaquetes;

	nodoProveedor *Hizq, *Hder, *siguiente, *anterior;

	void InsertarNodoProveedor(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
		string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes);

	friend class BinarioBusqueda;

};

typedef nodoProveedor *pNodoProveedor;
