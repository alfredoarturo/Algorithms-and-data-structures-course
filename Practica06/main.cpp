#include <iostream>
using namespace std;

class matrix{
	public:
	int **mat;
	int m, n;

	matrix(){
		mat = NULL;
		n = 0;
		m = 0;
	}

	matrix(int m, int n, int a){
		mat = new int*[m];
		*mat  = new int [m*n];
		for (int i = 1; i < m; ++i)
			mat[i] = mat[i-1];
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j)
				mat[i][j] = a;
		}
	}

	void operator=(const matrix &m1){
		if (m1.n == n && m1.m == m){
			for (int i = 0; i < m; ++i){
				for (int j = 0; j < n; ++j)
					mat[i][j] = m1.mat[i][j];
			}
		}
	}

	matrix operator-(const matrix &m1){
		matrix *mr = new matrix(m, n, 0);
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j)
				mr->mat[i][j] = mat[i][j] - m1.mat[i][j];
		}
		return mr;
	}

	friend ostream& operator<<(ostream& out, const matrix& m1){
		for (int i = 0; i < m1.m; ++i){
			for (int j = 0; j < m1.n; ++j)
				out << m1.mat[i][j] << " ";
			out << endl;
		}
		out << endl;
		return out;
	}

	~matrix(){
		delete [] *mat;
		delete [] mat;
		cout << "objeto destruido" << endl;
	}
};

matrix operator+(const matrix& l, const matrix& r){
	if (l.m == r.m && l.n == r.n){
		matix *mr = new matrix(l.m, l.n, 0);
		for (int i = 0; i < r.m; ++i){
			for (int j = 0; j < r.n; ++j)
				mr->mat[i][j] = r.mat[i][j] + l.mat[i][j];
		}
	}
	return mr;
}

int mult(const matrix &l, const matrix &r, int i, int j){
	int m = 0;
}

matrix operator*(const matrix &l, const matrix &r){
	if (l.n == r.m){
		
}

int main(){
	
}
