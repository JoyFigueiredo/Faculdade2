#include <stdio.h>
#include <string.h>

int numSaloes, numTuneos, apartir;
int alturas[250], visitados[250];
char matrizAdj[250][250];
int resultado =0;

void busca(int salao){ //Busca recursiva.
  int i, tmp;

  if (visitados[salao] == -1){
    resultado++;
    visitados[salao] = 0;
    for (i = 0; i < numSaloes; i++){
      if (matrizAdj[salao][i])
        busca(i);
    }
  }
}

int main(void){
  int aux;
  int origem, destino;
  scanf("%d", &numSaloes);
  scanf("%d", &numTuneos);
  scanf("%d", &apartir);

  for (aux = 0; aux < numSaloes; aux++)
    scanf("%d", &alturas[aux]);              //Ao receber valor deve se armazenar na memoria
    memset(matrizAdj, 0, sizeof(matrizAdj)); // memset(bloco da memoria, valor a ser armazenado, numero de bytes)
  for (aux = 0; aux < numTuneos; aux++)
  {
    scanf("%d", &origem);
    scanf("%d", &destino);
    origem--;
    destino--;

    if (alturas[origem] > alturas[destino])
      matrizAdj[origem][destino] = 1;
    else if (alturas[origem] < alturas[destino])
      matrizAdj[destino][origem] = 1;
  }

  memset(visitados, -1, sizeof(visitados));
  busca(apartir - 1);

  printf("%d\n", resultado - 1);

  return 0;
}