#include <stdio.h>

int main(){
	int x=0;
	char *y;
	y = (char *)(&x);
	y[1] = 255;
	printf("%d\n", x);
	return 0;
}
