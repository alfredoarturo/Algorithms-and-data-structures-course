#include <iostream>
using namespace std;
static const int N = 10000;
int main(){
	int i, j , p, q, id[N], sz[N];
	for (i = 0; i < N; ++i){
		id[i] = i; sz[i] = 1;
	}
	while ( cin >> p >> 1){
		for(i = p; i != id[i]; i = id[i]);  //find
		for(j = q; j != id[j]; j = id[j]);
		if ( i == j ) continue;

		if(sz[i] < sz[j]){
			id[i] = j; sz[j]+= sz[i];  // quick union + peso
		}
		else{
			id[j] = i; sz[i]+= sz[j];  // quick union + peso
		}
		cout << " " << p << " " << q << endl;
	}
	return 0;
}
