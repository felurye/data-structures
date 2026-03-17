#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int chave;
  int fb;
  struct node *esq;
  struct node *dir;
} Node;

int Rdupla = 0;
int rSimples = 0;
int nVisitados = 0;
int comparacoes = 0;

Node *remover_Node(Node *r, int x);
int fator_balanceamento(Node *r);
Node *rotacao_simples_direita(Node *r);
Node *rotacao_simples_esquerda(Node *r);

Node *verifica_balanceamento(Node *r) {
  int fb;
  fb = fator_balanceamento(r);

  if (fb < -1) {
    if (fator_balanceamento(r->esq) > 0) {
      Rdupla++;
      r->esq = rotacao_simples_esquerda(r->esq);
    }
    r = rotacao_simples_direita(r);
    rSimples++;
  } else if (fb > 1) {
    if (fator_balanceamento(r->dir) < 0) {
      Rdupla++;
      r->dir = rotacao_simples_direita(r->dir);
    }
    r = rotacao_simples_esquerda(r);
    rSimples++;
  }
  return r;
}

Node *insere_arvore(Node *r, int num) {
  if (r == NULL) {
    r = (Node *)malloc(sizeof(Node));
    r->chave = num;
    r->dir = NULL;
    r->esq = NULL;
  } else {
    nVisitados++;

    if (num == r->chave) {
      return r;
    } else if (num < r->chave) {
      r->esq = insere_arvore(r->esq, num);
    } else {
      r->dir = insere_arvore(r->dir, num);
    }
    r = verifica_balanceamento(r);
  }
  return r;
}

void busca_in_order(Node *r, int num) {
  if (r != NULL) {
    if (r->chave != num) {
      comparacoes++;

      busca_in_order(r->esq, num);

      busca_in_order(r->dir, num);
    } else {
      printf("%d ", r->chave);
    }
  }
}

void busca_pre_order(Node *r) {
  if (r != NULL) {
    printf("%d ", r->chave);
    busca_pre_order(r->esq);
    busca_pre_order(r->dir);
  }
}

void busca_pos_order(Node *r) {
  if (r != NULL) {
    busca_pos_order(r->esq);
    busca_pos_order(r->dir);
    printf("%d ", r->chave);
  }
}

int altura_arvore(Node *r) {
  if (r == NULL) {
    return -1;
  } else {
    int altEsq, altDir;
    altEsq = altura_arvore(r->esq);
    altDir = altura_arvore(r->dir);
    if (altEsq > altDir) {
      return altEsq + 1;
    } else {
      return altDir + 1;
    }
  }
}

int fator_balanceamento(Node *r) {
  return altura_arvore(r->dir) - altura_arvore(r->esq);
}

Node *rotacao_simples_direita(Node *r) {
  Node *q = r->esq;
  r->esq = q->dir;
  q->dir = r;
  return q;
}

Node *rotacao_simples_esquerda(Node *r) {
  Node *q = r->dir;
  r->dir = q->esq;
  q->esq = r;
  return q;
}

Node *menor_Node(Node *r) {
  Node *aux = r;
  while (aux->esq != NULL) {
    aux = aux->esq;
  }
  return aux;
}

Node *remover_folha(Node *r) {
  printf("\n\n %d removido com sucesso!\n", r->chave);
  free(r);
  return NULL;
}

Node *remover_1filho_esquerda(Node *r) {
  Node *aux = r->esq;
  printf("\n\n %d removido com sucesso!\n", r->chave);
  free(r);
  return aux;
}

Node *remover_1filho_direita(Node *r) {
  Node *aux = r->dir;
  printf("\n\n %d removido com sucesso!\n", r->chave);
  free(r);
  return aux;
}

Node *remover_2filhos(Node *r) {
  Node *aux;
  int x;
  aux = menor_Node(r->dir);
  x = aux->chave;
  r = remover_Node(r, x);

  r->chave = x;
  return r;
}

Node *remover_no(Node *r) {
  if (r->dir == NULL && r->esq == NULL) {
    r = remover_folha(r);
  } else {
    if (r->dir == NULL) {
      r = remover_1filho_esquerda(r);
    } else {
      if (r->esq == NULL) {
        r = remover_1filho_direita(r);
      } else {
        r = remover_2filhos(r);
      }
    }
  }
  return r;
}

Node *remover_Node(Node *r, int x) {
  if (r != NULL) {
    if (r->chave == x) {
      r = remover_no(r);
    } else {
      if (x < r->chave) {
        r->esq = remover_Node(r->esq, x);
      } else {
        r->dir = remover_Node(r->dir, x);
      }
      r = verifica_balanceamento(r);
    }
  } else {
    printf("\n %d nao foi encontrado.\n", x);
  }
  return r;
}

void imprimir(Node *r) {
  if (r) {
    imprimir(r->esq);
    printf(" %d |", r->chave);
    imprimir(r->dir);
  }
}

main() {
  int valor, op, aux = 0;
  Node *raiz;
  raiz = NULL;
  int flag = 0;
  int h = 0;

  do {
    printf("|=======================================|\n");
    printf("|             Arvore AVL                |\n");
    printf("|[1] Inserir                            |\n");
    printf("|[2] Remover                            |\n");
    printf("|[3] Imprimir                           |\n");
    printf("|[0] Sair                               |\n");
    printf("|=======================================|\n");
    printf(" Opcao: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        system("cls");
        printf("\n Valor a ser inserido: ");
        scanf("%d", &valor);
        raiz = insere_arvore(raiz, valor);
        printf("\n");
        system("pause");
        system("cls");
        break;

      case 2:
        system("cls");
        printf("\n Valor a ser removido: ");
        scanf("%d", &valor);
        raiz = remover_Node(raiz, valor);
        printf("\n");
        system("pause");
        system("cls");
        break;

      case 3:
        system("cls");
        printf("\n|");
        imprimir(raiz);
        printf("\n\n");
        system("pause");
        system("cls");
        break;

      case 0:
        system("cls");
        printf("\n Encerrado com sucesso! :)\n");
        break;

      default:
        system("cls");
        printf("\n !! Entre com uma opcao valida !!\n\n");
        system("pause");
        system("cls");
        break;
    }
  } while (op != 0);
}
