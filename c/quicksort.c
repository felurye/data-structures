#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8

static void trocar(int *valor_a, int *valor_b) {
  int valor_temporario = *valor_a;
  *valor_a = *valor_b;
  *valor_b = valor_temporario;
}

static int particionar(int vetor[], int indice_inicial, int indice_final) {
  int indice_meio = indice_inicial + (indice_final - indice_inicial) / 2;
  int pivo = vetor[indice_meio];
  int indice_esquerda = indice_inicial;
  int indice_direita = indice_final;

  while (indice_esquerda <= indice_direita) {
    while (vetor[indice_esquerda] < pivo) {
      indice_esquerda++;
    }

    while (vetor[indice_direita] > pivo) {
      indice_direita--;
    }

    if (indice_esquerda <= indice_direita) {
      trocar(&vetor[indice_esquerda], &vetor[indice_direita]);
      indice_esquerda++;
      indice_direita--;
    }
  }

  return indice_esquerda;
}

static void quicksort(int vetor[], int indice_inicial, int indice_final) {
  int indice_particao;

  if (indice_inicial >= indice_final) {
    return;
  }

  indice_particao = particionar(vetor, indice_inicial, indice_final);
  quicksort(vetor, indice_inicial, indice_particao - 1);
  quicksort(vetor, indice_particao, indice_final);
}

int main(void) {
  int vetor[TAMANHO];
  int indice;

  printf("Entre com %d valores:\n", TAMANHO);
  for (indice = 0; indice < TAMANHO; indice++) {
    if (scanf("%d", &vetor[indice]) != 1) {
      fprintf(stderr, "Entrada invalida.\n");
      return EXIT_FAILURE;
    }
  }

  quicksort(vetor, 0, TAMANHO - 1);

  printf("Vetor ordenado: ");
  for (indice = 0; indice < TAMANHO; indice++) {
    printf("%d%s", vetor[indice], indice == TAMANHO - 1 ? "\n" : " | ");
  }

  return EXIT_SUCCESS;
}
