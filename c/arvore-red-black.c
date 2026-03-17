#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct noh {
  int chave;
  char cor;
  struct noh *dir;
  struct noh *esq;
  struct noh *pai;
};

struct noh *pai(struct noh *n) { return n->pai; }

struct noh *irmao(struct noh *n) {
  struct noh *p = pai(n);
  if (p == NULL) {
    return NULL;
  }
  if (n == p->esq) {
    return p->dir;
  } else {
    return p->esq;
  }
}

struct noh *avo(struct noh *n) {
  if ((n != NULL) && (n->pai != NULL)) {
    return n->pai->pai;
  } else {
    return NULL;
  }
}

struct noh *tio(struct noh *n) {
  struct noh *a = avo(n);
  if (a == NULL) {
    return NULL;
  }
  if (n->pai == a->esq) {
    return a->dir;
  } else {
    return a->esq;
  }
}

struct noh *insercao(struct noh *raiz, struct noh *n) {
  insercao_noh(raiz, n);

  casos_insercao(n);

  raiz = n;

  while (raiz->pai != NULL) {
    raiz = raiz->pai;
  }

  return raiz;
}

void insercao_noh(struct noh *raiz, struct noh *n) {
  if (raiz != NULL && n->chave == raiz->chave) {
    printf("O noh ja existe!!!\n");
  } else if (raiz != NULL && n->chave < raiz->chave) {
    if (raiz->esq != NULL) {
      insercao_noh(raiz->esq, n);
      return;
    } else {
      raiz->esq = n;
    }
  } else if (raiz != NULL) {
    if (raiz->dir != NULL) {
      insercao_noh(raiz->dir, n);
      return;
    } else {
      raiz->dir = n;
    }
  }
  n->pai = raiz;
  n->esq = NULL;
  n->dir = NULL;
  n->cor = 'V';
}

void casos_insercao(struct noh *n) {
  struct noh *t = tio(n);

  if (n->pai == NULL) {
    insercao_caso1(n);
  } else if (n->pai->cor == 'P') {
    insercao_caso2(n);
  } else if (t != NULL && t->cor == 'V') {
    insercao_caso3(n);
  } else {
    insercao_caso4(n);
  }
}

void insercao_caso1(struct noh *n) {
  if (n->pai == NULL) {
    n->cor = 'P';
  }
}

void insercao_caso2(struct noh *n) { return; }

void insercao_caso3(struct noh *n) {
  struct noh *p = pai(n);
  struct noh *t = tio(n);
  struct noh *a = avo(n);

  p->cor = 'P';
  t->cor = 'P';
  a->cor = 'V';

  casos_insercao(a);
}

void rotacao_esq(struct noh *n) {
  struct noh *nnew = n->dir;
  struct noh *p = pai(n);

  if ((p != NULL) && (p->dir == n)) {
    n->pai->dir = nnew;
  } else if (p != NULL) {
    n->pai->esq = nnew;
  }

  if (nnew->esq != NULL) {
    nnew->esq->pai = n;
  }

  n->dir = nnew->esq;
  nnew->esq = n;
  nnew->pai = n->pai;
  n->pai = nnew;
}

void rotacao_dir(struct noh *n) {
  struct noh *nnew = n->esq;
  struct noh *p = pai(n);

  if ((p != NULL) && (p->dir == n)) {
    n->pai->dir = nnew;
  } else if (p != NULL) {
    n->pai->esq = nnew;
  }

  if (nnew->dir != NULL) {
    nnew->dir->pai = n;
  }

  n->esq = nnew->dir;
  nnew->dir = n;
  nnew->pai = n->pai;
  n->pai = nnew;
}

void insercao_caso4(struct noh *n) {
  struct noh *p = pai(n);
  struct noh *a = avo(n);

  if ((a->esq != NULL) && (n == a->esq->dir)) {
    rotacao_esq(p);
    n = n->esq;
  } else if ((a->dir != NULL) && (n == a->dir->esq)) {
    rotacao_dir(p);
    n = n->dir;
  }

  insercao_caso4_2(n);
}

void insercao_caso4_2(struct noh *n) {
  struct noh *p = pai(n);
  struct noh *a = avo(n);

  if (n == p->esq) {
    rotacao_dir(a);
  } else {
    rotacao_esq(a);
  }

  p->cor = 'P';
  a->cor = 'V';
}

struct noh *busca(struct noh *raiz, int chave) {
  struct noh *elem;

  if (raiz == NULL) {
    printf("O valor buscado não existe!\n");
    return NULL;
  }

  if (raiz->chave == chave) {
    printf("Valor encontrado!\n");
    return raiz;
  } else if (raiz->chave < chave) {
    elem = busca(raiz->dir, chave);
  } else if (raiz->chave > chave) {
    elem = busca(raiz->esq, chave);
  }

  return elem;
}

struct noh *antecessor(struct noh *n) {
  if (n->dir == NULL) {
    return n;
  }
  antecessor(n->dir);
}

struct noh *remocao_caso1(struct noh *n, struct noh *filho) {
  filho->pai = n->pai;
  if (n == n->pai->esq) {
    filho->pai->esq = filho;
  } else {
    filho->pai->dir = filho;
  }

  return filho;
}

struct noh *remocao_caso2(struct noh *n) {
  struct noh *filho = (n->dir == NULL) ? n->esq : n->dir;

