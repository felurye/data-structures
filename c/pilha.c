#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 20

struct pilha {
  int topo;
  char elementos[TAMANHO];
};

int tamanho_string(char *st);
int pilha_vazia(struct pilha p);
void empilhar(struct pilha *p, char simbolo);
char desempilhar(struct pilha *p);
char topo_da_pilha(struct pilha p);

main() {
  char expressao[TAMANHO], elem;
  int cont, i, valida, tamanho;

  printf("\nDigite a expressao matematica desejada: ");
  scanf("%s", &expressao);

  tamanho = tamanho_string(expressao);

  printf("%d", tamanho);

  struct pilha s;
  s.topo = -1;
  cont = 0;
  valida = 1;

  elem = expressao[cont];

  while (cont < TAMANHO || elem == '\0') {
    if (elem == '(') empilhar(&s, elem);
    if (elem == ')') {
      if (pilha_vazia(s))
        valida = 0;
      else
        desempilhar(&s);
    }
    elem = expressao[cont];
    cont++;
  }
  if (valida == 1 && pilha_vazia(s))
    printf("Expressao Matematica Valida!!!");
  else
    printf("Expressao Matematica Invalida!!!");
}

int tamanho_string(char *st) {
  int i;
  for (i = 0; st[i] != '\0'; i++);
  return (i);
}

int pilha_vazia(struct pilha p) {
  if (p.topo == -1)
    return (1);
  else
    return (0);
}

void empilhar(struct pilha *p, char simbolo) {
  int top;
  top = p->topo;
  p->elementos[top + 1] = simbolo;
  p->topo = top + 1;
}

char desempilhar(struct pilha *p) {
  char aux;
  int top;
  if (pilha_vazia(*p)) {
    printf("\nA pilha esta vazia, impossivel desempilhar");
    return ('0');
  } else {
    aux = p->elementos[p->topo];
    top = p->topo;
    p->topo = top - 1;
    return (aux);
  }
}

char topo_da_pilha(struct pilha p) { return (p.elementos[p.topo]); }
