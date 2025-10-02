#include<stdio.h>
#include<string.h>


#define INFINITO 9999

int main(){

int N, M, i, j, a, b, c;

    scanf("%d", &N);
    scanf("%d", &M);
    
    int matriz[N][N];
    memset(matriz, INFINITO, sizeof(matriz));

    for (i = 0; i < M; i++){
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        matriz[(a-1)][(b-1)] = c;
        matriz[(b-1)][(a-1)] = c;
    }

      for (i = 0; i < N+1; i++){
        for (j = 0; j < N+1; j++){
            printf(" %d ",matriz[i][j]);
        }
        printf("\n");
    }

    // Dijkstra

    int ant[N], visitado[N], dist[N];
    int min, prox, count = 1;

    for(i=0; i < N; i++) {
        dist[i] = matriz[0][i];
        ant[i] = 0;
        visitado[i] = 0;
    }

    dist[0]=0;
    visitado[0]=1;

    do {

    min = INFINITO;

        for(i =0; i < N; i++) {

            if(dist[i] < min && visitado[i] != 1) {
                min = dist[i];
                prox = i;
            }
            visitado[prox] = 1;
            
            for(i =0; i<N; i++) {
                if(visitado[i]!= 1) {
                    if(min + matriz[prox][i] < dist[i]) {
                        dist[i] = min + matriz[prox][i];
                        ant[i] = prox;
                        
                    }
                }        
            }
        }
        count++;

    }while(i < N-1);

    printf("%d", min);

    return 0;
}