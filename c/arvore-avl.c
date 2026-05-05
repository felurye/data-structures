#include <stdio.h>
#include <stdlib.h>

typedef struct no_avl {
  int chave;
  int fator_balanceamento;
  struct no_avl *esquerda;
  struct no_avl *direita;
} NoAvl;

static int total_rotacoes_duplas = 0;
static int total_rotacoes_simples = 0;
static int total_nos_visitados = 0;

static NoAvl *remover_no_avl(NoAvl *raiz, int chave);
static int calcular_fator_balanceamento(NoAvl *raiz);
static NoAvl *rotacao_simples_direita(NoAvl *raiz);
static NoAvl *rotacao_simples_esquerda(NoAvl *raiz);

static NoAvl *criar_no_avl(int chave) {
  NoAvl *novo_no = (NoAvl *)malloc(sizeof(NoAvl));

  if (novo_no == NULL) {
    fprintf(stderr, "Sem memoria disponivel.\n");
    exit(EXIT_FAILURE);
  }

  novo_no->chave = chave;
  novo_no->fator_balanceamento = 0;
  novo_no->esquerda = NULL;
  novo_no->direita = NULL;
  return novo_no;
}

static NoAvl *balancear_no(NoAvl *raiz) {
  int fator = calcular_fator_balanceamento(raiz);

  if (fator < -1) {
    if (calcular_fator_balanceamento(raiz->esquerda) > 0) {
      total_rotacoes_duplas++;
      raiz->esquerda = rotacao_simples_esquerda(raiz->esquerda);
    }
    raiz = rotacao_simples_direita(raiz);
    total_rotacoes_simples++;
  } else if (fator > 1) {
    if (calcular_fator_balanceamento(raiz->direita) < 0) {
      total_rotacoes_duplas++;
      raiz->direita = rotacao_simples_direita(raiz->direita);
    }
    raiz = rotacao_simples_esquerda(raiz);
    total_rotacoes_simples++;
  }

  raiz->fator_balanceamento = calcular_fator_balanceamento(raiz);
  return raiz;
}

static NoAvl *inserir_no_avl(NoAvl *raiz, int chave) {
  if (raiz == NULL) {
    return criar_no_avl(chave);
  }

  total_nos_visitados++;

  if (chave == raiz->chave) {
    return raiz;
  } else if (chave < raiz->chave) {
    raiz->esquerda = inserir_no_avl(raiz->esquerda, chave);
  } else {
    raiz->direita = inserir_no_avl(raiz->direita, chave);
  }

  return balancear_no(raiz);
}

static int calcular_altura(NoAvl *raiz) {
  int altura_esquerda;
  int altura_direita;

  if (raiz == NULL) {
    return -1;
  }

  altura_esquerda = calcular_altura(raiz->esquerda);
  altura_direita = calcular_altura(raiz->direita);
  return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) +
         1;
}

static int calcular_fator_balanceamento(NoAvl *raiz) {
  return calcular_altura(raiz->direita) - calcular_altura(raiz->esquerda);
}

static NoAvl *rotacao_simples_direita(NoAvl *raiz) {
  NoAvl *novo_topo = raiz->esquerda;
  raiz->esquerda = novo_topo->direita;
  novo_topo->direita = raiz;
  return novo_topo;
}

static NoAvl *rotacao_simples_esquerda(NoAvl *raiz) {
  NoAvl *novo_topo = raiz->direita;
  raiz->direita = novo_topo->esquerda;
  novo_topo->esquerda = raiz;
  return novo_topo;
}

static NoAvl *buscar_menor_no(NoAvl *raiz) {
  NoAvl *no_atual = raiz;

  while (no_atual->esquerda != NULL) {
    no_atual = no_atual->esquerda;
  }

  return no_atual;
}

static NoAvl *remover_folha(NoAvl *raiz) {
  printf("\n\n %d removido com sucesso!\n", raiz->chave);
  free(raiz);
  return NULL;
}

static NoAvl *remover_com_filho_esquerdo(NoAvl *raiz) {
  NoAvl *nova_raiz = raiz->esquerda;
  printf("\n\n %d removido com sucesso!\n", raiz->chave);
  free(raiz);
  return nova_raiz;
}

static NoAvl *remover_com_filho_direito(NoAvl *raiz) {
  NoAvl *nova_raiz = raiz->direita;
  printf("\n\n %d removido com sucesso!\n", raiz->chave);
  free(raiz);
  return nova_raiz;
}

static NoAvl *remover_com_dois_filhos(NoAvl *raiz) {
  NoAvl *menor_no = buscar_menor_no(raiz->direita);
  int chave_substituta = menor_no->chave;

  raiz = remover_no_avl(raiz, chave_substituta);
  raiz->chave = chave_substituta;
  return raiz;
}

static NoAvl *remover_no_atual(NoAvl *raiz) {
  if (raiz->direita == NULL && raiz->esquerda == NULL) {
    return remover_folha(raiz);
  }

  if (raiz->direita == NULL) {
    return remover_com_filho_esquerdo(raiz);
  }

  if (raiz->esquerda == NULL) {
    return remover_com_filho_direito(raiz);
  }

  return remover_com_dois_filhos(raiz);
}

static NoAvl *remover_no_avl(NoAvl *raiz, int chave) {
  if (raiz != NULL) {
    if (raiz->chave == chave) {
      raiz = remover_no_atual(raiz);
    } else {
      if (chave < raiz->chave) {
        raiz->esquerda = remover_no_avl(raiz->esquerda, chave);
      } else {
        raiz->direita = remover_no_avl(raiz->direita, chave);
      }

      if (raiz != NULL) {
        raiz = balancear_no(raiz);
      }
    }
  } else {
    printf("\n %d nao foi encontrado.\n", chave);
  }

  return raiz;
}

static void imprimir_em_ordem(NoAvl *raiz) {
  if (raiz != NULL) {
    imprimir_em_ordem(raiz->esquerda);
    printf(" %d |", raiz->chave);
    imprimir_em_ordem(raiz->direita);
  }
}

int main(void) {
  int valor;
  int opcao;
  NoAvl *raiz = NULL;

  do {
    printf("|=======================================|\n");
    printf("|             Arvore AVL                |\n");
    printf("|[1] Inserir                            |\n");
    printf("|[2] Remover                            |\n");
    printf("|[3] Imprimir                           |\n");
    printf("|[0] Sair                               |\n");
    printf("|=======================================|\n");
    printf(" Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        system("cls");
        printf("\n Valor a ser inserido: ");
        scanf("%d", &valor);
        raiz = inserir_no_avl(raiz, valor);
        printf("\n");
        system("pause");
        system("cls");
        break;

      case 2:
        system("cls");
        printf("\n Valor a ser removido: ");
        scanf("%d", &valor);
        raiz = remover_no_avl(raiz, valor);
        printf("\n");
        system("pause");
        system("cls");
        break;

      case 3:
        system("cls");
        printf("\n|");
        imprimir_em_ordem(raiz);
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
  } while (opcao != 0);

  return 0;
}
