#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubblesort(int *v, int n, int *a0, int *a1){
    int i, j, aux, delta;

    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }

            if(i==0){
               delta= abs(v[j] - v[j+1]);
               *a0 = v[j];
               *a1 = v[j+1];
            }

            else{
                    if(delta>abs(v[j]-v[j+1])){
                        delta=abs(v[j]-v[j+1]);
                        *a0 = v[j];
                        *a1 = v[j+1];
                    }
            }

        }
    }
    printf("\n %d - %d = %d", *a1, *a0, delta);
}



int main(){
    int i, a, b;
    int dado[]={5, 12, 3, 13, 1, 99};
    int *usuario, n;

    for(i=0;i<6;i++) printf(" %d ", dado[i]);
    bubblesort(dado, 6, &a, &b); printf("\n\n");
    for(i=0;i<6;i++) printf(" %d ", dado[i]);


return 0;
}
