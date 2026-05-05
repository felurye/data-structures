#include <stdio.h>
#include <stdlib.h>

typedef struct no_lista {
  int elemento;
  struct no_lista *proximo;
} NoLista;

static NoLista *alocar_no(int valor) {
  NoLista *novo_no = (NoLista *)malloc(sizeof(NoLista));

  if (novo_no == NULL) {
    fprintf(stderr, "Sem memoria disponivel.\n");
    exit(EXIT_FAILURE);
  }

  novo_no->elemento = valor;
  novo_no->proximo = NULL;
  return novo_no;
}

static int lista_esta_vazia(NoLista *lista) { return lista == NULL; }

static NoLista *inserir_no_inicio(NoLista *lista, int valor) {
  NoLista *novo_no = alocar_no(valor);
  novo_no->proximo = lista;
  return novo_no;
}

static NoLista *remover_do_inicio(NoLista *lista) {
  NoLista *no_removido;

  if (lista_esta_vazia(lista)) {
    printf("Lista vazia.\n");
    return lista;
  }

  no_removido = lista;
  lista = lista->proximo;
  printf("%d foi retirado da lista.\n", no_removido->elemento);
  free(no_removido);
  return lista;
}

static void exibir_lista(NoLista *lista) {
  NoLista *no_atual = lista;

  if (lista_esta_vazia(lista)) {
    printf("Lista vazia!\n\n");
    return;
  }

  while (no_atual != NULL) {
    printf("%d%s", no_atual->elemento,
           no_atual->proximo == NULL ? "\n" : " -> ");
    no_atual = no_atual->proximo;
  }
}

static int exibir_menu(void) {
  int opcao;
  printf("Digite uma opcao...\n");
  printf("1- Inserir Elemento na lista... \n");
  printf("2- Retirar Elemento da lista... \n");
  printf("3 - Exibir elementos...\n");
  printf("0- Para sair... \n");
  printf("Opcao: ");

  if (scanf("%d", &opcao) != 1) {
    return -1;
  }

  return opcao;
}

static void liberar_lista(NoLista *lista) {
  while (lista != NULL) {
    NoLista *proximo_no = lista->proximo;
    free(lista);
    lista = proximo_no;
  }
}

int main(void) {
  NoLista *lista = NULL;
  int opcao;

  do {
    opcao = exibir_menu();

    switch (opcao) {
      case 1: {
        int valor;
        printf("Elemento novo: ");
        if (scanf("%d", &valor) == 1) {
          lista = inserir_no_inicio(lista, valor);
        }
        break;
      }
      case 2:
        lista = remover_do_inicio(lista);
        break;
      case 3:
        exibir_lista(lista);
        break;
      case 0:
        break;
      default:
        printf("Comando invalido.\n");
        break;
    }
  } while (opcao != 0);

  liberar_lista(lista);
  return EXIT_SUCCESS;
}
