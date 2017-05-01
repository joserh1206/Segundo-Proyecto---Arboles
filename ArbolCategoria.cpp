#include <iostream>
#include "ArbolCategorias.h"
using namespace std;


void ArbolCategorias::InsertaNodo(Categoria pCategoria)
{
	if (raiz == NULL) {
		raiz = new nodoCategoria(pCategoria, 'n', NULL);
	}
	else {
		if (!(existeCategoria(raiz, pCategoria.idCategoria))) {
			raiz->InsertaRojiNegro(pCategoria, 'r');
			BalancearRN(raiz);
		}
		else {
			cout << "El Categoria con id: " << pCategoria.idCategoria << " ya existe" << endl;
		}
	}
}



void ArbolCategorias::BalancearRN(nodoCategoria *R) {
	if (R == NULL) {
		return;
	}
	else {
		//cout<<"Nodo: "<<R->codigo<<endl;
		BalancearRN(R->Hizq);
		BalancearRN(R->Hder);
		//cout<<"Compara R y raiz. R= "<<R->codigo<<endl;
		if (R != raiz) {
			if (R->anterior->value.idCategoria != raiz->value.idCategoria) {
				nodoCategoria *padre = R->anterior;
				nodoCategoria *abuelo = padre->anterior;
				nodoCategoria *tio;
				if (abuelo->Hder != NULL && abuelo->Hder->value.idCategoria == padre->value.idCategoria) {
					tio = abuelo->Hizq;
				}
				else {
					tio = abuelo->Hder;
				}
				if (R->color == 'r' && padre->color == 'r') {
					if (tio != NULL && tio->color == 'r') {
						//APLICAR REGLA DEL TIO
						ReglaTio(tio, padre, abuelo);
					}
					else {
						//APLICAR ROTACIONES
						if (abuelo->Hder != NULL && abuelo->Hder->value.idCategoria == padre->value.idCategoria) {
							if (padre->Hizq != NULL && padre->Hizq->value.idCategoria == R->value.idCategoria) {
								//ROTACION DOBLE A LA IZQUIERDA
								RotacionDobleIzquierda(R, padre, abuelo);
							}
							else {
								//ROTACION SIMPLE A LA IZQUIERDA
								RotacionSimpleIzquierda(R, padre, abuelo);
							}
						}
						else if (abuelo->Hizq != NULL && abuelo->Hizq->value.idCategoria == padre->value.idCategoria) {
							if (padre->Hder != NULL && padre->Hder->value.idCategoria == R->value.idCategoria) {
								//ROTACION DOBLE A LA DERECHA
								RotacionDobleDerecha(R, padre, abuelo);
							}
							else {
								//ROTACION SIMPLE A LA DERECHA
								RotacionSimpleDerecha(R, padre, abuelo);
							}
						}
						else if (abuelo->Hizq->value.idCategoria == padre->value.idCategoria && padre->Hder->value.idCategoria == R->value.idCategoria) {
						}
					}
				}
			}
		}
	}
}

void ArbolCategorias::ReglaTio(nodoCategoria *tio, nodoCategoria *padre, nodoCategoria *abuelo) {
	tio->color = 'n';
	padre->color = 'n';
	if (abuelo != raiz) {
		abuelo->color = 'r';
	}
}

void ArbolCategorias::RotacionDobleIzquierda(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo) {
	nodoCategoria *bisabuelo = abuelo->anterior;
	nodoCategoria *aux = abuelo;
	if (abuelo != raiz) {
		if (bisabuelo->Hder == abuelo) {
			bisabuelo->Hder = n;
		}
		else {
			bisabuelo->Hizq = n;
		}
		n->anterior = bisabuelo;

	}
	else {
		n->anterior = NULL;
		raiz = n;
	}
	padre->anterior = n;
	padre->Hizq = n->Hder;
	n->Hder = padre;
	aux->anterior = n;
	aux->Hder = n->Hizq;
	n->Hizq = aux;
	n->color = 'n';
	aux->color = 'r';
}

void ArbolCategorias::RotacionDobleDerecha(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo) {
	nodoCategoria *bisabuelo = abuelo->anterior;
	nodoCategoria *aux = abuelo;
	if (abuelo != raiz) {
		if (bisabuelo->Hder == abuelo) {
			bisabuelo->Hder = n;
		}
		else {
			bisabuelo->Hizq = n;
		}
		n->anterior = bisabuelo;

	}
	else {
		n->anterior = NULL;
		raiz = n;
	}
	padre->anterior = n;
	padre->Hder = n->Hizq;
	n->Hizq = padre;
	aux->anterior = n;
	aux->Hizq = n->Hder;
	n->Hder = aux;
	n->color = 'n';
	aux->color = 'r';
}

void ArbolCategorias::RotacionSimpleDerecha(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo) {
	/*cout<<"Nodo: "<<n->codigo<<endl;
	cout<<"Padre: "<<padre->codigo<<endl;
	cout<<"Abuelo: "<<abuelo->codigo<<endl;*/
	nodoCategoria *bisabuelo = abuelo->anterior;
	if (abuelo != raiz) {
		if (bisabuelo->Hder == abuelo) {
			bisabuelo->Hder = padre;
		}
		else {
			bisabuelo->Hizq = padre;
		}
		padre->anterior = bisabuelo;

	}
	else {
		padre->anterior = NULL;
		raiz = padre;
		//cout<<"RAIZRSD: "<<raiz->codigo<<endl;
	}
	abuelo->Hizq = padre->Hder;
	padre->Hder = abuelo;
	abuelo->anterior = padre;

	padre->color = 'n';
	abuelo->color = 'r';
}

void ArbolCategorias::RotacionSimpleIzquierda(nodoCategoria* n, nodoCategoria* padre, nodoCategoria* abuelo) {
	nodoCategoria *bisabuelo = abuelo->anterior;
	if (abuelo != raiz) {
		if (bisabuelo->Hder == abuelo) {
			bisabuelo->Hder = padre;
		}
		else {
			bisabuelo->Hizq = padre;
		}
		padre->anterior = bisabuelo;

	}
	else {
		padre->anterior = NULL;
		raiz = padre;
	}
	abuelo->Hder = padre->Hizq;
	padre->Hizq = abuelo;
	abuelo->anterior = padre;

	padre->color = 'n';
	abuelo->color = 'r';
}

