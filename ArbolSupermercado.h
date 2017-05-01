#pragma once
#include <iostream>
#include "NodoSupermercado.h"
using namespace std;

class PilaAVL {
public:
	PilaAVL() : plistaAVL(NULL) {}

	void PushAVL(pnodoAVL);
	void MostrarAVL();
	bool VaciaAVL() { return plistaAVL == NULL; }
	pnodoAVL PopAVL();
	int SizeAVL();

	pnodoAVL plistaAVL;
};

class AVL {
public:
	pNodoAVL raiz;

	AVL() :raiz(NULL) {}

	void InsertaNodoAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
		string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble);
	void PreordenI();
	string InordenI();
	void PostordenI();
	bool Hh;
	//void Borrar(NodoAVL *nodoB, bool);
	//void BorrarBalanceado(NodoAVL *r, bool, int eliminar);
	void Equilibrar1(NodoAVL *n, bool);
	void Equilibrar2(NodoAVL *n, bool);
	void InsertarBalanceado(NodoAVL *r, bool, string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
		string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble);
	void RotacionDobleIzquierda(NodoAVL *n1, NodoAVL *n2);
	void RotacionDobleDerecha(NodoAVL *n1, NodoAVL *n2);
	void RotacionSimpleIzquierda(NodoAVL *n1, NodoAVL *n2);
	void RotacionSimpleDerecha(NodoAVL *n1, NodoAVL *n2);

	friend class TareaProgramada2;
};
