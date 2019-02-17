#include <iostream>  
#include <queue>  

using namespace std;

struct compare{
	bool operator()(const int& l, const int& r) {  
    	return l > r;
	}
};

int main(){
	priority_queue<int,vector<int>, compare > pq;
	int N, costo, aux, uno, dos;
	while(1){
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; ++i){
			cin >> aux;
			pq.push(aux);
		}
		costo = 0;
		aux = 0;
		while(pq.size() > 1){
			uno = pq.top();
			pq.pop();
			dos = pq.top();
			pq.pop();
			aux = uno + dos;
			pq.push(aux);
			costo += aux;
		}
		pq.pop();
		cout << costo << endl;
	}
	return 0;
}