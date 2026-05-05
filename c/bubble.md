## Bubble sort

### Conceito

O **bubble sort** e um algoritmo simples de ordenacao que compara pares vizinhos e troca quando estao fora de ordem.

Ao final de cada passada, o maior elemento ainda nao ordenado "sobe" para sua posicao final.

### Bubble sort no contexto deste repositorio

Em `bubble.c`, o programa le oito numeros, ordena o vetor e imprime o resultado.

A funcao principal do algoritmo e:

```c
static void bubble_sort(int vetor[], int tamanho)
```

A versao atual usa uma melhoria importante: se uma passada inteira nao fizer nenhuma troca, o algoritmo para mais cedo.

### Ideia do algoritmo

1. Percorre o vetor comparando `vetor[i]` com `vetor[i + 1]`.
2. Troca os dois quando o elemento da esquerda e maior.
3. Repete o processo reduzindo o limite final.
4. Para antes do tempo se nenhuma troca ocorrer.

### Complexidade

- Melhor caso: `O(n)`, quando o vetor ja esta ordenado.
- Caso medio e pior caso: `O(n^2)`.
- Memoria extra: `O(1)`.

### Por que isso e importante para iniciantes

Bubble sort e facil de visualizar e ajuda a entender comparacoes, trocas e custo de algoritmos de ordenacao.
