# Lista Circular (`CircularList<T>`)

## Conceito

Uma **lista circular** é uma lista encadeada onde o último nó aponta de volta para o primeiro, formando um ciclo
contínuo - não há `null` ao final da cadeia.

```
     head
       |
[B] --> [C] --> [D]
 ^________________|
      tail
```

Nesta implementação:

- `tail` aponta para o nó mais recentemente inserido
- `head` aponta para o nó mais antigo (o que foi inserido primeiro)
- `head.next` fecha o ciclo apontando de volta para `tail`

### Por que usar lista circular?

- **Round-robin**: distribuir tarefas entre processos de forma cíclica
- **Buffer circular**: quando o buffer enche, novos dados sobrescrevem os mais antigos
- **Jogos multiplayer**: percorrer jogadores em turnos infinitamente
- **Playlists em loop**: navegar músicas ciclicamente

### Diferença em relação à lista simples

Na lista simples, percorrer além do último nó resulta em `null`. Na lista circular, chega-se de volta ao início - o
percurso nunca "termina" naturalmente, então é necessário controlar quantos elementos já foram visitados (usando
`size`).

## O que o exemplo faz

```java
CircularList<String> list = new CircularList<>();

list.add("A");
System.out.println(list);
// [A]-->(back to start)

list.remove(0);
System.out.println("remove(0): " + list);
// []

list.add("B");
list.add("C");
list.add("D");
System.out.println(list);
// [D]-->[C]-->[B]-->(back to start)

System.out.println("get(0): " + list.get(0)); // D (mais recente = índice 0)
System.out.println("get(2): " + list.get(2)); // B (mais antigo = índice 2)
System.out.println("size: " + list.size());   // 3
```

Observe que `get(0)` retorna `tail` (o mais recentemente inserido), não o mais antigo.

## Como praticar

**Exercício 1 - percurso cíclico**
Escreva um método `void percorrerN(int n)` que imprime os `n` primeiros elementos do ciclo (podendo dar mais de uma
volta na lista):

```java
// lista com [A, B, C]: percorrerN(7) imprime A B C A B C A
```

**Exercício 2 - round-robin**
Modele um escalonador simples: 3 processos compartilham o processador em ordem circular. A cada `tick()`, o próximo
processo recebe a CPU. Implemente com uma lista circular.

**Exercício 3 - buffer circular**
Crie um `BufferCircular<T>` com capacidade fixa N. Quando cheio, inserir um novo elemento deve sobrescrever o mais
antigo automaticamente.

**Exercício 4 - Problema de Josephus**
N pessoas estão em círculo e a cada K passos uma é eliminada. Use a lista circular para simular: quem é a última a
sobrar?

**Exercício 5 - indexOf**
Implemente `int indexOf(T value)` que percorre a lista e retorna o índice do primeiro nó com aquele valor (ou -1 se
não encontrado). Cuidado para não entrar em loop infinito.

**Exercício 6 - dois ponteiros**
Refatore para manter dois ponteiros: `head` (mais antigo) e `tail` (mais recente). Com isso, `add()` pode inserir no
final em O(1) e `remove(0)` remove o mais antigo também em O(1).
