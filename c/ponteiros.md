## Ponteiros

### Conceito

Um ponteiro é uma variável que armazena o **endereço de memória** de outra variável, em vez de armazenar o valor diretamente. Usa-se `&` para obter o endereço de uma variável e `*` para acessar (desreferenciar) o valor apontado:

```c
int a = 10;
int *p = &a;       // p guarda o endereço de a
printf("%d", *p);  // 10, o valor apontado por p
printf("%p", (void*) p); // o endereço em si
```

- `int *p` declara `p` como um ponteiro para `int` - o tipo do ponteiro precisa bater com o tipo da variável apontada.
- `*p = 20;` altera o valor de `a` através do ponteiro, já que `p` aponta para o endereço de `a`.

### Ponteiro nulo e ponteiro solto

- **Ponteiro nulo** (`NULL`): não aponta para endereço nenhum válido. Convém inicializar ponteiros com `NULL` quando ainda não têm um endereço válido, e checar `if (p != NULL)` antes de desreferenciar.
- **Ponteiro solto (dangling pointer)**: aponta para uma memória que já foi liberada (com `free()`, por exemplo) ou que saiu de escopo. Usá-lo é comportamento indefinido.

### Regras de ouro

- Sempre inicialize ponteiros antes de usar.
- Evite ponteiros soltos: depois de `free(p)`, considere atribuir `p = NULL`.
- Nunca acesse memória já liberada.
- Use `const` quando o valor apontado não deve ser alterado através daquele ponteiro (`const int *p`).

### Ponteiros e arrays

Como visto em `arrays-em-c.md`, o nome de um array decai para um ponteiro ao primeiro elemento em expressões. Isso é a base de como listas encadeadas são implementadas em C: cada nó guarda um ponteiro para o próximo nó.

```c
struct No {
    int valor;
    struct No *proximo;
};
```

Implementação neste repositório: `lista.c` e `fila.c` usam ponteiros para encadear nós (`struct no_lista *proximo`); `arvore-binaria.c`, `arvore-avl.c` e `arvore-red-black.c` usam ponteiros para ligar os nós da árvore (`esquerda`, `direita`, e no caso da red-black também `pai`).
