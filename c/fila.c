#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#include <windows.h>
#define LIMPA_TELA system("cls")
#else
#include <unistd.h>
#define LIMPA_TELA system("/usr/bin/clear")
#endif

#define ESPERA sleep(3)

typedef struct Fila {
  int valor;
  struct Fila *proximo;
} Dados;

void insere();
void exclui();
void mostra();
void mostra_erro();

Dados *principal = NULL;
Dados *final = NULL;

main() {
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
        insere();
        break;
      case '2':
        if (principal != NULL) {
          exclui();
        } else {
          printf("\nA Fila está vazia!\n");
          getchar();
        }
        break;
      case '3':
        if (principal != NULL) {
          mostra();
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
        break;

      default:
        mostra_erro();
        break;
    }
    getchar();
  } while (escolha > 0);
}

void insere() {
  int val;
  LIMPA_TELA;
  printf("\nInserção: \n");
  printf("--------------------------------------\n");
  printf("Insira o valor a ser inserido: ");
  scanf("%d", &val);
  Dados *atual = (Dados *)malloc(sizeof(Dados));
  atual->valor = val;
  atual->proximo = NULL;

  if (principal == NULL) {
    principal = final = atual;
  }

  else {
    final->proximo = atual;
    final = atual;
  }

  printf("\nValor inserido!\n");
  printf("--------------------------------------");
  getchar();
}

void exclui() {
  Dados *auxiliar;
  printf("\nExclusão: \n");
  printf("--------------------------------------\n");
  auxiliar = principal->proximo;
  free(principal);
  principal = auxiliar;
  printf("\nValor excluido!\n");
  printf("--------------------------------------");
  getchar();
}

void mostra() {
  int posicao = 0;
  Dados *nova = principal;
  LIMPA_TELA;
  printf("\nMostrando valores: \n");
  printf("--------------------------------------\n");

  for (; nova != NULL; nova = nova->proximo) {
    posicao++;
    printf("Posição %d, contém o valor %d\n", posicao, nova->valor);
  }
  printf("--------------------------------------");
  getchar();
}

void mostra_erro() {
  LIMPA_TELA;
  printf("\nErro de Digitação: \n");
  printf("--------------------------------------\n");
  printf("\nDigite uma opção válida (pressione -Enter- p/ continuar)!\n\n");
  printf("--------------------------------------");
  getchar();
}
