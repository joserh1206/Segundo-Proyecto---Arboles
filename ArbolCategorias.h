#pragma once
#include <iostream>
#include "NodoCategorias.h"
using namespace std;


class ArbolCategorias {
public:
	pnodoCategoria raiz;

	ArbolCategorias();

	void InsertaNodo(Categoria pCategoria);
	bool existeCategoria(nodoCategoria *R, int cod);
	void BalancearRN(nodoCategoria *R);
	void ReglaTio(nodoCategoria *tio, nodoCategoria *padre, nodoCategoria *abuelo);
	void PostordenR(nodoCategoria *R);
	nodoCategoria* getRaiz();

	void RotacionDobleIzquierda(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo);
	void RotacionDobleDerecha(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo);
	void RotacionSimpleIzquierda(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo);
	void RotacionSimpleDerecha(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo);

	bool alcanzaTransporte(nodoCategoria * R, int idTrans, int cantidad);
	double precioTransporte(nodoCategoria * R, int idTrans);
	bool restarTransporte(nodoCategoria * R, int idTrans, int cantidad);
	string eliminarTransporte(nodoCategoria * R, int idTrans);
	string infoTransporte(nodoCategoria * R, int idTrans);

	string removeNodo(nodoCategoria * R);
	string removeNodoCaso1(nodoCategoria * R);
	string removeNodoCaso2(nodoCategoria * R);
	string removeNodoCaso3(nodoCategoria * R);
	nodoCategoria * recorrerIzquierda(nodoCategoria* nodo);

	string intToString(int num);
	string inorden(nodoCategoria * R);
	friend class NodoAVL;

};
