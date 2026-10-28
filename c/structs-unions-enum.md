## Structures, Unions e Enumeration

### Structure (struct)

Uma **struct** agrupa itens de dados relacionados, de tipos diferentes, sob um único nome, representando um registro (como uma entidade do mundo real). Cada membro tem memória própria e separada:

```c
struct Student {
    int id;
    char name[20];
    float marks;
};

struct Student s1 = {1, "Ana", 9.5f};
printf("%s", s1.name);
```

### Union

Uma **union** também agrupa membros de tipos diferentes sob um nome, mas todos os membros **compartilham a mesma posição de memória** - apenas um membro pode conter um valor válido por vez, e o tamanho da union é o tamanho do maior membro:

```c
union Data {
    int i;
    float f;
    char ch;
};
```

### Enumeration (enum)

Uma **enum** cria constantes inteiras nomeadas, deixando o código mais legível que usar números "mágicos" soltos. Por padrão o primeiro valor é 0 e os seguintes são incrementados em 1 (mas pode ser customizado):

```c
enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
// MON = 0, TUE = 1, ..., SUN = 6

enum Status { ATIVO = 1, INATIVO = 5, PENDENTE }; // PENDENTE = 6
```

### Comparando struct e union

| Característica      | Structure                                       | Union                                                                 |
| ------------------- | ----------------------------------------------- | --------------------------------------------------------------------- |
| Alocação de memória | memória separada para cada membro               | memória compartilhada entre os membros                                |
| Tamanho             | soma de todos os membros (com padding)          | tamanho do maior membro                                               |
| Valor por vez       | todos os membros podem ter valor ao mesmo tempo | apenas um membro por vez                                              |
| Uso típico          | representar um registro completo                | economizar memória / interpretar os mesmos bytes de formas diferentes |

Implementação neste repositório: `arvore-binaria.c`, `arvore-avl.c` e `arvore-red-black.c` usam `struct` para representar nós de árvore; `lista.c`, `pilha.c` e `fila.c` usam `struct`/`typedef struct` para representar a pilha, a fila e os nós da lista encadeada.
