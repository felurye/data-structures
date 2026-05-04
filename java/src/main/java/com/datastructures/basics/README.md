# Básico - Passagem por Valor vs Referência

## Conceito

Em Java, a forma como variáveis são passadas ou copiadas depende do **tipo** do dado.

### Passagem por valor

Tipos primitivos (`int`, `double`, `boolean`, etc.) e `String` se comportam por valor: ao atribuir `b = a`, `b` recebe
uma cópia independente. Alterar `a` depois não afeta `b`.

`String` é imutável - ao fazer `a = "BBBB"`, Java cria um novo objeto na memória e faz `a` apontar para ele. `b`
continua apontando para o objeto original `"AAAA"`.

```
Antes: a --> ["AAAA"]   b --> ["AAAA"]  (mesmo objeto)
Após:  a --> ["BBBB"]   b --> ["AAAA"]  (a aponta para novo objeto)
```

### Passagem por referência

Objetos mutáveis compartilham a **referência** (endereço de memória). Ao fazer `b = a`, ambas as variáveis apontam para
o mesmo objeto. Mutar o objeto via `a` é visível em `b`, pois são a mesma instância.

```
Antes: a --> [Wrapper{"AAAA"}]   b --> [Wrapper{"AAAA"}]  (mesmo objeto)
Após:  a --> [Wrapper{"BBBB"}]   b --> [Wrapper{"BBBB"}]  (mesmo objeto, mutado)
```

## Implementação

`Wrapper<T>` é um wrapper genérico que expõe `setValue()`, permitindo mutar o conteúdo sem trocar a referência. Isso é o
que diferencia o comportamento de `String`.

## O que o exemplo faz

**`passByValue()`**

```java
String a = "AAAA";
String b = a;
a ="BBBB";
// b ainda é "AAAA"
```

**`passByReference()`**

```java
Wrapper<String> a = new Wrapper<>("AAAA");
Wrapper<String> b = a;
a.setValue("BBBB");
// b.getValue() agora é "BBBB"
```

Saída esperada:

```
==================================
------- Passagem por valor -------
a = "AAAA", b = a
a=AAAA b=AAAA
Após a = "BBBB":
a=BBBB b=AAAA
==================================

==================================
---- Passagem por referência -----
a = "AAAA", b = a
a=AAAA b=AAAA
Após a.setValue("BBBB"):
a=BBBB b=BBBB
==================================
```

## Como praticar

**Exercício 1 - tipos primitivos**
Teste com `int` em vez de `String`:

```java
int x = 10;
int y = x;
x = 99;
System.out.println(y); // ainda 10?
```

**Exercício 2 - arrays são referência**
Arrays em Java são objetos - verifique se o comportamento é igual ao de `Wrapper<T>`:

```java
int[] a = {1, 2, 3};
int[] b = a;
a[0] = 99;
System.out.println(b[0]); // 99 ou 1?
```

**Exercício 3 - parâmetros de método**
Escreva dois métodos - um que tenta mudar um `int` recebido por parâmetro e outro que muta um `Wrapper<Integer>`.
Confirme qual mudança persiste após o retorno.

**Exercício 4 - String vs StringBuilder**
Compare o comportamento de `String` (imutável) com `StringBuilder` (mutável) ao passar para um método e chamar operações
de modificação.
