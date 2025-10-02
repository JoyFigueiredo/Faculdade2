#include <stdio.h>
#include <string.h>

typedef struct Aluno{
    char nome[100];
    int idade;
    float nota;
}A;

int main(){
    A a1, a2, a3, a4, a5;
    strcpy(a1.nome, "Ana");
    a1.idade = 21;
    a1.nota = 3.5;

    strcpy(a2.nome, "Italo");
    a2.idade = 22;
    a2.nota = 1.2;

    strcpy(a3.nome, "Rosa Maria");
    a3.idade = 21;
    a3.nota = 3.0;

    strcpy(a4.nome, "Raissa");
    a4.idade = 25;
    a4.nota = 0.0;

    strcpy(a5.nome, "Rebecca");
    a5.idade = 22;
    a5.nota = 4.0;

    A vetorAlunos[5] = {a1, a2, a3, a4, a5};

    FILE *arq;
    arq = fopen("Alunos.dat","wb");

    fwrite(vetorAlunos, sizeof(A), 5, arq);

    fclose(arq);
    return 0;
}    