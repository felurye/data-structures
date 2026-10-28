## Arrays em C

### Conceito

Um array é uma coleção de elementos do **mesmo tipo**, indexados a partir de 0, armazenados em posições **contíguas** de memória:

```c
int arr[5] = {1, 2, 3, 4, 5};
printf("%d", arr[0]); // 1
printf("%d", arr[4]); // 5
```

- O tamanho de um array comum (estático) em C é **fixo**, definido na declaração e decidido em tempo de compilação.
- O acesso por índice é O(1): o endereço de `arr[i]` é calculado diretamente como `endereço_base + i * tamanho_do_tipo`.
- C **não verifica limites** (bounds checking): acessar `arr[10]` num array de tamanho 5 não gera erro de compilação nem, necessariamente, de execução - é comportamento indefinido e uma fonte comum de bugs.

### Arrays multidimensionais

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
printf("%d", matriz[1][2]); // 6
```

Uma matriz em C é, na memória, um bloco contíguo único (não um array de ponteiros para arrays), organizado em ordem de linha (row-major): os elementos da mesma linha ficam adjacentes na memória.

### Array e ponteiro

O nome de um array, usado numa expressão, "decai" para um ponteiro ao seu primeiro elemento - por isso `arr` e `&arr[0]` apontam para o mesmo endereço, e um array passado como parâmetro de função vira, na prática, um ponteiro (veja `ponteiros.md`).

Implementação neste repositório: `pilha.c` usa um array de tamanho fixo (`char elementos[TAMANHO]`) para implementar a pilha.
