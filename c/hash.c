#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// Fun��o respons�vel pelo c�lculo do hash, onde hash= |x mod tamanho|;
int hash(int x) { return (abs(x % TAM)); }

// Fun��o respons�vel pelo tratamento de colis�es;
colisao(int tabela[TAM][2], int elem, int h) {
  int i = h;

  // La�o de repeti��o respos�vel por percorrer a matrix a procura de uma
  // posi��o vazia e controle de colis�es;
  while (i < TAM && tabela[i][0] != -1) {
    // Sempre que uma posi��o estiver ocupada, ser� acrescentado +1 a colis�o

    tabela[i][1] = tabela[i][1] + 1;
    i++;
  }

  if (i < TAM)
    tabela[i][0] = elem;
  else {
    i = 0;

    while (i < h && tabela[i][0] != -1) {
      tabela[i][1] = tabela[i][1] + 1;
      i++;
    }

    if (i < h)
      tabela[i][0] = elem;
    else
      printf("Tabela cheia!!!\n\n");
  }
}

inserir(int tabela[TAM][2], int elem) {
  int h;
  h = hash(elem);

  if (tabela[h][0] != -1)
    colisao(tabela, elem, h);
  else
    tabela[h][0] = elem;
}

impressao(int tabela[TAM][2]) {
  int i;

  for (i = 0; i < TAM; i++)
    if (tabela[i][0] != -1)
      printf("Elemento: %d | Hash: %d | Posicao: %d | Colisao: %d.\n",
             tabela[i][0], hash(tabela[i][0]), i, tabela[i][1]);
}

remocao(int tab[TAM][2], int elem) {
  int h = hash(elem);
  int atual = hash(elem);
  int has;
  int vazio = h;

  while ((h < TAM) && (tab[h] != -1)) {
    if ((tab[h][0] == elem) && (tab[h][1] == 0)) {
      printf("Removido!\n");
      tab[h][0] = -1;
    } else if ((tab[h][0] == elem) && (tab[h][1] > 0)) {
      tab[h][0] = -1;
      vazio = h;
      tab[h][1]--;
      h++;
    } else {
      has = hash(tab[h][0]);
      if ((h >= has) && (vazio < has)) {
        if (tab[h][1] > 0) tab[h][1]--;
        h++;
      } else {
        tab[vazio][0] = tab[h][0];
        tab[h][0] = -1;
        vazio = h;
        tab[h][1]--;
        h++;
      }
    }
  }

  if (h < TAM) {
  } else {
    h = 0;
    while ((h < atual) && (tab[h] != -1)) {
      if ((tab[h] == elem) && (tab[h][1] == 0)) {
        printf("Removido!\n");
        tab[h][0] = -1;
      } else if ((tab[h][0] == elem) && (tab[h][1] > 0)) {
        tab[h][0] = -1;
        vazio = h;
        tab[h][1]--;
        h++;
      } else {
        has = hash(tab[h][0]);
        if ((h >= has) && (vazio < has)) {
          h++;
        } else {
          tab[vazio][0] = tab[h][0];
          tab[h][0] = -1;
          vazio = h;
          tab[h][1]--;
          h++;
        }
      }
    }
  }
}

main() {
  int tab[TAM][2];
  int op, n, i;

  for (i = 0; i < TAM; i++) {
    tab[i][0] = -1;
    tab[i][1] = 0;
  }

INICIO:
  system("cls");

  printf("*******************TABELA HASH*******************\n");
  printf("*************************************************\n");

  printf("(1) Inserir\n");
  printf("(2) Buscar\n");
  printf("(3) Excluir\n");
  printf("(4) Imprimir\n");
  printf("(0) Sair\n");
  printf("\nEntre com uma opcao acima: ");
  scanf("%d", &op);

  switch (op) {
    case 1:
      system("cls");

      printf("*******************Inserir*******************\n\n");
      printf("Valor: ");
      scanf("%d", &n);

      inserir(tab, n);

      system("pause");
      break;

    case 2:
      system("cls");

      printf("*******************Buscar*******************\n\n");

      system("pause");
      break;

    case 3:
      system("cls");

      printf("*******************Excluir*******************\n\n");
      printf("Valor: ");
      scanf("%d", &n);

      remocao(tab, n);
      system("pause");
      break;

    case 4:
      system("cls");

      printf("*******************Imprimir*******************\n\n");

      impressao(tab);

      system("pause");
      break;

    case 0:
      printf("\nVolte sempre!! :)");

      break;

    default:
      printf("Entre com uma opcao valida!!!");

      getchar();
      break;
  }
  if (op)
    goto INICIO;
  else
    getchar();
}
