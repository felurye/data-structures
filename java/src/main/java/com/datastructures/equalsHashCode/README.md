# equals e hashCode

## Conceito

Em Java, todo objeto herda dois métodos de `Object`:

- **`equals(Object o)`** - define o que significa dois objetos serem "iguais"
- **`hashCode()`** - retorna um número inteiro que representa o objeto

Por padrão, `equals()` compara **referências** (como `==`), e `hashCode()` é baseado no endereço de memória. Isso
significa que dois objetos criados separadamente com o mesmo conteúdo seriam considerados diferentes.

### O contrato equals/hashCode

O Java exige que esses dois métodos sejam consistentes:

> **Se `a.equals(b)` é `true`, então `a.hashCode()` deve ser igual a `b.hashCode()`.**

O inverso não precisa ser verdadeiro (dois objetos podem ter o mesmo hash sem ser iguais - isso é chamado de **colisão
**).

### Por que isso importa nas coleções

Estruturas como `ArrayList.contains()`, `HashSet`, `HashMap` e `TreeMap` dependem de `equals()` e `hashCode()` para
funcionar corretamente:

- `ArrayList.contains()` usa `equals()` para comparar elementos
- `HashSet` e `HashMap` usam `hashCode()` para localizar o bucket e `equals()` para confirmar a igualdade

Sem sobrescrever esses métodos, `new Car("Ford").equals(new Car("Ford"))` retorna `false`, pois compara endereços de
memória.

### Diferença entre `==` e `equals()`

```
Car a = new Car("Ford");
Car b = new Car("Ford");

a == b        --> false  (referências diferentes na memória)
a.equals(b)   --> true   (mesmo conteúdo, equals sobrescrito)
```

## Implementação

```java
@Override
public boolean equals(Object o) {
    if (this == o) return true;           // mesma referência
    if (!(o instanceof Car)) return false; // tipo diferente
    return Objects.equals(brand, ((Car) o).brand);
}

@Override
public int hashCode() {
    return Objects.hash(brand); // hash baseado nos campos usados em equals
}
```

`Objects.hash()` e `Objects.equals()` são utilitários que lidam com `null` de forma segura.

## O que o exemplo faz

```java
List<Car> lista = new ArrayList<>();
lista.add(new Car("Ford"));
// ...

lista.contains(new Car("Ford")); // true - equals encontra o objeto
new Car("Ford").hashCode() == new Car("Ford").hashCode(); // true - hashes iguais

Car a = new Car("Ford");
Car b = new Car("Ford");
a == b        // false
a.equals(b)   // true
```

## Como praticar

**Exercício 1 - sem sobrescrever**
Crie uma classe `Produto` com campo `nome` mas **sem** sobrescrever `equals` e `hashCode`. Adicione dois
`Produto("Leite")` em uma `ArrayList` e chame `contains(new Produto("Leite"))`. O resultado é o esperado?

**Exercício 2 - múltiplos campos**
Adicione um campo `int ano` à classe `Car`. Atualize `equals` e `hashCode` para considerar tanto `brand` quanto `ano`.
Dois carros com mesma marca mas anos diferentes devem ser distintos.

**Exercício 3 - HashSet**
Adicione vários `Car("Ford")` em um `HashSet<Car>`. Quantos elementos o set terá? Por quê?

**Exercício 4 - HashMap**
Use `Car` como chave de um `HashMap<Car, String>`. Insira `put(new Car("Ford"), "azul")` e depois tente
`get(new Car("Ford"))`. O valor é recuperado? O que aconteceria sem `hashCode` implementado?
