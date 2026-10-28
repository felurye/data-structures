## Variáveis e Constantes

### Variáveis

Uma variável é um nome usado para armazenar um dado na memória, e precisa ser declarada com um tipo antes de ser usada - C é uma linguagem de tipagem estática, o tipo é fixado na declaração e não muda depois:

```c
int age = 25;
float salary = 1500.50f;
char grade = 'A';
```

- **Declaração**: informa ao compilador o nome e o tipo da variável (`int age;`).
- **Inicialização**: atribui um valor inicial no momento da declaração (`int age = 25;`).
- Uma variável declarada mas não inicializada contém **lixo de memória** (um valor indefinido, não zero por padrão) até receber um valor.

### Constantes

Constantes são valores que não mudam durante a execução do programa. Podem ser definidas de duas formas:

```c
const float PI = 3.14159f;   // constante tipada, verificada pelo compilador
#define MAX_SIZE 100          // macro de pré-processador, substituição textual
```

| Forma     | Quando usar                                                                    |
| --------- | ------------------------------------------------------------------------------ |
| `const`   | quando o valor tem um tipo específico e você quer que o compilador o verifique |
| `#define` | quando o valor é usado antes mesmo da compilação (ex: tamanho de array fixo)   |

Tentar atribuir um novo valor a uma variável `const` depois de inicializada gera erro de compilação.
