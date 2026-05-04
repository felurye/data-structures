package com.datastructures.basics;

public class Main {
    public static void main(String[] args) {
        passByValue();
        passByReference();
    }

    // String é imutável: reatribuir 'a' cria novo objeto, 'b' mantém o original
    public static void passByValue() {
        String a = "AAAA";
        String b = a;
        System.out.println("==================================");
        System.out.println("--------- Pass by value ----------");
        System.out.println("a = \"AAAA\", b = a");
        System.out.println("a=" + a + " b=" + b);
        a = "BBBB";
        System.out.println("After a = \"BBBB\":");
        System.out.println("a=" + a + " b=" + b);
        System.out.println("==================================\n");
    }

    // Objeto compartilha referência: mutar via 'a' reflete em 'b'
    public static void passByReference() {
        Wrapper<String> a = new Wrapper<>("AAAA");
        Wrapper<String> b = a;
        System.out.println("==================================");
        System.out.println("------- Pass by reference --------");
        System.out.println("a = \"AAAA\", b = a");
        System.out.println("a=" + a.getValue() + " b=" + b.getValue());
        a.setValue("BBBB");
        System.out.println("After a.setValue(\"BBBB\"):");
        System.out.println("a=" + a.getValue() + " b=" + b.getValue());
        System.out.println("==================================");
    }
}
