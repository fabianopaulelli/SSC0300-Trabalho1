#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
    printf("\n %d - %d = %d\n", *a1, *a0, delta);
}

void imprime(int *v, int n){
    int i;
    printf("\n( ");
    for(i=0; i<n; i++) printf(" %d ", v[i]);
    printf(" )\n");
}

void menuinicial(void){
    printf("\n1- Pares Mais proximos/Closest Pair ");
    printf("\n2- Elemento Unico ");
    printf("\n3- Distribuicao de Frequencia");
    printf("\n4- Feixo Convexo");
    printf("\n0- Sair");
}

void menusecundario(void){
    printf("\n1- Vetor Dado");
    printf("\n2- Vetor Aleatorio de tamanho N");
    printf("\n3- Entrar com um vetor de tamanho N");
    printf("\n0- Para voltar");
}

void vetoraleatorio(int *v, int n){
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++) v[i]=rand()%100;
}

void le_vetor(int *v, int n){
    int i;
    for(i=0; i<n; i++) scanf("%d", &v[i]);
}


int main(){
    int i, a, b, opc, opc1;
    int dado[]={5, 12, 3, 13, 1, 99};
    int *usuario, n;

    do{
        menuinicial();
        scanf("%d", &opc); getchar();
        system("clear");

        switch(opc){
          case 1:
            do{
            menusecundario();
            scanf("%d", &opc1); getchar();
            system("clear");
               switch(opc1){
                 case 1:
                    imprime(dado, 6);
                    bubblesort(dado, 6, &a, &b); printf("\n\n");
                    imprime(dado, 6);
                    printf("\n\nPressione para continuar..."); getchar();
                    break;

                  case 2:
                    printf("Tamanho do vetor aletorio");
                    scanf("%d", &n); getchar();
                    usuario = (int *) calloc(n, sizeof(int));
                    vetoraleatorio(usuario, n);

                    imprime(usuario, n);
                    bubblesort(usuario, n, &a, &b);
                    imprime(usuario, n);
                    printf("\n\nPressione para continuar..."); getchar();
                 break;

                 case 3:
                    printf("Tamanho do vetor N");
                    scanf("%d", &n); getchar();
                    usuario = (int *) calloc(n, sizeof(int));
                    le_vetor(usuario, n);

                    imprime(usuario, n);
                    bubblesort(usuario, n, &a, &b);
                    imprime(usuario, n);
                    printf("\n\nPressione para continuar..."); getchar();
                 break;

                 case 0: break;

                 default: printf("Opcao invalida!");

               }
            }while(opc1!=0);
          break;

        }
    }while(opc!=0);


return 0;
}
