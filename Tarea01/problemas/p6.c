#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,k,l;
	int *nums = (int *)malloc(sizeof(int)*4);
	char *letras = (char *)malloc(sizeof(char)*4);
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 3;
	letras[0] = 'A';
	letras[1] = 'B';
	letras[2] = 'C';
	letras[3] = 'D';
	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			if (j == i)
				continue;
			for (k = 0; k < 4; ++k){
				if (k == j || k == i)
					continue;
				for(l = 0; l < 4; ++l){
					if (l == k || l == j || l == i)
						continue;
					printf("%c%c%c%c\n", letras[i], letras[j], letras[k], letras[l]);
				}
			}
		}
	}
	return 0;
}


