#include <stdlib.h>
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ArbolSupermercado.h"

void PilaAVL::PushAVL(pnodoAVL v)
{
	if (VaciaAVL()) {
		plistaAVL = v;
	}
	else {
		NodoAVL *aux = plistaAVL;
		while (aux->siguiente) {
			aux = aux->siguiente;
		}
		aux->siguiente = v;
		v->anterior = aux;

	}
}

pnodoAVL PilaAVL::PopAVL()
{
	NodoAVL *borrar = NULL;
	NodoAVL *salida = NULL;
	if (VaciaAVL()) {
		cout << "Pila Vacia" << endl;
	}
	else {
		borrar = plistaAVL;
		while (borrar->siguiente) {
			borrar = borrar->siguiente;
		}
		if (SizeAVL()>1) {
			salida = borrar;
			borrar->anterior->siguiente = NULL;
			borrar = NULL;
			delete borrar;
		}
		else {
			salida = plistaAVL;
			plistaAVL = NULL;
		}
	}
	return salida;
}

int PilaAVL::SizeAVL() {
	while (plistaAVL && plistaAVL->anterior) plistaAVL = plistaAVL->anterior;
	int cont = 0;
	NodoAVL *aux;
	aux = plistaAVL;
	while (aux) {
		cont++;
		aux = aux->siguiente;
	}
	return cont;
}

void PilaAVL::MostrarAVL() {
	if (VaciaAVL()) {
		cout << "Vacia";
	}
	NodoAVL *aux = plistaAVL;
	while (aux) {
		cout << aux->valor << " - ";
		aux = aux->siguiente;
	}
}


void NodoAVL::InsertaAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
	string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble)
{
	if (num<valor) {
		if (Hizq == NULL) {
			Hizq = new NodoAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
				pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
		}
		else {
			Hizq->InsertaAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
				pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
		}
	}
	else {
		if (Hder == NULL) {
			Hder = new NodoAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
				pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
		}
		else {
			Hder->InsertaAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
				pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
		}
	}
}

void AVL::InsertaNodoAVL(string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
	string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble)
{
	if (raiz == NULL) {
		raiz = new NodoAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
			pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
	}
	else {
		raiz->InsertaAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
			pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
	}
}

void AVL::PreordenI() {
	NodoAVL *Act = raiz;
	PilaAVL p;
	while (p.VaciaAVL() == false || (Act != NULL)) {
		if (Act != NULL) {
			cout << "idHotel: " << Act->valor << endl;
			cout << "Destino: " << Act->idDestino << endl;
			cout << "Nombre: " << Act->nombre << endl;
			cout << "Categoria: " << Act->categoria << endl;
			cout << "Ciudad:" << Act->ciudad << endl;
			cout << "PrecioHabIndiv: " << Act->precioHabIndiv << endl;
			cout << "PrecioHabDoble: " << Act->precioHabDoble << endl;
			cout << "CantHabIndiv: " << Act->cantHabIndiv << endl;
			cout << "CantHabDoble: " << Act->cantHabDoble << endl;
			cout << "\n" << endl;
			p.PushAVL(Act);
			Act = Act->Hizq;
		}
		else {
			Act = p.PopAVL();
			Act = Act->Hder;
		}
	}
}


string AVL::InordenI() {
	NodoAVL *Act = raiz;
	PilaAVL p;
	bool band = true;
	string mostrado;

	while (band) {

		while (Act != NULL) {
			p.PushAVL(Act);
			Act = Act->Hizq;
		}
		if (!p.VaciaAVL()) {
			Act = p.PopAVL();

			mostrado += "\nidHotel: " + Act->idHotel;
			mostrado += "\nNombre: " + Act->nombre;
			mostrado += "\nCategoria: " + Act->categoria;
			mostrado += "\nCiudad: " + Act->ciudad;
			mostrado += "\nPrecioHabIndiv: " + Act->precioHabIndiv;
			mostrado += "\nPrecioHabDoble: " + Act->precioHabDoble;

			string stringcantHabIndiv;
			string stringcantHabDoble;

			int intCantHabIndiv = Act->cantHabIndiv;
			stringcantHabIndiv = to_string(intCantHabIndiv);

			int intCantHabDoble = Act->cantHabDoble;
			stringcantHabDoble = to_string(intCantHabDoble);

			mostrado += "\nCantHabIndiv: " + stringcantHabIndiv;
			mostrado += "\nCantHabDoble: " + stringcantHabDoble;
			mostrado += "\n";

			Act = Act->Hder;
		}
		if (p.VaciaAVL() && Act == NULL) {
			break;
		}
	}

	return mostrado;
}

void AVL::PostordenI() {
	NodoAVL *Act = raiz;
	PilaAVL p;
	PilaAVL p2;
	while (!p.VaciaAVL() || Act != NULL) {
		if (Act != NULL) {
			p2.PushAVL(new NodoAVL(Act->idDestino, Act->valor, Act->idHotel, Act->nombre, Act->categoria, Act->ciudad, Act->precioHabIndiv,
				Act->precioHabDoble, Act->cantHabIndiv, Act->cantHabDoble));
			p.PushAVL(Act);
			Act = Act->Hder;
		}
		else {
			Act = p.PopAVL();
			Act = Act->Hizq;
		}
	}
	while (!p2.VaciaAVL()) {
		NodoAVL *salida = p2.PopAVL();
		cout << "idHotel: " << salida->valor << endl;
		cout << "idDestino: " << salida->idDestino << endl;
		cout << "Nombre: " << salida->nombre << endl;
		cout << "Categoria: " << salida->categoria << endl;
		cout << "Ciudad: " << salida->ciudad << endl;
		cout << "PrecioHabIndiv: " << salida->precioHabIndiv << endl;
		cout << "PrecioHabDoble: " << salida->precioHabDoble << endl;
		cout << "CantHabIndiv: " << salida->cantHabIndiv << endl;
		cout << "CantHabDoble: " << salida->cantHabDoble << endl;
		cout << "\n" << endl;
	}
}

