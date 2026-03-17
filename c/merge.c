#include <stdio.h>

void intercalar(int v[], int aux[], int ini1, int ini2, int fim2) {
  int in1 = ini1, in2 = ini2, fim1 = in2 - 1, au = 0, i;

  while (in1 <= fim1 && in2 <= fim2) {
    if (v[in1] < v[in2]) {
      aux[au++] = v[in1++];
    } else {
      aux[au++] = v[in2++];
    }
  }
  while (in1 <= fim1) {
    aux[au++] = v[in1++];
  }
  while (in2 <= fim2) {
    aux[au++] = v[in2++];
  }

  for (i = 0; i < au; i++) {
    v[i + ini1] = aux[i];
  }
}

void mergeSort(int v[], int aux[], int esq, int dir) {
  int meio;
  if (esq < dir) {
    meio = (esq + dir) / 2;
    mergeSort(v, aux, esq, meio);
    mergeSort(v, aux, meio + 1, dir);
    intercalar(v, aux, esq, meio + 1, dir);
  }
}

int main() {
  int v[10] = {45, 23, 10, 25, 89, 75, 46, 32, 20, 1}, aux[10], i;

  mergeSort(v, aux, 0, 9);

  printf("| ");
  for (i = 0; i < 10; i++) {
    printf("%d | ", v[i]);
  }

  return 0;
}
