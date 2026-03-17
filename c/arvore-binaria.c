#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int chave;
  struct node *esq;
  struct node *dir;
} Node;

Node *criaRaiz(int novo) {
  Node *pNovo;

  pNovo = (Node *)malloc(sizeof(Node));

  pNovo->esq = NULL;
  pNovo->dir = NULL;
  pNovo->chave = novo;

  return pNovo;
}

void inserir(Node *r, int novo) {
  Node *pNovo;

  pNovo = (Node *)malloc(sizeof(Node));

  pNovo->esq = NULL;
  pNovo->dir = NULL;
  pNovo->chave = novo;

  if (r->chave > pNovo->chave) {
    if (r->esq == NULL) {
      r->esq = pNovo;
    } else {
      inserir(r->esq, novo);
    }
  } else {
    if (r->dir == NULL) {
      r->dir = pNovo;
    } else {
      inserir(r->dir, novo);
    }
  }
}
Node *buscar(Node *r, int k) {
  if (r->chave > k) {
    return buscar(r->esq, k);
  } else {
    return buscar(r->dir, k);
  }
  if (r->chave == k) {
    printf("Numero encontrado!!");
    return r;
  } else {
    printf("Numero nao encontrado!!");
    return r;
  }
}

void imprimir(Node *r) {
  if (r) {
    imprimir(r->esq);
    printf(" %d |", r->chave);
    imprimir(r->dir);
  }
}

int main() {
  Node *pRaiz;
  int valor, op, aux = 0;

  while (op != 4) {
    printf("\n\n|===================================================|");
    printf("\n|              Arvore Binaria de Busca              |");
    printf("\n|[1] Inserir                                        |");
    printf("\n|[2] Buscar                                         |");
    printf("\n|[3] Imprimir                                       |");
    printf("\n|[4] Fator Balanceamento                            |");
    printf("\n|[5] Sair                                           |");
    printf("\n|===================================================|");
    printf("\nOpcao: ");
    scanf("%d", &op);

    system("cls");

    switch (op) {
      case 1:
        if (aux == 0) {
          printf("\nEntre com um valor, para raiz: ");
          scanf("%d", &valor);
          pRaiz = criaRaiz(valor);
          aux = 1;
          system("cls");
        } else {
          printf("\nEntre com um valor: ");
          scanf("%d", &valor);
          inserir(pRaiz, valor);
          system("cls");
        }
        break;
      case 2:
        printf("\nEntre com o valor que deseja buscar: ");
        scanf("%d", &valor);
        buscar(pRaiz, valor);
        break;
      case 3:
        printf("|");
        imprimir(pRaiz);
        break;
      case 4:
        printf("\nOutra coisa.");
        break;
      default:
        printf("\nDigite uma opcao!");
        break;
    }
  }
}
