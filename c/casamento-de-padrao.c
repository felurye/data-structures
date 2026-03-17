#include <stdio.h>
#include <stdlib.h>

#include "time.h"

#define TAM 100

int main() {
  int mat[TAM];
  char tab[TAM];
  char p[5] = {'a', 'b', 'b', 'a', 'c'};
  int i, cont = 0, n = 0;

  srand(time(NULL));
  for (i = 0; i < TAM; i++) {
    mat[i] = (rand() % 4) + 97;
  }

  printf("=================Matriz:=================\n");
  printf("=========================================\n\n");

  for (i = 0; i < TAM; i++) {
    tab[i] = (char)mat[i];
  }

  for (i = 0; i < TAM; i++) {
    printf("%c |", tab[i]);
    cont = cont + 1;

    if (cont == 10) {
      printf("\n");
      cont = 0;
    }
  }

  for (i = 0; i < TAM - 4; i++) {
    if (tab[i] == p[0] && tab[i + 1] == p[1] && tab[i + 2] == p[2] &&
        tab[i + 3] == p[3] && tab[i + 4] == p[4]) {
      n = n + 1;
    }
  }

  printf("\n\nForam encontrados %d padroes.\n", n);

  return 0;
}
