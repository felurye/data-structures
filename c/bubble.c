#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8

static void bubble_sort(int vetor[], int tamanho) {
  int fim;

  for (fim = tamanho - 1; fim > 0; fim--) {
    int i;
    int trocou = 0;

    for (i = 0; i < fim; i++) {
      if (vetor[i] > vetor[i + 1]) {
        int aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
        trocou = 1;
      }
    }

    if (!trocou) {
      break;
    }
  }
}

int main(void) {
  int vet[TAMANHO];
  int i;

  printf("Entre com %d numeros:\n", TAMANHO);

  for (i = 0; i < TAMANHO; i++) {
    if (scanf("%d", &vet[i]) != 1) {
      fprintf(stderr, "Entrada invalida.\n");
      return EXIT_FAILURE;
    }
  }

  bubble_sort(vet, TAMANHO);

  printf("Vetor ordenado: ");
  for (i = 0; i < TAMANHO; i++) {
    printf("%d%s", vet[i], i == TAMANHO - 1 ? "\n" : " | ");
  }

  return EXIT_SUCCESS;
}
