package com.datastructures.list;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Car> cars = new ArrayList<>();

        cars.add(new Car("Ford"));
        cars.add(new Car("Chevrolet"));
        cars.add(new Car("Fiat"));
        cars.add(new Car("Peugeot"));

        System.out.println("contains Ford: " + cars.contains(new Car("Ford")));
        System.out.println("get(2): " + cars.get(2));
        System.out.println("indexOf Fiat: " + cars.indexOf(new Car("Fiat")));

        System.out.println("remove(2): " + cars.remove(2));
        System.out.println(cars);
    }
}
