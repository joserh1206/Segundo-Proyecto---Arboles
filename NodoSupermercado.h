#pragma once
#include <iostream>


using namespace std;

class NodoAVL {
public:

	NodoAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
		string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble, NodoAVL *der = NULL, NodoAVL *izq = NULL,
		NodoAVL *sig = NULL, NodoAVL *ant = NULL) :
		Hizq(izq), Hder(der), siguiente(sig), anterior(ant), FB(0) {

		idDestino = pIdDestino;
		valor = num;
		idHotel = pIdHotel;
		nombre = pNombre;
		categoria = pCategoria;
		ciudad = pCiudad;
		precioHabIndiv = pPrecioHabIndiv;
		precioHabDoble = pPrecioHabDoble;
		cantHabIndiv = pCantHabIndiv;
		cantHabDoble = pCantHabDoble;
	

	}

	string idDestino;
	int valor;
	string idHotel;
	string nombre;
	string categoria;
	string ciudad;
	string precioHabIndiv;
	string precioHabDoble;
	int cantHabIndiv;
	int cantHabDoble;
	int FB;

	NodoAVL *Hizq, *Hder, *siguiente, *anterior;

	void InsertaAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
		string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble);


	friend class AVL;
	friend class TareaProgramada2;
	friend class NodoBinarioBusqueda;

};

typedef NodoAVL *pnodoAVL;
typedef NodoAVL *pNodoAVL;
