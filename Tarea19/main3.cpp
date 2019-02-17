#include <iostream>

using namespace std;

template <class t>
class tree_node{
public:
	t item;
	tree_node<t> *left;
	tree_node<t> *right;
	tree_node<t> *parent;

	tree_node<t>(){
		item = 0;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	tree_node<t>(t v){
		item = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	tree_node<t>(tree_node<t> *a){
			item = a->item;
			left = a->left;
			right = a->right;
			parent = a->parent;
	}

	tree_node<t> (t a, tree_node <t> *l , tree_node <t> *r, tree_node <t> *p){
		item = a;
		left = l;
		right = r;
		parent = p;
	}

	tree_node<t> (t a, tree_node <t> *l , tree_node <t> *r){
		item = a;
		left = l;
		right = r;
		parent = NULL;
	}

};


template <class t>
class tree{
public:
	tree_node<t> *root;

	tree<t>(){
		root = NULL;
	}

	tree<t>(tree_node<t> *r){
		root = r;
	}

	void LRotate(tree<t> *T, tree_node<t> *x){
		tree_node<t> *y = x->right;
		x->right = y->left;
		if (y->left != NULL)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			T->root = y;
		else{
			if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void LeftRotate(tree_node<t> *x){
		LRotate(this, x);
	}

	void RRotate(tree<t> *T, tree_node<t> *x){
		tree_node<t> *y = x->left;
		x->left = y->right;
		if (y->right != NULL)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			T->root = y;
		else{
			if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	void RightRotate(tree_node<t> *x){
		RRotate(this, x);
	}

	void insT(tree<t> *T, t x){
		if (T->root == NULL){
			T->root = new tree_node<t>(x);
			return;
		}
		if (x < T->root->item){
			if (T->root->left == NULL){
				T->root->left = new tree_node<t>(x, NULL, NULL, T->root);
				RightRotate(T->root);
				return;
			}
			tree<t> *aux = new tree<t>(T->root->left);
			insT(aux, x); 
			RightRotate(T->root);
		}
		else{
			if (T->root->right == NULL){
				T->root->right = new tree_node<t>(x, NULL, NULL, T->root);
				LeftRotate(T->root);
				return;
			}
			tree<t> *aux = new tree<t>(T->root->right);
			insT(aux, x);
			LeftRotate(T->root);
		}
	}

	void insertT(t x){
		insT(this, x);
	}

	tree_node<t> *TSearch(tree_node<t> *T, t k){
		if ( T == NULL || k == T->item)
			return T;
		if (k < T->item)
			TSearch(T->left, k);
		else
			TSearch(T->right, k);
	}

	tree_node<t> *TreeSearch(t k){
		return TSearch(this->root, k);
	}

	tree_node<t> *Successor(tree_node<t> *T){
		if (T->right != NULL)
			return TreeMin(T->right);
		tree_node<t> *y = T->parent;
		while (y != NULL && T == y->right){
			T = y;
			y = y->parent;
		}
		return y;
	}

	tree_node<t> *TreeMin(tree_node<t> *T){
		while (T->left != NULL)
			T = T->left;
		return T;
	}

	tree_node<t> *TreeMax(tree_node<t> *T){
		while (T->right != NULL)
			T = T->right;
		return T;
	}

	void TreeDelete(tree_node<t> *z){
		tree_node<t> *y, *x;
		if (z->left == NULL || z->right == NULL)
			y = z;
		else
			y = Successor(z);
		if (y->left != NULL)
			x = y->left;
		else
			x = y->right;
		if (x != NULL)
			x->parent = y->parent;
		if (y->parent == NULL)
			this->root = x;
		else{
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		}
		if (y != z)
			z->item = y->item;
	}

	tree_node<t> *Select(int k){
		tree_node<t> *x = TreeMin(this->root);
		for (int i = 0; i < k-1; ++i){
			x = Successor(x);
		}
		return x;
	}
};

template<typename Item>
void printnode (Item x, int h){
	for (int i = 0; i < h; ++i)
		cout << "   ";
	cout << "  " << x << endl;
}

template<typename q>
void show(tree_node<q> *t, int h){
	if ( t == NULL){
		printnode<char>('*', h);
		return;
	}
	show(t->right, h+1);
	printnode<q>(t->item, h);
	show(t->left, h+1);
}

int main(){
	tree_node<int> *n1 = new tree_node<int>(1);
	tree_node<int> *n2 = new tree_node<int>(3);
	tree<char> *T = new tree<char>();

	cout << "Se insertan elemntos a la raiz:" << endl;

	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('a');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('s');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('e');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('r');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('c');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('h');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('i');
	show(T->root, 0);
	cout << "###################################################" << endl;
	T->insertT('n');
	show(T->root, 0);
	T->insertT('g');

	cout << "###################################################" << endl;

	show(T->root, 0);

	cout << "###################################################" << endl;

	cout << "Se elimina el nodo con 'g'" << endl;
	T->TreeDelete(T->TreeSearch('g'));
	show(T->root, 0);

	cout << "###################################################" << endl;

	cout << "Se busca el elemento 'n':" << endl; 
	cout << T->TreeSearch('n')->item << endl;
	cout << "Se busca el minimo: " << endl;
	cout << T->TreeMin(T->root)->item << endl;
	cout << "Se busca el máximo:" << endl;
	cout << T->TreeMax(T->root)->item << endl;
	cout << "Se selecciona el 5 nodo:" << endl;
	cout << T->Select(5)->item << endl;

	/*delete q;
	delete w;
	delete q;
	delete a;
	delete b;
	delete c;
	delete d;*/

	return 0;
}
