#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void bubblesort(int *v, int n, int *a0, int *a1);
void menor_dfab(int *v, int n, int i, int j, int *a0, int *a1, int *delta);
void imprime(int *v, int n);
void menu_pp(int *v, int *v_copia, int n, int a, int b);
void insertionsort(int *v, int n);
void elementounico(int *v, int *excluidos, int n, int cont);
void menu_eu(int *v, int *v_copia, int n);
void frequencia(int *v, int n);
void selection_sort(int *v, int N);
void menu_df(int *v, int *v_copia, int n);



int main(){
    int v_dado[] = {5,12,3,13,1,99};
    int v_escolhido[] = {1,1,3,19,2,32,3,5,8,6,5};
    int *v_copia;
    int *v_inserido;
    int N, a, b, i, opc;

    do{
    printf("Digite um vetor de tamanho N>1: ");
    scanf("%d", &N);}while(N<=1);
    v_inserido = (int *) malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        printf("v[%d] = ", i);
        scanf("%d", &v_inserido[i]); getchar();
    }
    system("clear");

    do{
        printf("1- Pares mais Proximos \n");
        printf("2- Elemento Unico \n");
        printf("3- Distribuicao de Frequencia\n");
        printf("0- Sair \n");
        scanf("%d", &opc); getchar(); system("clear");

        switch(opc){
            case 1:
                menu_pp(v_dado, v_copia, 6, a, b);
                menu_pp(v_escolhido, v_copia, 10, a, b);
                menu_pp(v_inserido, v_copia, N, a, b);
            break;

            case 2:
                menu_eu(v_dado, v_copia, 6);
                menu_eu(v_escolhido, v_copia, 10);
                menu_eu(v_inserido, v_copia, N);
            break;

            case 3:
                menu_df(v_dado, v_copia, 6);
                menu_df(v_escolhido, v_copia, 10);
                menu_df(v_inserido, v_copia, N);
            break;
        }

    }while(opc!=0);




return 0;
}

void menu_pp(int *v, int *v_copia, int n, int a, int b){
    int i;
    v_copia = (int *) malloc(n*sizeof(int));
    for(i=0; i<n; i++) v_copia[i] = v[i];
    printf(" . . .: :::: PARES MAIS PROXIMOS :::: :. . .");
    printf("\n\n>> VETOR " );
    imprime(v, n);
    printf("\n> MENOR DIFERENCA ");
    bubblesort(v_copia, n, &a, &b);
    printf("\n> VETOR ORDENADO PELO BUBBLE SORT");
    imprime(v_copia, n);
    printf("\nPROXIMO..."); getchar(); system("clear");
    free(v_copia);
}

void menu_eu(int *v, int *v_copia, int n){
    int i;
    v_copia = (int *) malloc(n*sizeof(int));
    for(i=0; i<n; i++) v_copia[i] = v[i];
    printf(" . . .: :::: ELEMENTO UNICO :::: :. . .");
    printf("\n\n>> VETOR " );
    imprime(v, n);
    printf("\n> ELEMENTO UNICO ");
    insertionsort(v_copia, n);
    printf("\n> VETOR ORDENADO PELO INSERTION SORT");
    imprime(v_copia, n);
    printf("\nPROXIMO..."); getchar(); system("clear");
    free(v_copia);
}

void menu_df(int *v, int *v_copia, int n){
    int i;
    v_copia = (int *) malloc(n*sizeof(int));
    for(i=0; i<n; i++) v_copia[i] = v[i];
    printf(" . . .: :::: DISTRIBUICAO DE FREQUENCIA :::: :. . .");
    printf("\n\n>> VETOR " );
    imprime(v, n);
    printf("\n> FREQUENCIA ");
    frequencia(v_copia, n);
    printf("\n> VETOR ORDENADO PELO SELECTION SORT");
    imprime(v_copia, n);
    printf("\nPROXIMO..."); getchar(); system("clear");
    free(v_copia);
}

void bubblesort(int *v, int n, int *a0, int *a1){
    int i, j, aux, delta;

    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
            menor_dfab(v, n, i, j, a0, a1, &delta);
        }
    }
    printf("\n %d - %d = %d\n", *a1, *a0, delta);
}

void menor_dfab(int *v, int n, int i, int j, int *a0, int *a1, int *delta){
    if(i==0){
        *delta = abs(v[j] - v[j+1]);
        *a0 = v[j];
        *a1 = v[j+1];
    }

    else{
        if(*delta>abs(v[j]-v[j+1])){
            *delta=abs(v[j]-v[j+1]);
            *a0 = v[j];
            *a1 = v[j+1];
        }
    }
}

void imprime(int *v, int n){
    int i;
    printf("\n( ");
    for(i=0; i<n; i++) printf(" %d ", v[i]);
    printf(" )\n");
}


void insertionsort(int *v, int n) {
   int *excluidos=NULL;
   int i, j, x, cont=0;

   for (i = 1; i < n; i++){
      x = v[i];
      j = i - 1;
      while ((j>=0) && (x <= v[j])) {
         if(x == v[j]){
            excluidos = (int *) realloc(excluidos, sizeof(int)*(cont+1));
            excluidos[cont] = x;
            cont++;
         }
         v[j+1] = v[j];
         j--;
      }
      v[j+1] = x;
   }
   elementounico(v, excluidos, n, cont);
}

void elementounico(int *v, int *excluidos, int n, int cont){
    int i,j,flag;

    printf("\n");
    for(i=0; i<n; i++){
        flag=1;

        for(j=0; j<cont; j++){
            if(v[i] == excluidos[j]){
                flag=0;
            }
        }

        if(flag==1) printf(" %d ", v[i]);
    }
    printf("\n");
}

void frequencia(int *v, int n){
    int i, j, k=0, flag, cont;
    int *v2 = NULL;
    float *freq = NULL;

    for(i=0; i<n; i++){
        flag=1;

        for(j=i+1; j<n; j++){
            if(v[j]==v[i]) flag = 0;
        }

        if(flag==1){
            v2 = (int *) realloc(v2, (k+1)*sizeof(int));
            v2[k] = v[i];
            k++;
        }
    }

    freq = (float *) malloc((k+1)*sizeof(float));

    for(i=0; i<k; i++){
        freq[i]=0.0;
        for(j=0;j<n;j++){
            if(v2[i] == v[j])
                freq[i]++;
        }
    }


    for(i=0;i<k;i++){
    printf("\n%d = %.3f%%", v2[i], (freq[i]/k * 100));
    }
    printf("\n");

    free(freq);
    free(v2);
    selection_sort(v, n);

}

void selection_sort(int *v, int N){
  int i, j, min, aux;
  for (i=0; i<(N-1); i++){
    min = i;
    for (j = (i+1); j<N; j++){
      if(v[j] < v[min])
        min = j;
    }
    if (i != min){
      aux = v[i];
      v[i] = v[min];
      v[min] = aux;
    }
  }
}