void AVL::Equilibrar1(NodoAVL* n, bool Hh) {
	NodoAVL *n1;
	switch (n->FB) {
	case -1: n->FB = 0;
		break;
	case 0: n->FB = 1;
		Hh = false;
		break;
	case 1: n1 = n->Hder;
		if (n1->FB >= 0) {
			if (n1->FB = 0) {
				Hh = false;
				RotacionSimpleDerecha(n, n1);
			}
			else {
				RotacionDobleDerecha(n, n1);
			}
		}
	}
}

void AVL::Equilibrar2(NodoAVL* n, bool Hh) {
	NodoAVL *n1;
	switch (n->FB) {
	case 1: n->FB = 0;
		break;
	case 0: n->FB = 1;
		Hh = false;
		break;
	case -1: n1 = n->Hizq;
		if (n1->FB <= 0) {
			if (n1->FB = 0) {
				Hh = false;
				RotacionSimpleIzquierda(n, n1);
			}
			else {
				RotacionDobleIzquierda(n, n1);
			}
		}
	}
}

void AVL::InsertarBalanceado(pNodoAVL ra, bool Hh, string pIdDestino, int num, string pIdHotel, string pNombre, string pCategoria, string pCiudad, string pPrecioHabIndiv,
	string pPrecioHabDoble, int pCantHabIndiv, int pCantHabDoble) {
	pNodoAVL n1;

	if (raiz == NULL) {
		ra = new NodoAVL(pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
			pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);
		cout << ra->valor << endl;
		Hh = true;
	}
	else {
		cout << endl;
		if (num <= ra->valor) {
			InsertarBalanceado(ra->Hizq, Hh, pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
				pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);

			if (Hh) {
				switch (ra->valor) {
				case 1: ra->FB = 0;
					Hh = false;
					break;
				case 0: ra->FB = -1;
					break;
				case -1: n1 = ra->Hizq;
					if (n1->FB = -1) {
						RotacionSimpleIzquierda(ra, n1);
					}
					else {
						RotacionDobleIzquierda(ra, n1);
					}
					Hh = false;
					break;
				}
			}
		}
		else {
			if (num>ra->valor) {
				InsertarBalanceado(ra->Hder, Hh, pIdDestino, num, pIdHotel, pNombre, pCategoria, pCiudad, pPrecioHabIndiv,
					pPrecioHabDoble, pCantHabIndiv, pCantHabDoble);

				if (Hh) {
					switch (ra->FB) {
					case -1: ra->FB = 0;
						Hh = false;
						break;
					case 0: ra->FB = 1;
						break;
					case 1:n1 = ra->Hder;
						if (n1->FB = 1) {
							RotacionSimpleDerecha(ra, n1);
						}
						else {
							RotacionDobleDerecha(ra, n1);
						}
						Hh = false;
						break;
					}
				}
			}
		}
	}
}

void AVL::RotacionDobleIzquierda(NodoAVL* n, NodoAVL* n1) {
	NodoAVL *n2;
	n2 = n1->Hder;
	n->Hizq = n2->Hder;
	n2->Hder = n;
	n1->Hder = n2->Hizq;
	n2->Hizq = n1;

	if (n2->FB == 1) {
		n1->FB = -1;
	}
	else {
		n1->FB = 0;
	}
	if (n2->FB == -1) {
		n->FB = 1;
	}
	else {
		n->FB = 0;
	}
	n2->FB = 0;
	n = n2;
}

void AVL::RotacionDobleDerecha(NodoAVL* n, NodoAVL* n1) {
	NodoAVL *n2;
	n2 = n1->Hizq;
	n->Hder = n2->Hizq;
	n2->Hizq = n;
	n1->Hizq = n2->Hder;
	n2->Hder = n1;

	if (n2->FB == 1) {
		n->FB = -1;
	}
	else {
		n->FB = 0;
	}
	if (n2->FB == -1) {
		n1->FB = 1;
	}
	else {
		n1->FB = 0;
	}
	n2->FB = 0;
	n = n2;
}

void AVL::RotacionSimpleDerecha(NodoAVL* n, NodoAVL* n1) {
	n->Hder = n1->Hizq;
	n1->Hizq = n;

	if (n1->FB == 1) {
		n->FB = 0;
		n1->FB = 0;
	}
	else {
		n->FB = 1;
		n1->FB = -1;
	}
	n = n1;
}

void AVL::RotacionSimpleIzquierda(NodoAVL* n, NodoAVL* n1) {
	n->Hizq = n1->Hder;
	n1->Hder = n;

	if (n1->FB == -1) {
		n->FB = 0;
		n1->FB = 0;
	}
	else {
		n->FB = -1;
		n1->FB = -1;
	}
	n = n1;
}

/*
int main(){
AVL B;
B.InsertaNodoAVL(12);
B.InsertaNodoAVL(10);
B.InsertaNodoAVL(9);
B.InsertaNodoAVL(8);
B.InsertaNodoAVL(7);
B.InsertaNodoAVL(4);
B.InsertaNodoAVL(5);
B.InsertaNodoAVL(1);
B.InsertaNodoAVL(3);

B.InordenI();

}
*/
