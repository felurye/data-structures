#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 100

static void construir_lps(const char padrao[], int tamanho, int lps[]) {
  int comprimento = 0;
  int i = 1;

  lps[0] = 0;

  while (i < tamanho) {
    if (padrao[i] == padrao[comprimento]) {
      comprimento++;
      lps[i] = comprimento;
      i++;
    } else if (comprimento != 0) {
      comprimento = lps[comprimento - 1];
    } else {
      lps[i] = 0;
      i++;
    }
  }
}

static int contar_ocorrencias_kmp(const char texto[], int texto_tam,
                                  const char padrao[], int padrao_tam) {
  int lps[5];
  int i = 0;
  int j = 0;
  int ocorrencias = 0;

  construir_lps(padrao, padrao_tam, lps);

  while (i < texto_tam) {
    if (texto[i] == padrao[j]) {
      i++;
      j++;
    }

    if (j == padrao_tam) {
      ocorrencias++;
      j = lps[j - 1];
    } else if (i < texto_tam && texto[i] != padrao[j]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  return ocorrencias;
}

int main(void) {
  char tab[TAM];
  char padrao[] = "abbac";
  int i;
  int cont = 0;
  int n;

  srand(time(NULL));
  for (i = 0; i < TAM; i++) {
    tab[i] = (char)((rand() % 4) + 'a');
  }

  printf("=================Matriz:=================\n");
  printf("=========================================\n\n");

  for (i = 0; i < TAM; i++) {
    printf("%c |", tab[i]);
    cont++;

    if (cont == 10) {
      printf("\n");
      cont = 0;
    }
  }

  n = contar_ocorrencias_kmp(tab, TAM, padrao, (int)strlen(padrao));

  printf("\n\nForam encontrados %d padroes.\n", n);

  return EXIT_SUCCESS;
}
