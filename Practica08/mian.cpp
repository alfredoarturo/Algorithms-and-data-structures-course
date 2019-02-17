#include <iostream>


using namespace std;

template <class t>
class node {
   public:
	t item;
	node<t> * next;

	node(t a, node<t>* b)
	{
		item = a;
		next = b;
	}
	
};

template <class t>
class lista{
	public:
		int size;
	private:
		node<t> * head;

	void imprime_direcciones()
	{
		node<t>* aux = head;
		cout <<"imprimiendo direcciones de memoria"<<endl;
		while(aux != NULL)
		{
			cout <<aux <<" ";
			aux = aux ->next;
		}
		cout <<endl;
	}
	public:
	lista()
	{
		head = NULL;
		size = 0;
	}
    t regrsa_inicio()
    {
        if(head != NULL)
        {
            return head->item;
        }
        cout << "pila vacia" << endl;
    }
	void inserta_inicio(t a)
	{
		node<t>* aux = new node<t>(a, head);
		head = aux;
		size++;
	}
	void inserta_final(t a)
	{
		node<t>* aux = new node<t>(a,NULL);
		if (head == NULL)
			head = aux;
		else
		{
			node<t>* current = head;
			while(current->next != NULL)
				current = current->next;
			current->next = aux;
		}
	}
	void borra_inicio()
	{
		if(head != NULL)
		{
			node<t>* aux = head;
			head = head->next;
			delete aux;
			size--;
		}
		else
		{
			cout<<"No hay nada que borrar"<<endl;
		}
	}
	~lista()
	{
		cout <<endl<<"borrando lista "<<endl;
		//imprime_direcciones();

		node<t>* aux = head;
		while(head != NULL)
		{
			aux = head;
			head = head->next;

			delete aux;
		}
	//	cout <<endl<<"listo"<<endl<<endl;
	}


    void borra_n(int n)
    {
        if (n ==  0)
        {
            borra_inicio();
            return;
        }
        int i = 0 ;
        node<t>* aux = head;
        node<t>* aux2 = head;

        while( i < n && aux != NULL)
        {
            i++;
            aux2 = aux;
            aux = aux->next;
        }
        aux2->next = aux->next;
        delete aux;
    }

    void imprime_lista()
    {
        node<t>* aux = head;

        while(aux != NULL)
        {
            cout <<aux->item<<" ";
            aux = aux->next;
        }
            cout <<endl<<endl;
    }
};

template<class t>
class pila{
	private:
		lista <t> head;
	public:
		pila(){

		}
		void pop(){
			head.borra_inicio();
		}
		void push(t a){
			if (a == 0)
				return;
			head.inserta_inicio(a);
		}
		t peek(){
			return head.regrsa_inicio();
		}
		void imprime(){
			head.imprime_lista();
		}
		bool empty(){
			if (head.size == 0)
				return true;
			return false;
		}
};

template <class t>
class cola{
	private:
		lista <t> head;
	public:
		cola(){

		}
		void pop(){
			head.borra_inicio();
		}
		void push(t a){
			if (a == 0)
				return;
			head.inserta_final(a);
		}
		t peek(){
			return head.regrsa_inicio();
		}
		void imprime(){
			head.imprime_lista();
		}
		bool empty(){
			if (head.size == 0)
				return true;
			return false;
		}
};

template <class t>
class tree_node{
   public:
	t item;
	tree_node<t> *left;
	tree_node<t> *right;

	tree_node(){
		item = 0;
		left = NULL;
		right = NULL;
	}

	tree_node(t a, tree_node <t> *l , tree_node <t> *r){
		item = a;
		left = l;
		right = r;
	}
	

	void preorden(){
		cout << item << " ";
		if (left != NULL)
			left->preorden();
		if (right != NULL)
			right->preorden();
	}

	void inorden(){
		if (left != NULL)
			left->preorden();
		cout << item << " ";
		if (right != NULL)
			right->preorden();

	}

	void posorden(){
		if (left != NULL)
			left->preorden();
		if (right != NULL)
			right->preorden();
		cout << item << " ";
	}

	void anchura(){
		cola <tree_node<t>*> a;
		tree_node <t> *aux;
		cout << item << " ";
		a.push(left);
		a.push(right);
		while (!a.empty()){
			aux = a.peek();
			a.pop();
			cout << aux->item << " ";
			a.push(aux->left);
			a.push(aux->right);
		}
		a.imprime();
	}
};

int main(){
	tree_node <int> *q = new tree_node<int>(2, NULL, NULL);
	tree_node <int> *w = new tree_node<int>(3, NULL, NULL);
	tree_node <int> t(1, q, w);
	cout << "preorden" << endl;
	t.preorden();
	cout << endl;
	cout << "inorden" << endl;
	t.inorden();
	cout << endl;
	cout << "posorden" << endl;
	t.posorden();
	cout << endl;
	cout << "nivel" << endl;
	t.anchura();
	cout << endl;

   lista<double> l;
   l.inserta_final(30.1);
   l.inserta_inicio(11.1);
   l.inserta_final(40.1);

   l.imprime_lista();

   pila <double> a;
   a.push(1.2);
   a.push(2.3);
   a.imprime();
   a.pop();
   a.imprime();


   cola <double> b;
   cout << "a" << endl;
   b.push(1.2);
   b.push(2.3);
   b.imprime();
   b.pop();
   b.imprime();

	return 0;
}
