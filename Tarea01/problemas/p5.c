#include <stdio.h>

int valor(int param){
	static int b = 5;
	b = b + param;
	return b;
}

int main(){
	valor(10);
	return 0;
}
