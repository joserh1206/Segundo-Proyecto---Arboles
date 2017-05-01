#include <iostream>
#include "Producto.h"
#include "NodoProductos.h"
#include <sstream>
using namespace std;

class AATree
{
public:
	explicit AATree();
	AATree(const AATree & rhs);
	~AATree();

	const int & findMin() const;
	const int & findMax() const;
	Producto & find(const int & x) const;
	bool isEmpty() const;
	string printTree();

	void makeEmpty();
	void insert(Producto & x);
	void remove(const int & x);

	NodoProducto* find(Producto x);
	bool existeProducto(int ofer);
	bool alcanzaProducto(int idProducto, int cantidad, int tipo);
	double precioProducto(int idProducto, int tipo);
	string toString(int value);

	const AATree & operator = (const AATree & rhs);

	std::string getInorder();

	int getLastDiscount() { return lastDiscount; }

private:
	NodoProducto *root;
	NodoProducto *nullNode;

	int counter;
	int lastDiscount;

	// Recursive routines
	void insert(Producto & x, NodoProducto * & t);
	void remove(const int & x, NodoProducto * & t);
	void makeEmpty(NodoProducto * & t);
	string printTree(NodoProducto *t);

	// Rotations
	void skew(NodoProducto * & t) const;
	void split(NodoProducto * & t) const;
	void rotateWithLeftChild(NodoProducto * & t) const;
	void rotateWithRightChild(NodoProducto * & t) const;
	NodoProducto * clone(NodoProducto * t) const;

	void getStreamInorder(NodoProducto *tree, std::stringstream *convert);
};
