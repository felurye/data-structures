#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 20

typedef struct {
  int topo;
  char elementos[TAMANHO];
} Pilha;

static int pilha_esta_vazia(const Pilha *pilha);
static int pilha_esta_cheia(const Pilha *pilha);
static void inicializar_pilha(Pilha *pilha);
static int empilhar(Pilha *pilha, char simbolo);
static int desempilhar(Pilha *pilha, char *simbolo);
static int validar_parenteses(const char *expressao);

int main(void) {
  char expressao[TAMANHO];

  printf("\nDigite a expressao matematica desejada: ");

  if (fgets(expressao, sizeof(expressao), stdin) == NULL) {
    fprintf(stderr, "Erro ao ler a expressao.\n");
    return EXIT_FAILURE;
  }

  expressao[strcspn(expressao, "\n")] = '\0';

  if (validar_parenteses(expressao)) {
    printf("Expressao matematica valida!\n");
  } else {
    printf("Expressao matematica invalida!\n");
  }

  return EXIT_SUCCESS;
}

static int validar_parenteses(const char *expressao) {
  Pilha pilha;
  size_t indice;

  inicializar_pilha(&pilha);

  for (indice = 0; expressao[indice] != '\0'; indice++) {
    char caractere = expressao[indice];

    if (caractere == '(') {
      if (!empilhar(&pilha, caractere)) {
        return 0;
      }
    } else if (caractere == ')') {
      char topo;
      if (!desempilhar(&pilha, &topo)) {
        return 0;
      }
    }
  }

  return pilha_esta_vazia(&pilha);
}

static void inicializar_pilha(Pilha *pilha) { pilha->topo = -1; }

static int pilha_esta_vazia(const Pilha *pilha) { return pilha->topo == -1; }

static int pilha_esta_cheia(const Pilha *pilha) {
  return pilha->topo == TAMANHO - 1;
}

static int empilhar(Pilha *pilha, char simbolo) {
  if (pilha_esta_cheia(pilha)) {
    return 0;
  }

  pilha->topo++;
  pilha->elementos[pilha->topo] = simbolo;
  return 1;
}

static int desempilhar(Pilha *pilha, char *simbolo) {
  if (pilha_esta_vazia(pilha)) {
    return 0;
  }

  *simbolo = pilha->elementos[pilha->topo];
  pilha->topo--;
  return 1;
}
