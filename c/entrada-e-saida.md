## Entrada e Saída

### Funções padrão

As funções de entrada e saída (I/O) básicas de C vêm da biblioteca `stdio.h`:

| Função               | Uso                                                                     |
| -------------------- | ----------------------------------------------------------------------- |
| `printf()`           | imprime dados formatados na saída padrão                                |
| `scanf()`            | lê dados formatados da entrada padrão                                   |
| `getchar()`          | lê um único caractere                                                   |
| `putchar()`          | imprime um único caractere                                              |
| `gets()` / `fgets()` | lê uma linha inteira (`fgets` é a versão segura, com limite de tamanho) |
| `puts()`             | imprime uma string seguida de nova linha                                |

```c
int idade;
printf("Digite sua idade: ");
scanf("%d", &idade);
printf("Você tem %d anos\n", idade);
```

### Especificadores de formato comuns

| Especificador | Tipo                                         |
| ------------- | -------------------------------------------- |
| `%d`          | inteiro (`int`)                              |
| `%f`          | ponto flutuante (`float`)                    |
| `%lf`         | ponto flutuante (`double`), usado em `scanf` |
| `%c`          | caractere (`char`)                           |
| `%s`          | string                                       |
| `%p`          | endereço de ponteiro                         |

`scanf` precisa do operador `&` (endereço de memória) para a maioria dos tipos, já que precisa saber onde gravar o valor lido - exceto para strings (`char[]`), onde o nome do array já é um ponteiro para o primeiro caractere.
