#include <iostream>
#pragma once

using namespace std;

class Producto {
	int idProducto;
	double precioHabInd;
	double precioHabDob;
	int cantidadInd;
	int cantidadDob;

	friend class AATree;
};