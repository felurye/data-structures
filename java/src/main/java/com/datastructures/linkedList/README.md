# Lista Simplesmente Encadeada (`SinglyLinkedList<T>`)

## Conceito

Uma **lista simplesmente encadeada** é uma sequência de nós onde cada nó conhece apenas o próximo. Não há referência de
volta ao anterior.

```
head --> [A|->] --> [B|->] --> [C|->] --> [D|null]
```

Diferente de um `ArrayList`, não existe array subjacente: os nós podem estar espalhados na memória, conectados apenas
pelas referências `next`.

### Complexidade

| Operação      | Complexidade | Motivo                               |
| ------------- | ------------ | ------------------------------------ |
| `add(T)`      | O(n)         | Percorre até o final para inserir    |
| `get(int)`    | O(n)         | Acesso sequencial, sem índice direto |
| `remove(int)` | O(n)         | Precisa chegar ao nó anterior        |
| `size()`      | O(1)         | Campo `size` mantido internamente    |

### Comparação com ArrayList

|                    | ArrayList                  | SinglyLinkedList                         |
| ------------------ | -------------------------- | ---------------------------------------- |
| Acesso por índice  | O(1)                       | O(n)                                     |
| Inserção no final  | O(1) amortizado            | O(n)                                     |
| Inserção no início | O(n) - desloca tudo        | O(1) - basta atualizar `head`            |
| Memória            | Contígua, pode desperdiçar | Fragmentada, usa exatamente o necessário |

A lista encadeada brilha quando inserções no início são frequentes, ou quando o tamanho varia muito e o desperdício de
array seria alto.

### Estrutura interna

`head` aponta para o primeiro nó. `size` evita contar os nós a cada operação (O(1) em vez de O(n)).

## O que o exemplo faz

```java
SinglyLinkedList<String> list = new SinglyLinkedList<>();

list.add("A");
list.add("B");
list.add("C");
list.add("D");
System.out.println(list); // [A]-->[B]-->[C]-->[D]-->null

System.out.println("get(0): " + list.get(0)); // A
System.out.println("get(2): " + list.get(2)); // C
System.out.println("size: " + list.size());   // 4

System.out.println("remove(1): " + list.remove(1)); // B
System.out.println(list); // [A]-->[C]-->[D]-->null

list.add("E");
System.out.println(list); // [A]-->[C]-->[D]-->[E]-->null
```

## Como praticar

**Exercício 1 - inserção no início**
Adicione um método `addFirst(T value)` que insere no início da lista em O(1):

```java
public void addFirst(T value) {
    Node<T> novoNo = new Node<>(value);
    novoNo.setNext(head);
    head = novoNo;
    size++;
}
```

**Exercício 2 - busca por valor**
Adicione `boolean contains(T value)` que percorre a lista e retorna `true` se o valor estiver presente (use
`equals()`).

**Exercício 3 - remoção por valor**
Adicione `boolean remove(T value)` que remove a primeira ocorrência do valor fornecido.

**Exercício 4 - inverter a lista**
Implemente `void inverter()` que inverte a ordem dos nós in-place, sem criar uma nova lista. _(Dica: use três
ponteiros - anterior, atual, próximo.)_

**Exercício 5 - ciclo**
Escreva um método `boolean temCiclo()` que detecta se a lista tem um ciclo (um nó cujo `next` aponta para um nó
anterior). _(Dica: algoritmo de Floyd - dois ponteiros com velocidades diferentes.)_

**Exercício 6 - índice inválido**
Tente chamar `list.get(99)` em uma lista pequena. Que exceção é lançada? Adicione uma verificação para índices
negativos também.
