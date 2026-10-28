## Algoritmos Gulosos (Greedy)

Greedy é um paradigma algorítmico que constrói a solução passo a passo, escolhendo em cada etapa a opção localmente ótima, na esperança de alcançar o ótimo global. A escolha é irrevogável (não há volta atrás).

Um algoritmo greedy funciona corretamente quando o problema tem:

- **Propriedade da escolha gulosa**: uma solução globalmente ótima pode ser alcançada escolhendo a melhor opção em cada passo.
- **Subestrutura ótima**: a solução ótima do problema contém as soluções ótimas de seus subproblemas.

Roteiro geral: ordenar a entrada (se necessário), inicializar o resultado, enquanto houver candidatos, escolher o melhor, adicionar ao resultado e atualizar os candidatos.

Problemas clássicos resolvidos com greedy: seleção de atividades (escolher a atividade com término mais cedo), mochila fracionária (escolher o item com melhor razão valor/peso), codificação de Huffman, troco com moedas mínimas, sequenciamento de tarefas com prazos, algoritmo de Dijkstra (caminho mínimo) e árvore geradora mínima (Kruskal/Prim).

| Aspecto               | Greedy               | Programação Dinâmica          |
| --------------------- | -------------------- | ----------------------------- |
| Abordagem             | melhor escolha local | resolve todos os subproblemas |
| Escolhas              | irrevogáveis         | revisáveis                    |
| Otimalidade           | nem sempre ótimo     | sempre ótimo                  |
| Complexidade de tempo | geralmente menor     | geralmente maior              |

Vantagens: simples de entender e implementar, geralmente mais rápido, funciona bem em problemas reais. Desvantagens: nem sempre dá a solução ótima, a propriedade de escolha gulosa nem sempre é fácil de provar, e não é adequado para problemas sem subestrutura ótima. O erro mais comum é aplicar greedy a um problema sem a propriedade de escolha gulosa, sem checar se a decisão local realmente leva ao ótimo global.
