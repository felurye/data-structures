#include <stdio.h>
#include <stdlib.h>

struct node {
  int elemento;
  struct node *proximo;
};

typedef struct node node;

struct node *inserir_lista(struct node *inicio, struct node *lista, int i) {
  lista->elemento = i;
  lista->proximo = inicio;
  return lista;
}

struct node *retirar_lista(struct node *lista) {
  struct node *no1;
  int x;
  // no1 = (struct node*)(malloc(sizeof(struct node)));
  if (lista->proximo == NULL) {
    printf("\n Impossivel retirar elemento da lista.");
    return lista;
  } else {
    no1 = lista;
    lista = no1->proximo;
    x = no1->elemento;
    printf("\n %d foi retirado da lista", x);
    return lista;
  }
}

node *aloca() {
  node *novo = (node *)malloc(sizeof(node));
  if (!novo) {
    printf("Sem memoria disponivel...\n");
    exit(1);

  } else {
    printf("Elemento novo: ...");
    scanf("%d", &novo->proximo);
    return novo;
  }
}

void inicia(node *lista) { lista->proximo = NULL; }

int vazia(node *lista) {
  if (lista->proximo == NULL)
    return 1;
  else
    return 0;
}

void Insere_Elemento(node *lista) {
  node *novo = aloca();
  node *tmp = lista->proximo;
  lista->proximo = novo;
  novo->proximo = tmp;
}

void Exibe(node *lista) {
  if (!vazia(lista)) {
    printf("Lista vazia!\n\n");
  }
  node *tmp;
  tmp = lista->proximo;
  while (tmp != NULL) {
    printf("%d", tmp->elemento);
    tmp = tmp->proximo;
  }
  printf("\n\n");
}

int menu(void) {
  int opcao;
  printf("Digite uma opcao...\n");
  printf("1- Inserir Elemento na lista... \n");
  printf("2- Retirar Elemento da lista... \n");
  printf("3 - Exibir elementos...\n");
  printf("0- Para sair... \n");
  scanf("%d", &opcao);
}

int opcao(node *lista, int op) {
  node *tmp;
  switch (op) {
    case 0:
      exit(1);
      break;
    case 1:
      Insere_Elemento(lista);
      break;
      /*case 2:
                      tmp= Retira_Elemento(lista);
                      printf("Retirado: %d\n\n", tmp->elemento);
                      break;*/
    case 3:
      Exibe(lista);
      break;
    default:
      printf("Comando invalido/n");
  }
}

int main() {
  node *lista = (node *)malloc(sizeof(node));
  if (!lista) {
    printf("Sem memoria disponivel...");
    exit(1);
  } else {
    inicia(lista);
    int opt;
    do {
      opt = menu();
      opcao(lista, opt);
    } while (opt);
  }

  return 0;
}
