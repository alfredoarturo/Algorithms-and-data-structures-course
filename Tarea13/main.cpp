#include <iostream>
#define N 5
#define MaxCap 100

using namespace std;

typedef struct {
    char name;
    int size;
    int val;
} Item;

Item items[N];
int obj[MaxCap];
int cam[MaxCap];

int knap(int cap){
    if (obj[cap] != -1) return obj[cap];

    int i,space,max,t;
    int maxi=-1;
    for(i=0,max=0;i<N;i++){
        if( (space = cap-items[i].size)>=0 ){
            if( (t = knap(space) + items[i].val ) > max ){
                max = t;
                maxi = i;
            }
        }
    }
    obj[cap] = max;
    cam[cap] = maxi;
    return max;
}

int main(){
    for (int i = 0; i < MaxCap; ++i) obj[i] = -1;
    // fill
    items[0].name='A'; items[0].size= 3; items[0].val= 4;
    items[1].name='B'; items[1].size= 4; items[1].val= 5;
    items[2].name='C'; items[2].size= 7; items[2].val= 10;
    items[3].name='D'; items[3].size= 8; items[3].val= 11;
    items[4].name='E'; items[4].size= 9; items[4].val= 13;
    int resp=knap(17);
    cout << "El mayor valor del robo es " << resp << " Para una bolsa de tamano " << 17  << endl;
    int ind=17;
    while(ind>0){
        cout << "Se roba: " << items[cam[ind]].name << endl;
        ind -= items[cam[ind]].size;
    }
}
