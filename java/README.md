# Estruturas de Dados - Java

Implementações de estruturas de dados e exemplos de coleções Java, organizados por pacote.

## Estrutura do projeto

```
src/main/java/com/datastructures/
├── node/              - Conceito básico de nó encadeado
├── basics/            - Passagem por valor vs referência
├── equalsHashCode/    - Contrato equals/hashCode
├── list/              - ArrayList (java.util)
├── set/               - HashSet e TreeSet (java.util)
├── map/               - HashMap (java.util)
├── stack/             - Stack (java.util)
├── queue/             - Queue / LinkedList (java.util)
├── linkedStack/       - Pilha genérica (implementação própria)
├── linkedQueue/       - Fila genérica (implementação própria)
├── linkedList/        - Lista encadeada
├── doublyLinkedList/  - Lista duplamente encadeada
├── circularList/      - Lista circular
└── binaryTree/        - Árvore binária de busca
```

## Estruturas implementadas

### Nó (`node`)

Bloco fundamental de todas as estruturas encadeadas. Um nó genérico `Node<T>` armazena um valor e uma referência para o
próximo nó.

### Pilha encadeada (`linkedStack`)

Estrutura LIFO (Last In, First Out). Implementação própria com nó genérico.

| Operação    | Descrição                   |
| ----------- | --------------------------- |
| `push(T)`   | Insere no topo              |
| `pop()`     | Remove e retorna o topo     |
| `top()`     | Consulta o topo sem remover |
| `isEmpty()` | Verifica se está vazia      |

### Fila encadeada (`linkedQueue`)

Estrutura FIFO (First In, First Out). Implementação própria com nó genérico.

| Operação     | Descrição                       |
| ------------ | ------------------------------- |
| `enqueue(T)` | Insere no final                 |
| `dequeue()`  | Remove e retorna o primeiro     |
| `first()`    | Consulta o primeiro sem remover |
| `isEmpty()`  | Verifica se está vazia          |

### Lista simplesmente encadeada (`linkedList`)

Cada nó aponta apenas para o próximo. Acesso sequencial a partir da cabeça.

| Operação      | Descrição                            |
| ------------- | ------------------------------------ |
| `add(T)`      | Insere no final                      |
| `get(int)`    | Retorna elemento por índice          |
| `remove(int)` | Remove e retorna elemento por índice |
| `size()`      | Retorna o tamanho                    |

### Lista duplamente encadeada (`doublyLinkedList`)

Cada nó aponta para o próximo e para o anterior, permitindo navegação nos dois sentidos.

| Operação            | Descrição                     |
| ------------------- | ----------------------------- |
| `add(T)`            | Insere no final               |
| `add(int, T)`       | Insere em posição específica  |
| `remove(int)`       | Remove por índice             |
| `get(int)`          | Retorna elemento por índice   |
| `toStringReverse()` | Percorre de `tail` até `head` |

### Lista circular (`circularList`)

Lista encadeada em que o último nó aponta de volta para o primeiro, formando um ciclo.

| Operação      | Descrição                   |
| ------------- | --------------------------- |
| `add(T)`      | Insere na lista             |
| `remove(int)` | Remove por índice           |
| `get(int)`    | Retorna elemento por índice |

### Árvore binária de busca (`binaryTree`)

Cada nó tem no máximo dois filhos. Valores menores ficam à esquerda; maiores, à direita.

| Operação           | Descrição                                                    |
| ------------------ | ------------------------------------------------------------ |
| `insert(T)`        | Insere mantendo a propriedade BST                            |
| `remove(T)`        | Remove tratando os três casos (folha, um filho, dois filhos) |
| `printInOrder()`   | Percurso esquerda - raiz - direita (ordem crescente)         |
| `printPreOrder()`  | Percurso raiz - esquerda - direita                           |
| `printPostOrder()` | Percurso esquerda - direita - raiz                           |

## Coleções Java

Os pacotes abaixo demonstram o uso das estruturas da biblioteca padrão.

| Pacote  | Estrutura              | Característica principal                                  |
| ------- | ---------------------- | --------------------------------------------------------- |
| `list`  | `ArrayList`            | Lista dinâmica com acesso por índice                      |
| `set`   | `HashSet` / `TreeSet`  | Conjunto sem duplicatas; TreeSet mantém ordem             |
| `map`   | `HashMap`              | Pares chave-valor com acesso O(1)                         |
| `stack` | `Stack`                | Pilha LIFO da biblioteca padrão                           |
| `queue` | `Queue` / `LinkedList` | Fila FIFO com operações seguras (`offer`, `poll`, `peek`) |

### Conceitos de suporte

- **`basics`** - diferença entre passagem por valor (tipos primitivos e String) e por referência (objetos mutáveis)
- **`equalsHashCode`** - por que sobrescrever `equals` e `hashCode` é necessário para usar objetos em coleções
  corretamente

## Como executar

```bash
cd java
mvn compile
mvn exec:java -Dexec.mainClass="com.datastructures.linkedStack.Main"
```

Substitua o `mainClass` pelo pacote desejado.

## Requisitos

- Java 11+
- Maven 3.6+
