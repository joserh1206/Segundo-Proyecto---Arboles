#pragma once
#include <iostream>
#include "NodoProveedores.h"

using namespace std;
class ArbolProveedores {
public:
	pNodoProveedor raiz;

	ArbolProveedores() :raiz(NULL) {}

	void InsertarProveedor(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
		string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes);

	void InsertarNodoReservacionViaje(int num, string pIdCliente, string pIdViaje, string pNumPlazas);

	void InsertarNodoReservacionHotel(int pRv_num, string pIdCliente, string pIdViaje, string pIdHotel, string pFechaInicial, string pFechasFinal, string pPrecioHab);

	void InsertarNodoReservacionTransporte(int num, string IdCliente, string IdViaje, string IdTransporte);

	void PreordenI();
	string InordenI();
	void PostordenI();

	void InordenI_RV();
	void InordenI_RH();
	void InordenI_RT();

	void BuscarViaje();
	string BuscarDestinoViaje(string destino);

	//void Borrar(NodoArbolProveedores *nodoB, bool);
	//void BorrarBalanceado(NodoArbolProveedores *r, bool, int eliminar);

	friend class TareaProgramada2;

};

