# Nó (`Node<T>`)

## Conceito

Um **nó** é o bloco fundamental de todas as estruturas de dados encadeadas. Ele é composto por dois campos:

- **valor** - o dado armazenado (pode ser qualquer tipo via generics)
- **proximo** - referência para o próximo nó da cadeia (ou `null` se for o último)

```
[value | next] --> [value | next] --> [value | null]
```

Sozinho, o nó não é uma estrutura de dados - ele é a peça que estruturas como listas, pilhas e filas usam internamente
para encadear elementos na memória sem precisar de um array contíguo.

## Implementação

```java
public class Node<T> {
    private T value;
    private Node<T> next;
}
```

O uso de generics `<T>` permite que o mesmo nó armazene qualquer tipo: `Node<String>`, `Node<Integer>`, `Node<Car>`,
etc.

## O que o exemplo faz

```java
Node<String> node1 = new Node<>("Primeiro");
Node<String> node2 = new Node<>("Segundo");
Node<String> node3 = new Node<>("Terceiro");

node1.setNext(node2);
node2.setNext(node3);

System.out.println(node1);
```

Cria uma cadeia de três nós e imprime a partir do primeiro. O `toString()` de `Node` é recursivo: ao imprimir `node1`,
ele
também imprime `node1.next` (que imprime `node2.next`, e assim por diante).

Saída esperada:

```
Node{value=Primeiro, next=Node{value=Segundo, next=Node{value=Terceiro, next=null}}}
```

## Como praticar

**Exercício 1 - percurso manual**
Dado o `node1`, percorra a cadeia com um loop e imprima cada valor separadamente:

```java
Node<String> atual = node1;
while (atual != null) {
    System.out.println(atual.getValue());
    atual = atual.getNext();
}
```

**Exercício 2 - contar nós**
Escreva um método `int contar(Node<?> node)` que recebe o primeiro nó e retorna quantos nós há na cadeia.

**Exercício 3 - busca**
Escreva um método `boolean contem(Node<String> node, String value)` que percorre a cadeia e retorna `true` se algum nó
tiver
aquele valor.

**Exercício 4 - inverter**
Escreva um método que inverte a ordem de uma cadeia de nós (o último passa a ser o primeiro).
