# Lista (`ArrayList`)

## Conceito

`ArrayList` é a implementação de `List` mais usada em Java. Internamente, usa um **array redimensionável**: quando o
array interno fica cheio, ele é copiado para um novo com o dobro da capacidade.

### Características

| Operação            | Complexidade                   |
| ------------------- | ------------------------------ |
| `add(T)` (no final) | O(1) amortizado                |
| `get(int)`          | O(1)                           |
| `remove(int)`       | O(n) - desloca elementos       |
| `contains(T)`       | O(n) - percorre com `equals()` |
| `indexOf(T)`        | O(n)                           |

### Quando usar

- Você precisa de acesso rápido por índice
- Insere e remove principalmente no final
- A ordem de inserção importa
- Pode haver elementos duplicados

### Interface `List`

É boa prática declarar a variável como `List<T>`, não `ArrayList<T>`. Isso facilita trocar a implementação depois:

```java
List<Car> lista = new ArrayList<>(); // bom
ArrayList<Car> lista = new ArrayList<>(); // amarra à implementação
```

## O que o exemplo faz

```java
List<Car> lista = new ArrayList<>();
lista.add(new Car("Ford"));
lista.add(new Car("Chevrolet"));
lista.add(new Car("Fiat"));
lista.add(new Car("Peugeot"));

lista.contains(new Car("Ford"));    // true - usa equals()
lista.get(2);                       // Car{brand='Fiat'}
lista.indexOf(new Car("Fiat"));     // 2
lista.remove(2);                    // remove Fiat, retorna Car{brand='Fiat'}
System.out.println(lista);          // [Ford, Chevrolet, Peugeot]
```

## Como praticar

**Exercício 1 - ordenação**
Adicione vários carros e ordene a lista alfabeticamente por marca usando `Collections.sort()`. Para isso, `Car`
precisa implementar `Comparable<Car>`.

**Exercício 2 - filtro**
Crie uma lista com marcas diversas e filtre apenas as que têm mais de 4 letras:

```java
List<Car> filtrados = new ArrayList<>();
for (Car c : lista) {
    if (c.getBrand().length() > 4) filtrados.add(c);
}
```

**Exercício 3 - remoção por valor**
Use `lista.remove(new Car("Ford"))` (não por índice). O que precisa estar implementado para isso funcionar?

**Exercício 4 - subLista**
Explore `lista.subList(1, 3)`. A sublista é uma visão do original ou uma cópia? Mude um elemento na sublista e veja o
efeito na lista original.

**Exercício 5 - LinkedList**
Troque `ArrayList` por `LinkedList` (mantendo `List<Car>` na declaração). O código compila sem mudanças? Quando
`LinkedList` seria preferível?
