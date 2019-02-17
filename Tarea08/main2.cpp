#include <iostream>
#define N 1000000

using namespace std;

int main(){
	float a = 0.1, res = 0;
	for (int i = 0; i < N; ++i)
		res += a;
	cout << res << endl;
}
