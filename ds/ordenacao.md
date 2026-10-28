## Ordenação

| Algoritmo      | Melhor caso | Caso médio | Pior caso  | Espaço   | Estável | In-place |
| -------------- | ----------- | ---------- | ---------- | -------- | ------- | -------- |
| Bubble Sort    | O(n)        | O(n²)      | O(n²)      | O(1)     | Sim     | Sim      |
| Selection Sort | O(n²)       | O(n²)      | O(n²)      | O(1)     | Não     | Sim      |
| Insertion Sort | O(n)        | O(n²)      | O(n²)      | O(1)     | Sim     | Sim      |
| Merge Sort     | O(n log n)  | O(n log n) | O(n log n) | O(n)     | Sim     | Não      |
| Quick Sort     | O(n log n)  | O(n log n) | O(n²)      | O(log n) | Não     | Sim      |
| Heap Sort      | O(n log n)  | O(n log n) | O(n log n) | O(1)     | Não     | Sim      |
| Counting Sort  | O(n + k)    | O(n + k)   | O(n + k)   | O(n + k) | Sim     | Não      |

**Bubble Sort**: troca repetidamente elementos adjacentes fora de ordem; o maior elemento "borbulha" até o final a cada passagem.

**Selection Sort**: encontra o menor elemento da parte não ordenada e o coloca no início.

**Insertion Sort**: constrói o array ordenado um elemento de cada vez, inserindo o elemento atual na posição correta dentro da parte já ordenada.

**Merge Sort** (dividir para conquistar): divide o array em metades, ordena cada metade recursivamente e depois faz a intercalação (merge) das metades ordenadas.

```java
void mergeSort(int[] a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
```

**Quick Sort**: escolhe um pivô, particiona o array em elementos menores e maiores que o pivô (partição de Lomuto, por exemplo), e ordena recursivamente as duas partes.

```java
void quickSort(int[] a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
```

**Heap Sort**: constrói um max-heap e extrai repetidamente o maior elemento, colocando-o no final do array.

**Counting Sort**: conta a frequência de cada elemento e usa essa contagem para montar o array ordenado - muito eficiente quando o intervalo de valores (`k`) é pequeno.

Quando usar cada um: array quase ordenado -> Insertion Sort; é preciso estabilidade garantida com O(n log n) -> Merge Sort; ordenação in-place com bom desempenho médio -> Quick Sort; O(n log n) garantido e in-place -> Heap Sort; intervalo pequeno de inteiros -> Counting Sort. Não existe um algoritmo melhor para todos os casos - a escolha depende das restrições do problema (tamanho, intervalo, memória, necessidade de estabilidade).

Implementação neste repositório: `c/bubble.c`, `c/merge.c` e `c/quicksort.c`.
