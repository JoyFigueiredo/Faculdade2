#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int C, T, i, ultimo, x, y, j, resultado;

    scanf("%d", &C);
    scanf("%d", &T);

    int raio[C];

    for (i = 0; i < C; i++)
    {
        scanf("%d", &raio[i]);
        if (i == (C - 1))
        {
            ultimo = raio[i];
        }
    }
    double dis[i];
    int pontos = C;

    for (i = 0; i < T; i++){
        scanf("%d", &x);
        scanf("%d", &y);

        dis[i] = sqrt(x*x + y*y);
    }

    for (i = 0; i < C; i++){
        for (j = 0; j < T; j++){
            if (raio[i] >= dis[j] && dis[j] != (-1))
            {
                resultado = resultado + pontos;
                dis[j] = -1;
            }
        }
        pontos--;
    }
    printf("%d \n", resultado);

    return 0;
}