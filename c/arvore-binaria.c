#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore {
  int chave;
  struct no_arvore *esquerda;
  struct no_arvore *direita;
} NoArvore;

static NoArvore *criar_no(int chave) {
  NoArvore *novo_no = (NoArvore *)malloc(sizeof(NoArvore));

  if (novo_no == NULL) {
    fprintf(stderr, "Sem memoria disponivel.\n");
    exit(EXIT_FAILURE);
  }

  novo_no->esquerda = NULL;
  novo_no->direita = NULL;
  novo_no->chave = chave;
  return novo_no;
}

static void inserir_no(NoArvore *raiz, int chave) {
  if (chave == raiz->chave) {
    return;
  }

  if (chave < raiz->chave) {
    if (raiz->esquerda == NULL) {
      raiz->esquerda = criar_no(chave);
    } else {
      inserir_no(raiz->esquerda, chave);
    }
  } else if (raiz->direita == NULL) {
    raiz->direita = criar_no(chave);
  } else {
    inserir_no(raiz->direita, chave);
  }
}

static NoArvore *buscar_no(NoArvore *raiz, int chave_buscada) {
  if (raiz == NULL) {
    printf("Numero nao encontrado!!\n");
    return NULL;
  }

  if (raiz->chave == chave_buscada) {
    printf("Numero encontrado!!\n");
    return raiz;
  }

  if (chave_buscada < raiz->chave) {
    return buscar_no(raiz->esquerda, chave_buscada);
  }

  return buscar_no(raiz->direita, chave_buscada);
}

static void imprimir_em_ordem(NoArvore *raiz) {
  if (raiz != NULL) {
    imprimir_em_ordem(raiz->esquerda);
    printf(" %d |", raiz->chave);
    imprimir_em_ordem(raiz->direita);
  }
}

static void liberar_arvore(NoArvore *raiz) {
  if (raiz != NULL) {
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
  }
}

static int calcular_altura(NoArvore *raiz) {
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

static int calcular_fator_balanceamento(NoArvore *raiz) {
  if (raiz == NULL) {
    return 0;
  }

  return calcular_altura(raiz->direita) - calcular_altura(raiz->esquerda);
}

int main(void) {
  NoArvore *raiz = NULL;
  int valor;
  int opcao = 0;

  while (opcao != 5) {
    printf("\n\n|===================================================|");
    printf("\n|              Arvore Binaria de Busca              |");
    printf("\n|[1] Inserir                                        |");
    printf("\n|[2] Buscar                                         |");
    printf("\n|[3] Imprimir                                       |");
    printf("\n|[4] Fator Balanceamento                            |");
    printf("\n|[5] Sair                                           |");
    printf("\n|===================================================|");
    printf("\nOpcao: ");
    if (scanf("%d", &opcao) != 1) {
      fprintf(stderr, "Entrada invalida.\n");
      liberar_arvore(raiz);
      return EXIT_FAILURE;
    }

    switch (opcao) {
      case 1:
        if (raiz == NULL) {
          printf("\nEntre com um valor, para raiz: ");
          scanf("%d", &valor);
          raiz = criar_no(valor);
        } else {
          printf("\nEntre com um valor: ");
          scanf("%d", &valor);
          inserir_no(raiz, valor);
        }
        break;
      case 2:
        if (raiz == NULL) {
          printf("\nArvore vazia.\n");
          break;
        }
        printf("\nEntre com o valor que deseja buscar: ");
        scanf("%d", &valor);
        buscar_no(raiz, valor);
        break;
      case 3:
        printf("|");
        imprimir_em_ordem(raiz);
        break;
      case 4:
        printf("\nFator de balanceamento da raiz: %d\n",
               calcular_fator_balanceamento(raiz));
        break;
      case 5:
        break;
      default:
        printf("\nDigite uma opcao!");
        break;
    }
  }

  liberar_arvore(raiz);
  return EXIT_SUCCESS;
}
