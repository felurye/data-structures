## Hashing: Set e Map

Uma função de hash mapeia uma chave para um índice (bucket) em um array. Uma colisão ocorre quando chaves diferentes mapeiam para o mesmo bucket; Java trata colisões com encadeamento (chaining - lista ligada ou árvore balanceada no bucket). Em média, inserção, busca e remoção custam O(1); no pior caso (muitas colisões), O(n).

**Set / HashSet**: coleção de elementos únicos, sem duplicatas, sem ordem garantida (a menos que se use `LinkedHashSet`, que preserva a ordem de inserção, ou `TreeSet`, que mantém ordem crescente usando uma árvore red-black).

```java
HashSet<Integer> set = new HashSet<>();
set.add(10);
set.add(10);       // duplicata, ignorado
boolean exists = set.contains(10);
set.remove(10);
```

| Feature           | HashSet    | LinkedHashSet                        | TreeSet         |
| ----------------- | ---------- | ------------------------------------ | --------------- |
| Ordem             | nenhuma    | ordem de inserção                    | ordem crescente |
| Estrutura interna | hash table | hash table + lista duplamente ligada | red-black tree  |
| Complexidade      | O(1) médio | O(1) médio                           | O(log n)        |

**Map / HashMap**: coleção de pares chave-valor; as chaves são únicas, os valores podem se repetir. Também conhecido como dicionário ou array associativo.

```java
HashMap<String, Integer> map = new HashMap<>();
map.put("Alice", 25);
map.put("Alice", 26);          // atualiza o valor
int age = map.get("Alice");    // 26
boolean present = map.containsKey("Bob");
map.getOrDefault("Bob", 0);    // retorna 0 se a chave não existir
```

Aplicações comuns de hashing: contagem de frequência de elementos, cache (armazenamento chave-valor), lista de adjacência de grafos, agrupamento de anagramas e o clássico problema "Two Sum" (para cada elemento, verificar em O(1) se o complemento já foi visto, resolvendo o problema em uma única passagem O(n)).

```java
int[] twoSum(int[] a, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < a.length; i++) {
        int need = target - a[i];
        if (map.containsKey(need)) return new int[]{map.get(need), i};
        map.put(a[i], i);
    }
    return new int[]{};
}
```

Ao usar objetos customizados como chave, é preciso sobrescrever `equals()` e `hashCode()` corretamente, para que objetos logicamente iguais caiam no mesmo bucket.

Implementação neste repositório: `c/hash.c`, `java/src/main/java/com/datastructures/set/`, `java/src/main/java/com/datastructures/map/` e `java/src/main/java/com/datastructures/equalsHashCode/` (demonstra a importância de `equals()`/`hashCode()` consistentes).
