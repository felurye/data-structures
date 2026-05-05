## Pilha (Stack)

### Conceito

Uma **pilha** é uma estrutura de dados linear em que o último elemento inserido é o primeiro a ser removido.  
Esse comportamento é conhecido como **LIFO** (_Last In, First Out_ — último a entrar, primeiro a sair).

- **Empilhar (push)**: insere um novo elemento no topo da pilha.
- **Desempilhar (pop)**: remove o elemento que está atualmente no topo.
- **Topo (top/peek)**: consulta o elemento do topo sem removê-lo.
- **Pilha vazia**: não contém elementos (normalmente indicada por `topo == -1`).
- **Pilha cheia**: não é possível inserir mais elementos (atingiu a capacidade máxima).

Exemplos de situações reais que se comportam como pilha:

- Pilha de pratos em um restaurante.
- Histórico de páginas visitadas em um navegador (voltar/avançar).
- Funções sendo chamadas em um programa (call stack).

### Pilha no contexto deste repositório

Neste repositório, a pilha é implementada em `pilha.c` como um vetor fixo de caracteres com um índice `topo` que indica a posição do último elemento inserido.

```c
typedef struct {
  int topo;
  char elementos[TAMANHO];
} Pilha;
```

- `topo == -1` indica que a pilha está vazia.
- Cada chamada de **empilhar** incrementa `topo` e coloca um novo caractere em `elementos[topo]`.
- Cada chamada de **desempilhar** devolve `elementos[topo]` e depois decrementa `topo`.

As funções principais da pilha são:

- `inicializar_pilha(Pilha *pilha)`: inicializa a pilha, definindo `topo = -1`.
- `pilha_esta_vazia(const Pilha *pilha)`: retorna verdadeiro se `topo == -1`.
- `pilha_esta_cheia(const Pilha *pilha)`: retorna verdadeiro se `topo == TAMANHO - 1`.
- `empilhar(Pilha *pilha, char simbolo)`: adiciona um novo caractere no topo (se houver espaço).
- `desempilhar(Pilha *pilha, char *simbolo)`: remove o caractere do topo (se a pilha não estiver vazia).

Todas essas operações trabalham diretamente sobre a estrutura `Pilha` para manter o controle de quais elementos estão armazenados.

### Problema implementado em `pilha.c`

O programa em `pilha.c` usa a estrutura de pilha para **validar se os parênteses de uma expressão matemática estão balanceados**.

#### Enunciado (intuitivo)

Dada uma expressão contendo parênteses, como:

- `((2+3)*(4-1))`
- `(a+b))((c-d)`

queremos saber se:

- **Todo parêntese de abertura `'('` possui um parêntese de fechamento `')'` correspondente**, e
- **A ordem de abertura e fechamento é correta** (não permite fechar sem antes ter aberto).

Se isso acontece para todos os parênteses, dizemos que a expressão tem **parênteses balanceados**.

#### Ideia da solução com pilha

1. Começamos com a pilha vazia.
2. Percorremos a expressão caractere por caractere:
   - Quando encontramos `'('`, **empilhamos** esse caractere.
   - Quando encontramos `')'`, tentamos **desempilhar**:
     - Se a pilha estiver vazia, isso significa que estamos tentando fechar um parêntese que nunca foi aberto → expressão **inválida**.
3. Ao final da leitura:
   - Se a pilha estiver **vazia**, todos os `'('` encontrados tiveram um `')'` correspondente → expressão **válida**.
   - Se ainda houver elementos na pilha, significa que sobrou algum `'('` sem fechamento → expressão **inválida**.

Essa lógica está concentrada na função `validar_parenteses`:

```c
static int validar_parenteses(const char *expressao) {
  Pilha pilha;
  size_t i;

  inicializar_pilha(&pilha);

  for (i = 0; expressao[i] != '\0'; i++) {
    char c = expressao[i];

    if (c == '(') {
      if (!empilhar(&pilha, c)) {
        /* estouro de capacidade */
        return 0;
      }
    } else if (c == ')') {
      char topo;
      if (!desempilhar(&pilha, &topo)) {
        /* fecha sem abrir */
        return 0;
      }
    }
  }

  /* expressão válida se não houver sobras na pilha */
  return pilha_esta_vazia(&pilha);
}
```

Passo a passo:

- **Linha a linha da expressão**:
  - Se for `'('`, empilha.
  - Se for `')'`, tenta desempilhar:
    - Se não conseguir (pilha vazia), já sabemos que é inválida.
- **Ao terminar** o laço, verificamos se a pilha está vazia:
  - Se vazia → todos os `'('` tiveram par correspondente.
  - Se não vazia → há mais `'('` do que `')'`.

Essa abordagem mostra um **uso clássico de pilha** para checar **balanceamento de símbolos** em expressões.

### Fluxo do programa `pilha.c`

1. O programa pede para o usuário digitar uma expressão:
   - Ex.: `Digite a expressao matematica desejada: ((2+3)*(4-1))`
2. A expressão é lida como uma string.
3. A função `validar_parenteses` é chamada para verificar se os parênteses estão corretos.
4. O programa imprime:
   - `"Expressao matematica valida!"` se estiver balanceada.
   - `"Expressao matematica invalida!"` caso contrário.

### Por que isso é importante para iniciantes

Este exemplo é útil para iniciantes porque:

- Mostra uma **aplicação prática** de pilhas.
- Reforça o conceito de **LIFO**.
- Ensina a percorrer strings e a **tomar decisões baseado em cada caractere**.
- Demonstra como uma estrutura de dados pode **simplificar a lógica** de um problema que, inicialmente, parece difícil (verificar se parênteses estão corretos).
