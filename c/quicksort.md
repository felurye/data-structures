## Quicksort

### Conceito

O **quicksort** e um algoritmo de ordenacao baseado em particionamento.

Ele escolhe um pivo e reorganiza o vetor para deixar valores menores de um lado e maiores do outro. Depois aplica a mesma ideia nas duas partes.

### Quicksort no contexto deste repositorio

Em `quicksort.c`, o programa le oito valores, chama:

```c
quicksort(vetor, 0, TAMANHO - 1);
```

e imprime o vetor ordenado.

A versao atual usa o elemento do meio como pivo e trabalha com indices corretos do vetor.

### Ideia do algoritmo

1. Escolhe um pivo.
2. Avanca um indice pela esquerda ate encontrar valor maior ou igual ao pivo.
3. Recua outro indice pela direita ate encontrar valor menor ou igual ao pivo.
4. Troca os elementos quando os indices ainda nao se cruzaram.
5. Ordena recursivamente as duas partes.

### Complexidade

- Caso medio: `O(n log n)`.
- Pior caso: `O(n^2)`.
- Memoria extra: `O(log n)` por causa da pilha de recursao, em media.

### Por que isso e importante para iniciantes

Quicksort ajuda a entender particionamento, recursao e como a escolha do pivo influencia o desempenho.
