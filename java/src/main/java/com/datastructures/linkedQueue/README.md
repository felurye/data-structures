# Fila - Implementação própria (`LinkedQueue<T>`)

## Conceito

Esta é uma implementação manual de uma **fila FIFO** (First In, First Out) usando nós encadeados.

Diferente da `Queue` do Java, esta implementação gerencia a estrutura interna manualmente - sem herdar de `LinkedList`
nem de qualquer outra classe.

### Estrutura interna

A fila mantém uma única referência: `rear`, que aponta para o nó mais recentemente inserido. O elemento mais antigo (
o próximo a sair) fica no **fim** da cadeia.

```
rear --> [fourth|->] --> [third|->] --> [second|->] --> [first|null]
```

- **enqueue**: prepende o novo nó na frente da cadeia - O(1)
- **dequeue**: percorre até o penúltimo nó e desconecta o último - O(n)
- **first**: percorre até o fim da cadeia e retorna o valor - O(n)

### Tradeoff de design

Nesta implementação, `enqueue` é O(1) mas `dequeue` é O(n). Uma implementação com dois ponteiros (`head` e `tail`)
tornaria ambos O(1) - isso seria um bom exercício de extensão.

## O que o exemplo faz

```java
LinkedQueue<String> queue = new LinkedQueue<>();

queue.enqueue("first");
queue.enqueue("second");
queue.enqueue("third");
queue.enqueue("fourth");
System.out.println(queue);
// [fourth]-->[third]-->[second]-->[first]-->null

System.out.println("dequeue: " + queue.dequeue()); // first
System.out.println(queue);
// [fourth]-->[third]-->[second]-->null

queue.enqueue("fifth");
System.out.println("first: " + queue.first());     // second
System.out.println("isEmpty: " + queue.isEmpty()); // false
```

Note que `toString()` exibe do mais recente ao mais antigo (ordem de inserção invertida), mas `dequeue()` e `first()`
sempre retornam o elemento mais antigo.

## Como praticar

**Exercício 1 - fila vazia**
Chame `dequeue()` em uma `LinkedQueue` vazia. O que acontece? Adicione um tratamento adequado se necessário.

**Exercício 2 - tamanho**
Adicione um campo `size` e um método `size()`. Atualize `enqueue()` e `dequeue()` para manter o contador.

**Exercício 3 - dois ponteiros**
Refatore a implementação para usar `head` (aponta para o nó mais antigo) e `tail` (aponta para o nó mais recente).
Com isso, `dequeue()` passa a ser O(1) também:

- `enqueue`: adiciona em `tail`
- `dequeue`: remove de `head`

**Exercício 4 - fila de inteiros**
Crie uma `LinkedQueue<Integer>`, enfileire os números 1 a 5, desenfileire-os um a um e confirme que saem em ordem FIFO.

**Exercício 5 - comparar com Queue do Java**
Execute o mesmo fluxo usando `java.util.Queue<String>` com `LinkedList`. As operações são equivalentes? Qual é mais
legível?

**Exercício 6 - fila com prioridade**
Estenda a fila para que elementos inseridos com prioridade alta fiquem na frente dos demais. Isso exige que `enqueue()`
encontre a posição correta na cadeia.
