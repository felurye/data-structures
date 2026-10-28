## Alocação Dinâmica de Memória

### Memória estática vs. dinâmica

Memória **estática** é alocada em tempo de compilação, tem tamanho fixo e é gerenciada automaticamente (variáveis locais na pilha/stack de execução, ou globais/estáticas no segmento de dados do programa). Memória **dinâmica** é alocada em tempo de execução, no heap, pode ser redimensionada e **precisa ser gerenciada manualmente** pelo programador.

### Funções de `stdlib.h`

| Função                   | Propósito                                 | Inicialização                |
| ------------------------ | ----------------------------------------- | ---------------------------- |
| `malloc(size)`           | aloca um bloco de memória do tamanho dado | não (valores de lixo)        |
| `calloc(n, size)`        | aloca memória para `n` elementos          | sim (todos zerados)          |
| `realloc(ptr, novoSize)` | redimensiona um bloco já alocado          | preserva os dados existentes |
| `free(ptr)`              | libera a memória alocada                  | -                            |

```c
int *p = (int*) malloc(5 * sizeof(int));
if (p == NULL) {
    // falha na alocação
}
free(p);
```

### Pontos-chave

- `malloc()` e `calloc()` retornam `void*` - é preciso fazer cast para o tipo correto em C++ (em C puro, o cast é opcional, mas é boa prática documentar o tipo).
- `realloc()` pode mover o bloco para um **novo endereço** na memória - sempre reatribua o resultado (`ptr = realloc(ptr, novoTamanho)`).
- Sempre verifique se o retorno é `NULL` (indicando falha na alocação) antes de usar o ponteiro.
- Sempre libere memória dinamicamente alocada com `free()` quando ela não for mais necessária, para evitar **vazamento de memória** (memory leak).
- Depois de liberar, evite usar o ponteiro de novo (ponteiro solto) - veja `ponteiros.md`.

Implementação neste repositório: `lista.c`, `fila.c`, `arvore-binaria.c` e `arvore-avl.c` usam `malloc` para criar cada novo nó dinamicamente conforme elementos são inseridos.
