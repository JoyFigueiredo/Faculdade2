#include <stdio.h>
#include <stdlib.h>

struct endereco{
    char cidade[50];
    char estado[2];
};

struct funcionarios{
    char nome[100];
    int idade;
    struct endereco end;
};

void preenche(struct funcionarios *f, int tam)
{
    for (int i = 0; i < tam; i++){
        printf("Nome, idade, cidade e sigla do estado:");
        scanf("%s %d %s %s", &f[i].nome, &f[i].idade, &f[i].end.cidade, &f[i].end.estado);
    }
}

void imprime(struct funcionarios *f, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\n Nome: %s\n Idade: %d\n Cidade: %s\n Estado: %s\n", f[i].nome, f[i].idade, 
        f[i].end.cidade, f[i].end.estado);
    }
}

void ordena(struct funcionarios *f, int tam){
    struct funcionarios aux;

    for (int i = 1; i < tam; i++) {

        for (int j = 0; j < tam - 1; j++) {

            if (f[j].idade > f[j + 1].idade) {
                aux = f[j];
                f[j] = f[j + 1];
                f[j + 1] = aux;
            }
        }
    }
}

int main(){

    int tam;
    struct funcionarios *f;

    scanf("%d", &tam);

    f = (struct funcionarios *)malloc(tam * sizeof(struct funcionarios));

    preenche(f, tam);
    ordena(f, tam);
    imprime(f, tam);

    free(f);

    return 0;
}