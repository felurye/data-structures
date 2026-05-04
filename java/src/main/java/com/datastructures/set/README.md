# Conjunto (`HashSet` e `TreeSet`)

## Conceito

Um **Set** é uma coleção que **não permite elementos duplicados**. Dois elementos são considerados duplicados se
`a.equals(b)` retornar `true`.

Java oferece duas implementações principais:

### HashSet

Armazena elementos em uma **tabela hash**. Não garante nenhuma ordem de iteração.

| Operação      | Complexidade |
| ------------- | ------------ |
| `add(T)`      | O(1) médio   |
| `contains(T)` | O(1) médio   |
| `remove(T)`   | O(1) médio   |

Requer que a classe implemente `equals()` e `hashCode()` corretamente.

### TreeSet

Armazena elementos em uma **árvore binária balanceada** (Red-Black Tree). Mantém os elementos em **ordem crescente**
definida por `compareTo()`.

| Operação      | Complexidade |
| ------------- | ------------ |
| `add(T)`      | O(log n)     |
| `contains(T)` | O(log n)     |
| `remove(T)`   | O(log n)     |

Requer que a classe implemente `Comparable<T>` (ou que seja passado um `Comparator`).

### Quando usar cada um

| Situação                                            | Use       |
| --------------------------------------------------- | --------- |
| Verificação rápida de existência, ordem não importa | `HashSet` |
| Iteração em ordem crescente                         | `TreeSet` |
| Remover duplicatas de uma lista                     | `HashSet` |

## O que o exemplo faz

```java
Set<Car> hashSet = new HashSet<>();
hashSet.add(new Car("Ford"));
hashSet.add(new Car("Alfa Romeo"));
// ... adiciona mais carros
System.out.println(hashSet); // ordem imprevisível

Set<Car> treeSet = new TreeSet<>();
treeSet.add(new Car("Ford"));
treeSet.add(new Car("Alfa Romeo"));
// ... adiciona mais carros
System.out.println(treeSet); // ordem alfabética: Alfa Romeo, Chevrolet, Fiat...
```

`Car` implementa `Comparable<Car>` com `compareTo()` baseado na marca, o que permite o `TreeSet` ordenar
automaticamente.

## Como praticar

**Exercício 1 - duplicatas**
Tente adicionar `new Car("Ford")` duas vezes no mesmo `HashSet`. Quantos elementos há depois? Por quê?

**Exercício 2 - ordenação customizada**
Modifique o `compareTo()` de `Car` para ordenar pelo tamanho do nome da marca (menor primeiro). Como fica a saída do
`TreeSet`?

**Exercício 3 - Comparator externo**
Em vez de modificar `Car`, crie um `TreeSet` com um `Comparator` anônimo que ordena por tamanho da marca:

```java
Set<Car> set = new TreeSet<>((a, b) -> a.getBrand().length() - b.getBrand().length());
```

**Exercício 4 - remover duplicatas**
Dado um `List<String>` com nomes repetidos, use um `HashSet` para obter apenas os nomes únicos. Como você faria isso em
uma linha?

**Exercício 5 - operações de conjunto**
Com dois `HashSet<String>`, implemente:

- União: todos os elementos de ambos
- Interseção: apenas os elementos em comum
- Diferença: elementos do primeiro que não estão no segundo

_(Dica: `addAll()`, `retainAll()`, `removeAll()`)_
