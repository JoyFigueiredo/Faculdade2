#include<stdio.h>
#include<string.h>

int main (){

    int n, m, i, j;
    int Matriz[1000][1000];

    scanf("%d", &n);
    scanf("%d", &m);

    printf("valores", n);

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &Matriz[i][j]);
        } 
    }
    return 0;
}