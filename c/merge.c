#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

static void intercalar(int vetor[], int vetor_auxiliar[], int inicio_primeira,
                       int inicio_segunda, int fim_segunda) {
  int indice_primeira = inicio_primeira;
  int indice_segunda = inicio_segunda;
  int fim_primeira = inicio_segunda - 1;
  int quantidade_mesclada = 0;
  int indice;

  while (indice_primeira <= fim_primeira && indice_segunda <= fim_segunda) {
    if (vetor[indice_primeira] <= vetor[indice_segunda]) {
      vetor_auxiliar[quantidade_mesclada++] = vetor[indice_primeira++];
    } else {
      vetor_auxiliar[quantidade_mesclada++] = vetor[indice_segunda++];
    }
  }

  while (indice_primeira <= fim_primeira) {
    vetor_auxiliar[quantidade_mesclada++] = vetor[indice_primeira++];
  }

  while (indice_segunda <= fim_segunda) {
    vetor_auxiliar[quantidade_mesclada++] = vetor[indice_segunda++];
  }

  for (indice = 0; indice < quantidade_mesclada; indice++) {
    vetor[indice + inicio_primeira] = vetor_auxiliar[indice];
  }
}

static void merge_sort(int vetor[], int vetor_auxiliar[], int indice_esquerda,
                       int indice_direita) {
  int indice_meio;

  if (indice_esquerda < indice_direita) {
    indice_meio = indice_esquerda + (indice_direita - indice_esquerda) / 2;
    merge_sort(vetor, vetor_auxiliar, indice_esquerda, indice_meio);
    merge_sort(vetor, vetor_auxiliar, indice_meio + 1, indice_direita);
    intercalar(vetor, vetor_auxiliar, indice_esquerda, indice_meio + 1,
               indice_direita);
  }
}

int main(void) {
  int vetor[TAMANHO] = {45, 23, 10, 25, 89, 75, 46, 32, 20, 1};
  int vetor_auxiliar[TAMANHO];
  int indice;

  merge_sort(vetor, vetor_auxiliar, 0, TAMANHO - 1);

  printf("| ");
  for (indice = 0; indice < TAMANHO; indice++) {
    printf("%d | ", vetor[indice]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
