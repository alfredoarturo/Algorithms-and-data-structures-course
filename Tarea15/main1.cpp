#include <iostream>

template <class item>
class TreeNode{
private:
	item *l, *r;
public:
	TreeNode(){
		l = NULL;
		r = NULL;
	}
	item *get_l(){ return l; }
	item *get_r(){ return r; }
};

template <class T>
class Tree{
private:
	TreeNode<T> *top;
public:
	Tree(){
		top = NULL;
	}
	TreeNode<T> *get_top(){ return top; }
};

