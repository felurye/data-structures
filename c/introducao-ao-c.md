## Introdução ao C

### Conceito

C é uma linguagem de programação procedural, de propósito geral, criada por Dennis Ritchie em 1972 nos Bell Labs. É portável, rápida e eficiente, e organiza o código em funções em vez de objetos.

- **Procedural**: o programa é uma sequência de instruções organizadas em funções, sem o conceito de objetos/classes (diferente de C++ ou Java).
- **Compilada**: o código-fonte é traduzido para código de máquina antes de ser executado, o que a torna rápida.
- **Portável**: um programa em C padrão pode ser compilado em diferentes sistemas operacionais com poucas (ou nenhuma) alteração.
- **Linguagem de nível médio**: oferece recursos de alto nível (funções, structs) e também acesso de baixo nível (ponteiros, gerenciamento manual de memória), ficando entre o assembly e linguagens totalmente de alto nível.

### Estrutura mínima de um programa

Todo programa em C precisa incluir pelo menos o cabeçalho `stdio.h` para usar entrada e saída básica, e define uma função `main()` como ponto de entrada:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

- `#include <stdio.h>`: inclui a biblioteca padrão de entrada/saída, necessária para usar `printf`.
- `int main()`: função principal, por onde a execução do programa começa. O `int` indica que ela retorna um número inteiro ao sistema operacional.
- `return 0;`: indica que o programa terminou com sucesso.

### C no contexto deste repositório

As demais notas desta pasta (`c/`) partem do princípio de que você já conhece o básico apresentado aqui. Veja `tipos-de-dados.md`, `operadores.md`, `ponteiros.md` e as demais notas de linguagem para aprofundar cada tópico, e os arquivos `.md` pareados com cada `.c` (como `pilha.md`, `fila.md`, `grafo.md`) para ver C aplicado na implementação de estruturas de dados.
