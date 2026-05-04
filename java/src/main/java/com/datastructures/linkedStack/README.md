# Pilha - Implementação própria (`LinkedStack<T>`)

## Conceito

Esta é uma implementação manual de uma **pilha LIFO** (Last In, First Out) usando nós encadeados - sem depender de
nenhuma classe da biblioteca padrão.

Diferente da `Stack` do Java (que usa array), esta implementação usa uma **lista encadeada de nós**: cada nó aponta para
o nó abaixo dele na pilha.

```
top --> [5|->] --> [4|->] --> [3|->] --> [2|->] --> [1|null]
```

### Como funciona internamente

- `top` é a referência para o nó mais recentemente inserido
- **push**: cria um novo nó, aponta seu `next` para o `top` atual, e atualiza `top` para o novo nó - O(1)
- **pop**: salva o dado do `top`, avança `top` para `top.next`, retorna o dado - O(1)
- **top**: retorna o dado do `top` sem mover nada - O(1)

Não há realocação de memória (ao contrário de array): cada `push` aloca apenas um nó.

### Vantagem sobre array

Uma pilha baseada em lista encadeada nunca fica "cheia" (limitada apenas pela memória disponível). Uma pilha baseada em
array tem capacidade máxima (a menos que use um array dinâmico).

## O que o exemplo faz

```java
LinkedStack<Integer> stack = new LinkedStack<>();

for (int i = 1; i <= 5; i++) {
    stack.push(i);
}
System.out.println(stack);
// ------------
//    Stack
// ------------
// [5]
// [4]
// [3]
// [2]
// [1]
// ============

System.out.println("pop: " + stack.pop());  // 5
System.out.println("top: " + stack.top());  // 4 (não remove)
stack.push(99);
// nova pilha: [99][4][3][2][1]
```

## Como praticar

**Exercício 1 - pilha de strings**
Crie uma `LinkedStack<String>`, empilhe palavras e desempilhe-as para verificar que a ordem é invertida.

**Exercício 2 - verificar palíndromo**
Use a pilha para verificar se uma palavra é palíndromo: empilhe todos os caracteres e compare com o original enquanto
desempilha.

**Exercício 3 - tamanho**
Adicione um campo `size` e um método `size()` à classe `LinkedStack<T>`. Atualize `push()` e `pop()` para manter o
contador.

**Exercício 4 - toString sem StringBuilder**
O `toString()` atual usa `StringBuilder`. Reimplemente-o usando recursão com o próprio encadeamento dos nós.

**Exercício 5 - comparar com Stack do Java**
Execute o mesmo código usando `java.util.Stack<Integer>`. O comportamento de `push`, `pop` e `peek` é idêntico? Quais
diferenças você nota na API?

**Exercício 6 - pilha com mínimo**
Implemente uma pilha que, além das operações normais, oferece `min()` em O(1) - retorna o menor elemento presente na
pilha sem removê-lo. _(Dica: use uma segunda pilha auxiliar.)_
