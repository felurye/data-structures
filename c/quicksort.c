#include <stdio.h>

int particao(int vetor[8], int inicio, int fim) {
  int pivo, up, down, aux;

  pivo = vetor[inicio];
  down = inicio;
  up = fim;

  while (down < up) {
    while (vetor[down] <= pivo && down < fim) {
      down = down + 1;
    }
    while (vetor[up] > pivo) {
      up = up - 1;
    }
    if (down < up) {
      aux = vetor[down];
      vetor[down] = vetor[up];
      vetor[up] = aux;
    }
  }
  vetor[inicio] = vetor[up];
  vetor[up] = pivo;
  return (up);
}

void quicksort(int vetor[8], int inicio, int fim) {
  int pivo;

  if (inicio > fim) {
    return;
  }

  pivo = particao(vetor, inicio, fim);

  quicksort(vetor, inicio, pivo - 1);
  quicksort(vetor, pivo + 1, fim);
}

int main() {
  int vet[8], i, inicio, fim;

  printf("Entre com 8 valores: \n");
  for (i = 0; i < 8; i++) {
    scanf("%d", &vet[i]);
  }
  inicio = vet[0];
  fim = vet[7];

  quicksort(vet, inicio, fim);
}
