#pragma once
#include "Producto.h"
class NodoProducto
{
public:
	NodoProducto() :
		left(nullptr), right(nullptr), level(1) {}

	NodoProducto(Producto & e, NodoProducto *lt, NodoProducto *rt, int lv = 1)
		:value(e), left(lt), right(rt), level(lv) {}

	Producto getValue() { return value; }

private:
	Producto value;
	NodoProducto *left;
	NodoProducto *right;
	int level;

	friend class AATree;
};