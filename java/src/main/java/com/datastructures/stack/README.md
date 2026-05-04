# Pilha Java (`Stack`)

## Conceito

`Stack<T>` é a implementação de pilha da biblioteca padrão do Java. Segue o princípio **LIFO** (Last In, First Out): o
último elemento inserido é o primeiro a ser removido.

```
push(A)  push(B)  push(C)
            [C]  <-- topo
            [B]
            [A]
pop() --> C, depois B, depois A
```

`Stack` estende `Vector`, que é uma versão sincronizada de `ArrayList`. Para código novo, a documentação oficial
recomenda usar `Deque` (como `ArrayDeque`) como pilha, pois oferece melhor performance sem sincronização desnecessária.

### Principais operações

| Método      | Descrição                   | Comportamento se vazia       |
| ----------- | --------------------------- | ---------------------------- |
| `push(T)`   | Insere no topo              | -                            |
| `pop()`     | Remove e retorna o topo     | Lança `EmptyStackException`  |
| `peek()`    | Consulta o topo sem remover | Lança `EmptyStackException`  |
| `empty()`   | Verifica se está vazia      | -                            |
| `search(T)` | Posição 1-based do elemento | Retorna -1 se não encontrado |

### Casos de uso reais

- Histórico de navegação (voltar página)
- Desfazer/refazer em editores
- Avaliação de expressões matemáticas
- Pilha de chamadas (call stack) da JVM
- Verificação de parênteses balanceados

## O que o exemplo faz

```java
Stack<Car> stack = new Stack<>();

stack.push(new Car("Ford"));
stack.push(new Car("Chevrolet"));
stack.push(new Car("Fiat"));

System.out.println(stack);       // [Ford, Chevrolet, Fiat]
System.out.println(stack.pop()); // Fiat (remove do topo)
System.out.println(stack);       // [Ford, Chevrolet]

System.out.println(stack.peek()); // Chevrolet (não remove)
System.out.println(stack);        // [Ford, Chevrolet] (inalterado)

System.out.println(stack.empty()); // false
```

## Como praticar

**Exercício 1 - parênteses balanceados**
Implemente um método que verifica se uma string tem parênteses balanceados usando uma `Stack<Character>`:

```java
// "((a+b)*c)" --> true
// "((a+b)"    --> false
// "(a+b))"    --> false
```

**Exercício 2 - inverter uma string**
Use uma `Stack<Character>` para inverter uma string sem usar `StringBuilder.reverse()`.

**Exercício 3 - notação pós-fixa (RPN)**
Avalie expressões em notação polonesa reversa como `"3 4 + 2 *"` (resultado: 14) usando uma pilha de inteiros.

**Exercício 4 - ArrayDeque como pilha**
Reimplemente o exemplo trocando `Stack` por `ArrayDeque`:

```java
Deque<Car> stack = new ArrayDeque<>();
stack.push(new Car("Ford"));  // addFirst
stack.pop();                   // removeFirst
stack.peek();                  // peekFirst
```

**Exercício 5 - histórico de ações**
Modele um sistema simples de "desfazer" com uma pilha de strings representando ações. Cada `desfazer()` remove e imprime
a última ação realizada.
