#include <iostream>
#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include "NodoCliente.h"
#include "ArbolClientes.h"


void ArregloClaves::InsertarClave(pNodoCliente Clave, int Numero)
{
	arregloClaves[Numero] = Clave;
}

int ArregloClaves::ObtenerClave(int Numero)
{
	pNodoCliente Clave;
	Clave = arregloClaves[Numero];
	int numero = Clave->numero;
	return numero;
}

pNodoCliente ArregloClaves::ObtenerApuntadorClave(int Numero)
{
	pNodoCliente Clave;
	Clave = arregloClaves[Numero];
	return Clave;
}






void ArregloRamas::InsertarRama(ApuntadorPagina Rama, int Numero)
{
	arregloRamas[Numero] = Rama;
}

ApuntadorPagina ArregloRamas::ObtenerRama(int Numero)
{
	ApuntadorPagina AP;
	AP = arregloRamas[Numero];
	return AP;
}


void ArbolB::EstablecerRaizB(ApuntadorPagina Raiz)
{
	raizB = Raiz;
}

void ArbolB::IniciarInsercionB(int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono)
{
	ApuntadorPagina Raiz = raizB;
	raizB = InsertarB(Raiz, Numero, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
}

ApuntadorPagina ArbolB::InsertarB(ApuntadorPagina Raiz, int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono)
{
	ApuntadorPagina P = NULL;

	Raiz = EmpujarB(Raiz, Numero, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
	if (Raiz->EmpujarArriba == true) {
		P = new Pagina();
		P->cuenta = 1;
		pNodoCliente Auxiliar = new NodoCliente(Raiz->X, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
		P->Claves->InsertarClave(Auxiliar, 1);
		P->Ramas->InsertarRama(Raiz->Xr, 1);
		if (Raiz->llamadas == 1) {
			P->Ramas->InsertarRama(NULL, 0);
		}
		else {
			P->Ramas->InsertarRama(Raiz, 0);
		}

		Raiz = P;
	}
	return Raiz;


}

ApuntadorPagina ArbolB::EmpujarB(ApuntadorPagina Raiz, int Numero, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono)
{
	if (Raiz == NULL) {
		Raiz = new Pagina();
		Raiz->EmpujarArriba = true;
		Raiz->X = Numero;
		Raiz->Xr = NULL;
		Raiz->llamadas++;
		return Raiz;
	}

	else {
		Raiz = BuscarNodoB(Raiz, Numero);
		if (Raiz->Esta) {
			cout << "Elemento Repetido" << endl;
		}
		if (Raiz->K == 0) {

		}
		ApuntadorPagina Aux;
		Aux = EmpujarB(Raiz->Ramas->ObtenerRama(Raiz->K), Numero, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
		Raiz->EmpujarArriba = Aux->EmpujarArriba;
		Raiz->X = Aux->X;
		Raiz->Xr = Aux->Xr;
		if (Raiz->EmpujarArriba == true) {
			if (Raiz->cuenta < 4) {
				Raiz->EmpujarArriba = false;
				Raiz = MeterHojaB(Raiz, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
			}
		}
		else {
			Raiz->EmpujarArriba = true;
			Raiz = DividirNodoB(Raiz, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);

		}
		return Raiz;

	}
}

ApuntadorPagina ArbolB::BuscarNodoB(ApuntadorPagina Raiz, int Numero)
{
	int PClave1 = Raiz->Claves->ObtenerClave(1);
	if (Numero < PClave1) {
		Raiz->Esta = false;
		Raiz->K = 0;
	}
	else {
		Raiz->K = Raiz->cuenta;
		while (Numero < Raiz->Claves->ObtenerClave(Raiz->K) && Raiz->K > 1) {
			Raiz->K--;
		}
		if (Numero == Raiz->Claves->ObtenerClave(Raiz->K)) {
			Raiz->Esta = true;
		}
	}
	Raiz->llamadas++;
	return Raiz;
}

ApuntadorPagina ArbolB::MeterHojaB(ApuntadorPagina Raiz, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono)
{
	int I;
	I = Raiz->cuenta;
	while (I >= Raiz->K + 1) {
		Raiz->Claves->InsertarClave(Raiz->Claves->ObtenerApuntadorClave(I), I + 1);
		Raiz->Ramas->InsertarRama(Raiz->Ramas->ObtenerRama(I), I + 1);
		I--;
	}
	pNodoCliente X = new NodoCliente(Raiz->X, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
	Raiz->Claves->InsertarClave(X, Raiz->K + 1);
	Raiz->Ramas->InsertarRama(Raiz->Xr, Raiz->K + 1);
	Raiz->cuenta++;


	return Raiz;


}

ApuntadorPagina ArbolB::DividirNodoB(ApuntadorPagina Raiz, string pIdCliente, string pNombre, string pApellido, string pCiudad, string pTelefono)
{
	int I;
	int Posmda;
	ApuntadorPagina Mder;
	int Mda;

	if (Raiz->K <= 2) {
		Posmda = 2;
	}
	else {
		Posmda = 3;
	}

	Mder = new Pagina();
	I = Posmda + 1;
	while (I <= 4) {
		Mder->Claves->InsertarClave(Raiz->Claves->ObtenerApuntadorClave(I), I - Posmda);
		Mder->Ramas->InsertarRama(Raiz->Ramas->ObtenerRama(I), I - Posmda);
		I++;
	}
	Mder->cuenta = 4 - Posmda;
	Raiz->cuenta = Posmda;

	if (Raiz->K <= 2) {
		Raiz = MeterHojaB(Raiz, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
	}
	else {
		Mder->X = Raiz->X;
		Mder->Xr = Raiz->Xr;
		Mder->K = Raiz->K - Posmda;
		Mder = MeterHojaB(Mder, pIdCliente, pNombre, pApellido, pCiudad, pTelefono);
	}
	Mda = Raiz->Claves->ObtenerClave(Raiz->cuenta);
	Raiz->X = Mda;
	Mder->Ramas->InsertarRama(Raiz->Ramas->ObtenerRama(Raiz->cuenta), 0);
	Raiz->cuenta--;
	Raiz->Xr = Mder;
	return Raiz;
}

void ArbolB::IniciarRecorridoB()
{
	ApuntadorPagina Raiz = raizB;
	RecorridoInordenB(Raiz);
}

void ArbolB::RecorridoInordenB(ApuntadorPagina Raiz) {
	if (Raiz == NULL) {
		return;
	}
	else {
		RecorridoInordenB(Raiz->Ramas->ObtenerRama(0));
		int I = 1;
		while (I <= Raiz->cuenta) {
			pNodoCliente Recorrido = Raiz->Claves->ObtenerApuntadorClave(I);

			cout << "idCliente: " << Recorrido->numero << endl;
			cout << "Nombre: " << Recorrido->nombre << endl;
			cout << "Apellido: " << Recorrido->apellido << endl;
			cout << "Ciudad: " << Recorrido->ciudad << endl;
			cout << "Telefono: " << Recorrido->telefono << endl;
			cout << "\n" << endl;

			RecorridoInordenB(Raiz->Ramas->ObtenerRama(I));

			I++;
		}
	}
}


//-----------Pila-----------//
void PilaB::Push(pNodoCliente v)
{
	if (Vacia()) {
		plistaB = v;
	}
	else {
		NodoCliente *aux = plistaB;
		while (aux->siguiente) {
			aux = aux->siguiente;
		}
		aux->siguiente = v;
		v->anterior = aux;

	}
}

pNodoCliente PilaB::Pop()
{
	NodoCliente *borrar = NULL;
	NodoCliente *salida = NULL;
	if (Vacia()) {
		cout << "Pila Vacia" << endl;
	}
	else {
		borrar = plistaB;
		while (borrar->siguiente) {
			borrar = borrar->siguiente;
		}
		if (Size()>1) {
			salida = borrar;
			borrar->anterior->siguiente = NULL;
			borrar = NULL;
			delete borrar;
		}
		else {
			salida = plistaB;
			plistaB = NULL;
		}
	}
	return salida;
}

int PilaB::Size() {
	while (plistaB && plistaB->anterior) plistaB = plistaB->anterior;
	int cont = 0;
	NodoCliente *aux;
	aux = plistaB;
	while (aux) {
		cont++;
		aux = aux->siguiente;
	}
	return cont;
}

/*
int main(){

ArbolB Arbol;
Arbol.IniciarInsercionB(12,"Fabricio", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(32,"Jose", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(13,"Oscar", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(1245,"Luis", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(16,"Maria", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(78,"Valeria", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(20,"asdsd", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(345,"adss", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(234,"asdsa", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(21,"fsaf", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(1500,"safas", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(679,"Vsfa", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(86,"afas", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(97,"afsa", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(123,"Vsffsa", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(470,"asfasf", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(111,"asfas", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(1341,"Vsfsf", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(112,"sfasf", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(367,"sfasf", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(528,"asf", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(1438,"Vasfas", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(1191,"sff", "ks", "8yg", "pojih", "luvs");
Arbol.IniciarInsercionB(1,"Valeria", "ks", "8yg", "pojih", "luvs");
//Arbol.IniciarRecorridoB();

//cin.get();

return 0;
}*/
