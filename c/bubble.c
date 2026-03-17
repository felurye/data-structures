#include <stdio.h>

int main() {
  int vet[8], i, j, aux;

  printf("Entre com 8 numeros: \n");

  for (i = 0; i < 8; i++) {
    scanf("%d", &vet[i]);
  }

  printf("\n\n Troca: \n\n");

  for (j = 0; j < 8; j++) {
    for (i = 0; i < 7; i++) {
      if (vet[i] > vet[i + 1]) {
        printf("Vet[%d]= %d vet[%d]= %d - ", i, vet[i], i + 1, vet[i + 1]);

        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;

        printf("Vet[%d]= %d vet[%d]= %d \n\n", i, vet[i], i + 1, vet[i + 1]);
      }
    }
    printf("\n");
  }

  printf("\n\n Pos ordenacao: ");

  for (i = 0; i < 8; i++) {
    printf(" %d - ", vet[i]);
  }
  return 0;
}
