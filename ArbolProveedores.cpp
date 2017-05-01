#include "ArbolProveedores.h"
#include <iostream>

using namespace std;



void nodoProveedor::InsertarNodoProveedor(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
	string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes)
{
	if (num<valor) {
		if (Hizq == NULL) {
			Hizq = new nodoProveedor(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
				pNumPlazas, pCantPaquetes);
		}
		else {
			Hizq->InsertarNodoProveedor(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
				pNumPlazas, pCantPaquetes);
		}
	}
	else {
		if (Hder == NULL) {
			Hder = new nodoProveedor(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
				pNumPlazas, pCantPaquetes);
		}
		else {
			Hder->InsertarNodoProveedor(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
				pNumPlazas, pCantPaquetes);
		}
	}
}

void ArbolProveedores::InsertarProveedor(string pIdDestino, int num, string pIdViaje, string pOrigen, string pDestino, string pFechaSalida,
	string pFechaLlegada, string pPrecio, string pNumPlazas, int pCantPaquetes)
{
	if (raiz == NULL) {
		raiz = new nodoProveedor(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
			pNumPlazas, pCantPaquetes);
	}
	else {
		raiz->InsertarNodoProveedor(pIdDestino, num, pIdViaje, pOrigen, pDestino, pFechaSalida, pFechaLlegada, pPrecio,
			pNumPlazas, pCantPaquetes);
	}
}