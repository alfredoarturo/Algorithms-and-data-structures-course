#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

bool binary_search(int* array, int n, int target){
    int L = 0;
    int R = n-1;

    while(L <= R){
        int M = (L+R)/2;

        if(array[M] < target)
            L = M+1;
        else if(array[M] > target)
            R = M-1;
        else //if(array[M] == target)
            return true;
    }

    return false;
}

bool search(int* array, int n, int target){
    for(int i = 0; i < n; i++)
        if(array[i] == target)
            return true;
    return false;
}

void llenar(int *nums){
   srand(time(NULL));
   for (int i = 0; i < 1000000; ++i){
      nums[i] = i;
   }
}

int main(){
    clock_t start, end;
    double cpu_time;
    int *nums = (int *)malloc(sizeof(int)*1000000);

    llenar(nums);
    start = clock();
    search(nums, 1000000, 985463);
    end   = clock();

    cpu_time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << "search tardo: " << cpu_time << endl;

    start = clock();
    binary_search(nums, 1000000, 985463);
    end   = clock();

    cpu_time = (end - start) / (double)CLOCKS_PER_SEC;
    cout << "binary_search tardo: " << cpu_time << endl;

    return 0;
}
