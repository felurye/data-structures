# Mapa (`HashMap`)

## Conceito

Um **Map** armazena pares **chave-valor** (`key → value`). Cada chave é única; se você inserir uma chave que já existe,
o valor anterior é sobrescrito.

`HashMap` é a implementação mais usada: usa uma tabela hash para localizar valores em tempo constante pela chave.

### Características

| Operação         | Complexidade |
| ---------------- | ------------ |
| `put(K, V)`      | O(1) médio   |
| `get(K)`         | O(1) médio   |
| `containsKey(K)` | O(1) médio   |
| `remove(K)`      | O(1) médio   |

A chave deve ter `equals()` e `hashCode()` implementados corretamente (as mesmas regras do `HashSet`, já que
`HashSet<K>` é internamente um `HashMap<K, Object>`).

`HashMap` não garante ordem de iteração. Use `LinkedHashMap` para manter ordem de inserção, ou `TreeMap` para ordem das
chaves.

### Quando usar

- Associar um identificador único a um valor (id → objeto, nome → telefone, etc.)
- Contagem de frequência (`Map<String, Integer>`)
- Cache de resultados já calculados (memoização)

## O que o exemplo faz

```java
Map<String, String> aluno1 = new HashMap<>();
aluno1.put("nome", "João");
aluno1.put("idade", "17");
aluno1.put("media", "8.5");
aluno1.put("turma", "3A");

System.out.println(aluno1);               // {nome=João, idade=17, ...}
System.out.println(aluno1.keySet());      // [nome, idade, media, turma]
System.out.println(aluno1.get("nome"));   // João
System.out.println(aluno1.containsKey("media")); // true
```

Depois cria uma lista de mapas para representar uma turma e itera imprimindo nome e média de cada aluno.

## Como praticar

**Exercício 1 - contador de palavras**
Dado um texto, conte quantas vezes cada palavra aparece:

```java
String[] palavras = "o gato e o rato e o gato".split(" ");
Map<String, Integer> contagem = new HashMap<>();
for (String p : palavras) {
    contagem.put(p, contagem.getOrDefault(p, 0) + 1);
}
```

**Exercício 2 - inverter um mapa**
Dado um `Map<String, String>` onde chaves são nomes e valores são telefones, crie um mapa inverso `Map<String, String>`
onde chaves são telefones e valores são nomes.

**Exercício 3 - agrupar por critério**
Dada uma lista de carros, agrupe-os por marca usando `Map<String, List<Car>>`. Carros da mesma marca ficam na mesma
lista.

**Exercício 4 - LinkedHashMap vs TreeMap**
Substitua `HashMap` por `LinkedHashMap` e observe que a ordem de inserção é preservada na iteração. Depois tente
`TreeMap` e observe a ordem alfabética das chaves.

**Exercício 5 - computeIfAbsent**
Explore o método `computeIfAbsent()`, mais idiomático para o exercício 3:

```java
mapa.computeIfAbsent(brand, k -> new ArrayList<>()).add(car);
```
