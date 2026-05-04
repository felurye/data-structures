package com.datastructures.equalsHashCode;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Car> list = new ArrayList<>();
        list.add(new Car("Ford"));
        list.add(new Car("Chevrolet"));
        list.add(new Car("Volkswagen"));

        // contains usa equals() para comparar - retorna true porque equals está implementado
        System.out.println("contains Ford: " + list.contains(new Car("Ford")));

        // hashCode consistente: dois objetos iguais devem ter o mesmo hash
        System.out.println("hashCode Ford (1): " + new Car("Ford").hashCode());
        System.out.println("hashCode Ford (2): " + new Car("Ford").hashCode());

        // dois objetos com mesmo conteúdo são iguais por equals, mas não por ==
        Car a = new Car("Ford");
        Car b = new Car("Ford");
        System.out.println("a == b: " + (a == b));
        System.out.println("a.equals(b): " + a.equals(b));
    }
}
