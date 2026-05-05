#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#define LIMPA_TELA system("cls")
#define ESPERA Sleep(3000)
#else
#include <unistd.h>
#define LIMPA_TELA system("/usr/bin/clear")
#define ESPERA sleep(3)
#endif

typedef struct no_fila {
  int valor;
  struct no_fila *proximo;
} NoFila;

static void inserir_na_fila(void);
static void remover_da_fila(void);
static void mostrar_fila(void);
static void mostrar_erro(void);

static NoFila *inicio_fila = NULL;
static NoFila *fim_fila = NULL;

int main(void) {
  char escolha;

  do {
    LIMPA_TELA;
    printf("\nMétodo Fila\n\n");
    printf("Escolha uma opção: \n");
    printf("\t1 - Inserir valor na Fila\n");
    printf("\t2 - Remover valor da Fila\n");
    printf("\t3 - Mostrar valores da Fila\n");
    printf("\t9 - Sair\n\n");
    printf("Resposta: ");
    scanf("%c", &escolha);
    switch (escolha) {
      case '1':
        inserir_na_fila();
        break;
      case '2':
        if (inicio_fila != NULL) {
          remover_da_fila();
        } else {
          printf("\nA Fila está vazia!\n");
          getchar();
        }
        break;
      case '3':
        if (inicio_fila != NULL) {
          mostrar_fila();
        } else {
          printf("\nA Fila está vazia!\n");
          getchar();
        }
        break;
      case '9':
        printf("\nObrigado por utilizar esse programa!\n");
        printf("------>Terminal de Informação<------\n\n");
        ESPERA;
        exit(0);

      default:
        mostrar_erro();
        break;
    }
    getchar();
  } while (escolha > 0);

  return 0;
}

static void inserir_na_fila(void) {
  int valor;
  NoFila *novo_no;

  LIMPA_TELA;
  printf("\nInserção: \n");
  printf("--------------------------------------\n");
  printf("Insira o valor a ser inserido: ");
  scanf("%d", &valor);

  novo_no = (NoFila *)malloc(sizeof(NoFila));
  novo_no->valor = valor;
  novo_no->proximo = NULL;

  if (inicio_fila == NULL) {
    inicio_fila = fim_fila = novo_no;
  } else {
    fim_fila->proximo = novo_no;
    fim_fila = novo_no;
  }

  printf("\nValor inserido!\n");
  printf("--------------------------------------");
  getchar();
}

static void remover_da_fila(void) {
  NoFila *proximo_no;

  printf("\nExclusão: \n");
  printf("--------------------------------------\n");
  proximo_no = inicio_fila->proximo;
  free(inicio_fila);
  inicio_fila = proximo_no;
  if (inicio_fila == NULL) {
    fim_fila = NULL;
  }
  printf("\nValor excluido!\n");
  printf("--------------------------------------");
  getchar();
}

static void mostrar_fila(void) {
  int posicao = 0;
  NoFila *no_atual = inicio_fila;

  LIMPA_TELA;
  printf("\nMostrando valores: \n");
  printf("--------------------------------------\n");

  for (; no_atual != NULL; no_atual = no_atual->proximo) {
    posicao++;
    printf("Posição %d, contém o valor %d\n", posicao, no_atual->valor);
  }
  printf("--------------------------------------");
  getchar();
}

static void mostrar_erro(void) {
  LIMPA_TELA;
  printf("\nErro de Digitação: \n");
  printf("--------------------------------------\n");
  printf("\nDigite uma opção válida (pressione -Enter- p/ continuar)!\n\n");
  printf("--------------------------------------");
  getchar();
}
