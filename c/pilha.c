#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 20

typedef struct {
  int topo;
  char elementos[TAMANHO];
} Pilha;

static int pilha_vazia(const Pilha *p);
static int pilha_cheia(const Pilha *p);
static void pilha_inicializar(Pilha *p);
static int pilha_empilhar(Pilha *p, char simbolo);
static int pilha_desempilhar(Pilha *p, char *simbolo);


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
  size_t i;

  pilha_inicializar(&pilha);

  for (i = 0; expressao[i] != '\0'; i++) {
    char c = expressao[i];

    if (c == '(') {
      if (!pilha_empilhar(&pilha, c)) {
        /* estouro de capacidade */
        return 0;
      }
    } else if (c == ')') {
      char topo;
      if (!pilha_desempilhar(&pilha, &topo)) {
        /* fecha sem abrir */
        return 0;
      }
    }
  }

  return pilha_vazia(&pilha);
}

static void pilha_inicializar(Pilha *p) { p->topo = -1; }

static int pilha_vazia(const Pilha *p) { return p->topo == -1; }

static int pilha_cheia(const Pilha *p) { return p->topo == TAMANHO - 1; }

static int pilha_empilhar(Pilha *p, char simbolo) {
  if (pilha_cheia(p)) {
    return 0;
  }

  p->topo++;
  p->elementos[p->topo] = simbolo;
  return 1;
}

static int pilha_desempilhar(Pilha *p, char *simbolo) {

  if (pilha_vazia(p)) {
    return 0;
  }

  *simbolo = p->elementos[p->topo];
  p->topo--;
  return 1;
}