  filho = remocao_caso1(n, filho);
  if (n->cor == 'P') {
    printf("filho_elem_preto\n");
    if (filho->cor == 'V')
      filho->cor = 'P';
    else
      printf("delete_case1\n");
  }
  free(n);
  return filho;
}

void remocao(struct noh *raiz, int chave) {
  struct noh *elem = busca(raiz, chave);
  printf("raiz: %d\n", raiz->chave);

  if (elem == NULL) {
    printf("Valor nao encontrado!!\n");
    return;
  }

  if (elem->dir != NULL && elem->esq != NULL) {
    struct noh *maisProximo = antecessor(elem->esq);
    elem->chave = maisProximo->chave;
    remocao(elem->esq, maisProximo->chave);
  } else if (elem->dir != NULL || elem->esq != NULL) {
    remocao_caso2(elem);
  } else if (elem->cor == 'P') {
    struct noh *i = irmao(elem);
    if (i->cor == 'V') {
      i->cor = 'P';
      raiz->pai = 'V';
      raiz->pai->dir == NULL;
      raiz = NULL;
    } else {
      if (i->dir != NULL && i->esq != NULL) {
        i->pai->dir == NULL;
        i->pai->dir->pai = NULL;
        rotacao_dir(i->pai);
        i->cor = 'V';
        i->dir->cor = 'P';
        i->esq->cor = 'P';
        imprimir_RED(i->pai->pai);
      } else {
        if (i->esq != NULL) {
          i->pai->dir == NULL;
          i->pai->dir->pai = NULL;

          rotacao_dir(i->pai);
          imprimir_RED(i->pai->pai);
        } else if (i->dir != NULL) {
          struct noh *a = avo(i->dir);
          if (i->dir == a->dir->esq) {
            rotacao_dir(a);
          }
        }
      }
    }
  } else {
    struct noh *pai_elem = pai(elem);
    if (pai_elem != NULL && pai_elem->dir == elem) {
      pai_elem->dir = NULL;
    } else if (pai_elem != NULL) {
      pai_elem->esq = NULL;
    }
    free(elem);
  }
}

void imprimir_ERD(struct noh *raiz) {
  if (raiz == NULL) return;
  imprimir_ERD(raiz->esq);

  printf("Chave: %4d | Cor: %c ", raiz->chave, raiz->cor);

  if (raiz->pai != NULL)
    printf("| Pai: %4d ", raiz->pai->chave);
  else
    printf("| Pai: NULL ");

  if (raiz->esq != NULL)
    printf("| ESQ: %4d ", raiz->esq->chave);
  else
    printf("| ESQ: NULL ");

  if (raiz->dir != NULL)
    printf("| DIR: %4d ", raiz->dir->chave);
  else
    printf("| DIR: NULL ");

  printf("\n");

  imprimir_ERD(raiz->dir);
}

void imprimir_RED(struct noh *raiz) {
  if (raiz == NULL) return;

  printf("Chave: %4d | Cor: %c ", raiz->chave, raiz->cor);

  if (raiz->pai != NULL)
    printf("| Pai: %4d ", raiz->pai->chave);
  else
    printf("| Pai: NULL ");

  if (raiz->esq != NULL)
    printf("| ESQ: %4d ", raiz->esq->chave);
  else
    printf("| ESQ: NULL ");

  if (raiz->dir != NULL)
    printf("| DIR: %4d ", raiz->dir->chave);
  else
    printf("| DIR: NULL ");

  printf("\n");

  imprimir_RED(raiz->esq);
  imprimir_RED(raiz->dir);
}

menu() {
  system("cls");
  printf("**************************************\n");
  printf("|              Red black             |\n");
  printf("**************************************\n");
  printf(" (1) Inserir.\n");
  printf(" (2) Buscar.\n");
  printf(" (3) Remover.\n");
  printf(" (4) Imprimir.\n");
  printf(" (0) Encerrar.\n");
  printf("==========================\n");
  printf("Opcao: ");
}

main() {
  struct noh *raiz;
  raiz = NULL;

  struct noh *elem;
  struct noh *no[MAX];
  int i, max, chave, opcao;

  do {
    menu();
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Valor: ");
        scanf("%d", &chave);

        if (raiz == NULL) {
          raiz = (struct noh *)malloc(sizeof(struct noh));
          raiz->chave = chave;
          raiz->esq = NULL;
          raiz->dir = NULL;
          raiz->pai = NULL;
          raiz->cor = 'P';
        } else {
          no[i] = (struct noh *)malloc(sizeof(struct noh));
          no[i]->chave = chave;
          raiz = insercao(raiz, no[i]);
        }
        break;

      case 2:
        printf("Valor: ");
        scanf("%d", &chave);
        elem = busca(raiz, chave);
        if (elem == NULL) {
          printf("Noh nao encontrado!\n");
        } else {
          printf("Noh encontrado!\n");
        }

        system("pause");
        break;

      case 3:
        printf("Valor: ");
        scanf("%d", &chave);
        remocao(raiz, chave);
        break;
      case 4:
        system("cls");
        printf("Impressao ERD:\n");
        imprimir_ERD(raiz);
        printf("\n");
        system("pause");
        break;
      default:
        printf("Entre com uma opcao valida!!!\n");
        break;
    }
  } while (opcao != 0);
}
