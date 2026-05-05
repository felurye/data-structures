#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 10
#define VAZIO 0
#define OCUPADO 1
#define REMOVIDO 2

typedef struct {
  int valor;
  int estado;
} EntradaHash;

static int calcular_hash(int valor) {
  int indice = valor % TAMANHO_TABELA;
  return indice < 0 ? -indice : indice;
}

static void inicializar_tabela(EntradaHash tabela[]) {
  int indice;

  for (indice = 0; indice < TAMANHO_TABELA; indice++) {
    tabela[indice].valor = 0;
    tabela[indice].estado = VAZIO;
  }
}

static int buscar_posicao(const EntradaHash tabela[], int valor) {
  int indice_inicial = calcular_hash(valor);
  int tentativa;

  for (tentativa = 0; tentativa < TAMANHO_TABELA; tentativa++) {
    int posicao = (indice_inicial + tentativa) % TAMANHO_TABELA;

    if (tabela[posicao].estado == VAZIO) {
      return -1;
    }

    if (tabela[posicao].estado == OCUPADO && tabela[posicao].valor == valor) {
      return posicao;
    }
  }

  return -1;
}

static int inserir_valor(EntradaHash tabela[], int valor) {
  int indice_inicial = calcular_hash(valor);
  int primeira_posicao_removida = -1;
  int tentativa;

  if (buscar_posicao(tabela, valor) != -1) {
    return 0;
  }

  for (tentativa = 0; tentativa < TAMANHO_TABELA; tentativa++) {
    int posicao = (indice_inicial + tentativa) % TAMANHO_TABELA;

    if (tabela[posicao].estado == REMOVIDO &&
        primeira_posicao_removida == -1) {
      primeira_posicao_removida = posicao;
    }

    if (tabela[posicao].estado == VAZIO) {
      int posicao_destino =
          primeira_posicao_removida == -1 ? posicao : primeira_posicao_removida;
      tabela[posicao_destino].valor = valor;
      tabela[posicao_destino].estado = OCUPADO;
      return 1;
    }
  }

  if (primeira_posicao_removida != -1) {
    tabela[primeira_posicao_removida].valor = valor;
    tabela[primeira_posicao_removida].estado = OCUPADO;
    return 1;
  }

  return 0;
}

static int remover_valor(EntradaHash tabela[], int valor) {
  int posicao = buscar_posicao(tabela, valor);

  if (posicao == -1) {
    return 0;
  }

  tabela[posicao].estado = REMOVIDO;
  return 1;
}

static void imprimir_tabela(const EntradaHash tabela[]) {
  int indice;

  for (indice = 0; indice < TAMANHO_TABELA; indice++) {
    if (tabela[indice].estado == OCUPADO) {
      printf("Elemento: %d | Hash: %d | Posicao: %d.\n", tabela[indice].valor,
             calcular_hash(tabela[indice].valor), indice);
    }
  }
}

int main(void) {
  EntradaHash tabela[TAMANHO_TABELA];
  int opcao;
  int valor;

  inicializar_tabela(tabela);

  do {
    printf("*******************TABELA HASH*******************\n");
    printf("*************************************************\n");
    printf("(1) Inserir\n");
    printf("(2) Buscar\n");
    printf("(3) Excluir\n");
    printf("(4) Imprimir\n");
    printf("(0) Sair\n");
    printf("\nEntre com uma opcao acima: ");

    if (scanf("%d", &opcao) != 1) {
      fprintf(stderr, "Entrada invalida.\n");
      return EXIT_FAILURE;
    }

    switch (opcao) {
      case 1:
        printf("Valor: ");
        scanf("%d", &valor);

        if (inserir_valor(tabela, valor)) {
          printf("Inserido!\n");
        } else {
          printf("Tabela cheia ou elemento ja existente.\n");
        }
        break;

      case 2:
        printf("Valor: ");
        scanf("%d", &valor);

        if (buscar_posicao(tabela, valor) != -1) {
          printf("Elemento encontrado.\n");
        } else {
          printf("Elemento nao encontrado.\n");
        }
        break;

      case 3:
        printf("Valor: ");
        scanf("%d", &valor);

        if (remover_valor(tabela, valor)) {
          printf("Removido!\n");
        } else {
          printf("Elemento nao encontrado.\n");
        }
        break;

      case 4:
        imprimir_tabela(tabela);
        break;

      case 0:
        printf("\nVolte sempre!! :)\n");
        break;

      default:
        printf("Entre com uma opcao valida!!!\n");
        break;
    }
  } while (opcao != 0);

  return EXIT_SUCCESS;
}
