#include <iostream>

using namespace std;

class matriz{
    private:
        float **mat;
        int dim;
    public:
        matriz(){ dim = 0; mat = NULL; }                        //incia una matriz de dimension0

        void iniciaMatriz(int ren, int col){                    //reserva memoria para una matriz de la dimension indicada
            if (ren != col)
                return;
            dim = ren;
            mat = new float* [dim];                             //apuntadores a renglones
            mat[0] = new float[dim*dim];                        //matriz con memoria continua
            for (int i = 1; i < dim; ++i)
                mat[i] = mat[i-1] + dim;                        //se colocan los apuntadores a los renglones
        }
        matriz(int ren, float val){                             //crea una matriz de la dimension indicada, con todas las entradas en el valor indicado
            this->iniciaMatriz(ren, ren);                       //se crea memoria esta matriz del tamaño indicado
            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++){
                    mat[i][j] = val;                            //se rellena la matriz con el valor indicado
                }
            }
        }
        float **matP(){ return mat; }                           //regresa el doble apuntador mat
        int get_dim(){ return dim; }                            //regresa la dimension de la matriz
        friend ostream& operator<<(ostream& out, matriz& m1)    //sobrecarga el operador << para poder imprimir la matriz
        {
            for(int i = 0; i < m1.get_dim(); ++i){
                for(int j = 0; j < m1.get_dim(); ++j)
                    out << m1.matP()[i][j] << " ";              //se manda a imprimir entrada por entrada
                out << endl;
            }
            return out;
        }

        void operator=( matriz& m1 )                            //operador igual
        {
            if(m1.get_dim() == dim){
                for(int i = 0; i < dim; i++){
                    for(int j = 0; j < dim; j++) 
                        mat[i][j]= m1.matP()[i][j];             //se iguala entrada por entrada
                }
            }
        }
        float traza(){                                          //se calcula la traza de la matriz
            int t=0;
            for(int i = 0; i < dim; ++i){
                t += mat[i][i];                                 //se suma cada elemento de la diagonal
            }
            return t;
        }
        ~matriz()
        {
            delete []*mat;
            delete []mat;
        }
        void liberarMemoria(void){
            delete []*mat;
            delete []mat;
        }
};

matriz& operator+( matriz& m1, matriz& m2){                     //se sobrecarga el operdador de suma
    if(m1.get_dim() == m2.get_dim() && m2.get_dim() == m1.get_dim()){      //se checa que se tengan las dimensiones apropiadas
        matriz *aux;
        aux = new matriz(m1.get_dim(), 0);                      //se crea matriz donde va a estar la suma
        for(int i = 0; i < m1.get_dim(); ++i){
            for(int j = 0; j < m1.get_dim(); ++j){
                aux->matP()[i][j] = m1.matP()[i][j] + m2.matP()[i][j];      //se suma entrada por entrada
            }
        }
        return *aux;
    }
}

matriz& operator-( matriz& m1, matriz& m2){                     //se sobrecarga operador resta
    if(m1.get_dim() == m2.get_dim()){
        matriz *aux;
        aux = new matriz(m1.get_dim(), 0);
        for(int i = 0; i < m1.get_dim(); ++i){
            for(int j = 0; j < m1.get_dim(); ++j){
                aux->matP()[i][j] = m1.matP()[i][j] - m2.matP()[i][j];
            }
        }
        return *aux;
    }
}

int mult(matriz &l, matriz &r, int i, int j){                   //esto es un auxiliar para la multiplicacion de matrices
    int mult = 0;
    for (int k = 0; k < l.get_dim(); ++k)
        mult += l.matP()[i][k]*r.matP()[k][j];                  //se multiplica renglon por columna
    return mult;
}

matriz& operator*(matriz &l, matriz &r){                        //sobrecarga del operador multiplicacion
    if (l.get_dim() == r.get_dim()){
        matriz *res = new matriz(r.get_dim(), 0);
        for (int i = 0; i < l.get_dim(); ++i){
            for (int j   = 0; j < r.get_dim(); ++j)
                res->matP()[i][j] = mult(l, r, i, j);           //se manda llamar el multiplicar renglon por columna
        }
        return *res;
    }
}

bool operator<(matriz &l, matriz &r){                           //se sobrecarga el operador
    if (l.traza() < r.traza())                                  //compara las trazas
        return true;
    return false;
}

bool operator<(int l, matriz&r){                                //se sobre carga el operador
    if (l < r.traza())                                          //compara un entrero y la traza
        return true;
    return false;
}

bool operator==(int l, matriz&r){                               //sobre carga el operador
    if (l == r.traza())                                         //checa si la traza tiene cierto valor
        return true;
    return false;
}

//Inician otras funciones no de clase
//Espacio de separación
//Inicioan otras funciones

matriz** vectorOrdenado(int tam, int dim){                          //crea el vector requerido
    float inicio = (float) (((rand() % 10)/10)+ rand()%10);
    matriz **a = new matriz*[1];
    *a= new matriz[tam];
    for (int i = 0; i < tam; ++i){
        inicio += (((rand() % 10)/10)+ rand()%10);
        a[i] = new matriz(dim, inicio/dim);
    }
    return a;
}

int bin_search ( matriz **a, int v, int l, int r ){                 //busqueda binaria
    while (r >= l){
        int m = (l+r)/2;
        if (v == *a[m]) return m;
        if (v < *a[m]) r=m-1; else l=m+1;
    }
    return -1;
}

int main(){
    matriz *b = new matriz(10, 3);
    matriz *c = new matriz(10, 1);
    cout << "b:\n" << *b << endl;
    cout << "c:\n" << *c << endl;
    cout << "suma:\n" << *b + *c << endl;
    cout << "traza de b: " << b->traza() << endl;
    b->liberarMemoria();
    c->liberarMemoria();
    matriz **a = vectorOrdenado(1000, 3);
    for (int i = 0; i < 1000; ++i){
        cout << *(a)[i];
    }
    int n = 18;
    if (bin_search(a, n, 0, 999) != -1){
        cout << n << "esta en el vector" << endl;
    }
    else{
        cout << n << "no esta" << endl;
    }
    delete *a;
    delete []a;
}