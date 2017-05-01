#include "Categoria.h"
string Categoria::toString(double num) {
	std::ostringstream strs;
	strs << num;
	std::string str = strs.str();
	return str;
}

string Categoria::toString(int num) {
	stringstream ss;
	ss << num;
	return ss.str();
}

string Categoria::toString() {
	string aux = "";
	aux += "\nID: " + toString(idCategoria);
	aux += "\nTipo: " + toString(tipo);
	aux += "\nOrigen: " + origen;
	aux += "\nDestino: " + destino;
	aux += "\nFecha de salida: " + fechaSalida;
	aux += "\nHora de salida: " + horaSalida;
	aux += "\nFecha de llegada: " + fechaLlegada;
	aux += "\nHora de llegada: " + horaLlegada;
	aux += "\nCompania: " + compa�ia;
	aux += "\nPrecio: " + toString(precio);
	return aux;
}