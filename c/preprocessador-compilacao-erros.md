## Pré-processador, Compilação e Erros

### Pré-processador

Diretivas de pré-processador começam com `#` e são processadas **antes** da compilação propriamente dita, por um programa separado (o pré-processador), que faz substituições textuais no código-fonte:

```c
#include <stdio.h>
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
```

- `#include`: inclui o conteúdo de um arquivo de cabeçalho no ponto onde a diretiva aparece.
- `#define`: define uma constante simbólica ou uma macro (função textual, sem checagem de tipo).
- `#ifdef` / `#ifndef` / `#endif`: compilação condicional, usada para evitar inclusão duplicada de cabeçalhos ou compilar código diferente conforme a plataforma.

### Etapas da compilação

O processo de compilação converte o código-fonte em um executável em várias etapas:

```
Código-fonte (.c) -> Pré-processador -> Compilador (assembly) -> Montador (object code) -> Linker -> Executável (.exe)
```

1. **Pré-processador**: expande macros e `#include`, remove comentários.
2. **Compilador**: traduz o código em assembly.
3. **Montador (assembler)**: converte o assembly em código objeto (binário, mas ainda não executável).
4. **Linker**: junta o código objeto com bibliotecas externas (como a biblioteca padrão), gerando o executável final.

### Tipos de erro

- **Erro de sintaxe**: viola a gramática da linguagem (ponto e vírgula faltando, chaves desbalanceadas) - detectado pelo compilador, impede a geração do executável.
- **Erro em tempo de execução**: ocorre durante a execução do programa já compilado (divisão por zero, desreferência de ponteiro nulo).
- **Erro lógico**: o programa roda sem travar, mas produz resultado errado (fórmula ou condição incorreta) - o mais difícil de detectar, já que não gera nenhuma mensagem de erro.

### Dicas de depuração

- Verifique erros de sintaxe primeiro, pelas mensagens do compilador.
- Use nomes de variáveis significativos.
- Imprima valores em pontos-chave do programa (`printf` de depuração).
- Use um depurador (como o GDB) para inspecionar o estado do programa passo a passo.
- Verifique condições de contorno (boundary conditions): início/fim de arrays, listas vazias, valores nulos.
- Teste com entradas normais **e** com entradas extremas (vazias, muito grandes, negativas).
