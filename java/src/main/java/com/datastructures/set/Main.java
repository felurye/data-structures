package com.datastructures.set;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Set<Car> hashSet = new HashSet<>();
        hashSet.add(new Car("Ford"));
        hashSet.add(new Car("Chevrolet"));
        hashSet.add(new Car("Fiat"));
        hashSet.add(new Car("Peugeot"));
        hashSet.add(new Car("Zip"));
        hashSet.add(new Car("Alfa Romeo"));
        System.out.println(hashSet);

        Set<Car> treeSet = new TreeSet<>();
        treeSet.add(new Car("Ford"));
        treeSet.add(new Car("Chevrolet"));
        treeSet.add(new Car("Fiat"));
        treeSet.add(new Car("Peugeot"));
        treeSet.add(new Car("Zip"));
        treeSet.add(new Car("Alfa Romeo"));
        System.out.println(treeSet);
    }
}
