#pragma once
#include <iostream>
#include "NodoCliente.h"

using namespace std;

class ArregloClaves
{
public:

	ArregloClaves() {

		for (int k = 0; k < 5; k++) {
			arregloClaves[k] = NULL;
		}
	}

	void InsertarClave(pNodoCliente Clave, int Numero);
	int ObtenerClave(int Numero);
	pNodoCliente ObtenerApuntadorClave(int Numero);


private:

	pNodoCliente arregloClaves[5];

	friend class Pagina;
};
typedef ArregloClaves *ApuntadorClaves;

class Pagina;
typedef Pagina *ApuntadorPagina;



class ArregloRamas
{
public:

	ArregloRamas() {
		for (int k = 0; k < 5; k++) {
			arregloRamas[k] = NULL;
		}
	}
	void InsertarRama(ApuntadorPagina Rama, int Numero);
	ApuntadorPagina ObtenerRama(int Numero);

private:

	ApuntadorPagina arregloRamas[5];

	friend class Pagina;
};

typedef ArregloRamas *ApuntadorRamas;


class Pagina
{
public:

	Pagina() {
		cuenta = 0;
		Claves = new ArregloClaves();
		Ramas = new ArregloRamas();
		EmpujarArriba = false;
		X = 0;
		Xr = NULL;
		K = 0;
		Esta = false;
		llamadas = 0;
	}
	//private:

	int cuenta;
	ApuntadorClaves Claves;
	ApuntadorRamas Ramas;
	bool EmpujarArriba;
	int X;
	ApuntadorPagina Xr;
	int K;
	bool Esta;
	int llamadas;

	friend class ArbolB;

};


class ArbolB
{
public:

	ArbolB() { raizB = NULL; }
	bool BVacio() { return raizB == NULL; }
	void EstablecerRaizB(ApuntadorPagina Raiz);
	void IniciarInsercionB(int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono);
	ApuntadorPagina InsertarB(ApuntadorPagina Raiz, int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono);
	ApuntadorPagina EmpujarB(ApuntadorPagina Raiz, int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono);
	ApuntadorPagina BuscarNodoB(ApuntadorPagina Raiz, int Numero);
	ApuntadorPagina MeterHojaB(ApuntadorPagina Raiz, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono);
	ApuntadorPagina DividirNodoB(ApuntadorPagina Raiz, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono);
	void IniciarRecorridoB();
	void RecorridoInordenB(ApuntadorPagina Raiz);


	//private:

	ApuntadorPagina raizB;

};


class PilaB {
public:
	PilaB() : plistaB(NULL) {}

	void Push(pNodoCliente);

	bool Vacia() { return plistaB == NULL; }
	pNodoCliente Pop();
	int Size();

	pNodoCliente plistaB;
};





