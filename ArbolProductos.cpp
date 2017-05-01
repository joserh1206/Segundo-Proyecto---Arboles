#include "ArbolProductos.h"


string AATree::toString(int value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

AATree::AATree()
{
	nullNode = new NodoProducto;
	nullNode->left = nullNode->right = nullNode;
	nullNode->level = 0;
	root = nullNode;

	counter = 0;
	lastDiscount = 0;
}

AATree::AATree(const AATree & rhs)
{
	nullNode = new NodoProducto;
	nullNode->left = nullNode->right = nullNode;
	nullNode->level = 0;
	root = clone(rhs.root);

	counter = 0;
	lastDiscount = 0;
}

AATree::~AATree()
{
	makeEmpty();
	delete nullNode;
}

void AATree::insert(Producto & x)
{
	insert(x, root);
}

void AATree::remove(const int & x)
{
	remove(x, root);
}

NodoProducto *AATree::find(Producto x)
{
	NodoProducto *current = root;
	nullNode->value = x;

	for (; ; )
	{
		if (x.idProducto < current->value.idProducto)
			current = current->left;
		else if (current->value.idProducto < x.idProducto)
			current = current->right;
		else if (current != nullNode)
			return current;
		else
			return NULL;
	}
}

bool AATree::existeProducto(int ofer) {
	NodoProducto *current = root;

	for (; ; )
	{
		if (ofer < current->value.idProducto)
			current = current->left;
		else if (current->value.idProducto < ofer)
			current = current->right;
		else if (current->value.idProducto == ofer)
			return true;
		else
			return false;
	}
}

const int & AATree::findMin() const
{
	static const int z = 0;
	if (isEmpty())
		return z;

	NodoProducto *ptr = root;
	while (ptr->left != nullNode)
		ptr = ptr->left;

	return ptr->value.idProducto;
}

const int & AATree::findMax() const
{
	static const int z = 0;
	if (isEmpty())
		return z;

	NodoProducto *ptr = root;
	while (ptr->right != nullNode)
		ptr = ptr->right;

	return ptr->value.idProducto;
}

Producto & AATree::find(const int & x) const
{
	Producto z;
	NodoProducto *current = root;
	nullNode->value.idProducto = x;

	for (; ; )
	{
		if (x < current->value.idProducto)
			current = current->left;
		else if (current->value.idProducto < x)
			current = current->right;
		else if (current != nullNode)
			return current->value;
		else
			return z;
	}
}

void AATree::makeEmpty()
{
	makeEmpty(root);
}

bool AATree::isEmpty() const
{
	return root == nullNode;
}

string AATree::printTree()
{
	if (root == nullNode)
		return "Hotel no tiene Productos";
	else
		return printTree(root);
}

const AATree & AATree::operator=(const AATree & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}

	return *this;
}

std::string AATree::getInorder()
{
	std::stringstream *stream = new std::stringstream();
	getStreamInorder(root, stream);
	return stream->str();
}

void AATree::insert(Producto & x, NodoProducto * & t)
{
	if (t == nullNode)
		t = new NodoProducto(x, nullNode, nullNode);
	else if (x.idProducto < t->value.idProducto)
		insert(x, t->left);
	else if (t->value.idProducto < x.idProducto)
		insert(x, t->right);
	else
		return;  // Duplicate; do nothing

	skew(t);
	split(t);
}

void AATree::remove(const int & x, NodoProducto * & t)
{
	static NodoProducto *lastNode, *deletedNode = nullNode;

	if (t != nullNode)
	{
		// Step 1: Search down the tree and set lastNode and deletedNode
		lastNode = t;
		if (x < t->value.idProducto)
			remove(x, t->left);
		else
		{
			deletedNode = t;
			remove(x, t->right);
		}

		// Step 2: If at the bottom of the tree and
		//         x is present, we remove it
		if (t == lastNode)
		{
			if (deletedNode == nullNode || x != deletedNode->value.idProducto)
				return;   // Item not found; do nothing
			deletedNode->value = t->value;
			deletedNode = nullNode;
			t = t->right;
			delete lastNode;
		}

		// Step 3: Otherwise, we are not at the bottom; rebalance
		else
			if (t->left->level < t->level - 1 ||
				t->right->level < t->level - 1)
			{
				if (t->right->level > --t->level)
					t->right->level = t->level;
				skew(t);
				skew(t->right);
				skew(t->right->right);
				split(t);
				split(t->right);
			}
	}
}

void AATree::makeEmpty(NodoProducto * & t)
{
	if (t != nullNode)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullNode;
}

string AATree::printTree(NodoProducto *t)
{
	string res = "";
	if (t != nullNode)
	{
		res += printTree(t->left);
		res += "\nID: " + toString(t->value.idProducto);
		res += "\nPrecio Individual: " + toString(t->value.precioHabInd);
		res += "\nPrecio Doble: " + toString(t->value.precioHabDob);
		res += printTree(t->right);
	}
	return res;
}

void AATree::rotateWithLeftChild(NodoProducto * & k2) const
{
	NodoProducto *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2 = k1;
}

void AATree::rotateWithRightChild(NodoProducto * & k1) const
{
	NodoProducto *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1 = k2;
}

void AATree::skew(NodoProducto * & t) const
{
	if (t->left->level == t->level)
		rotateWithLeftChild(t);
}

void AATree::split(NodoProducto * & t) const
{
	if (t->right->right->level == t->level)
	{
		rotateWithRightChild(t);
		t->level++;
	}
}

NodoProducto *AATree::clone(NodoProducto * t) const
{
	if (t == t->left)  // Cannot test against nullNode!!!
		return nullNode;
	else
		return new NodoProducto(t->value, clone(t->left),
			clone(t->right), t->level);
}

void AATree::getStreamInorder(NodoProducto *tree, std::stringstream *convert)
{
	if (tree)
	{
		getStreamInorder(tree->left, convert);
		*convert << tree->getValue().idProducto << ",";
		getStreamInorder(tree->right, convert);
	}
}
