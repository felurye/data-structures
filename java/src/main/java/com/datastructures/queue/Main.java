package com.datastructures.queue;

import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Queue<Car> queue = new LinkedList<>();

        queue.add(new Car("Ford"));
        queue.add(new Car("Chevrolet"));
        queue.add(new Car("Fiat"));
        queue.offer(new Car("Peugeot")); // igual a add, mas retorna false em vez de lançar exceção
        System.out.println(queue);

        System.out.println("element (não remove): " + queue.element());
        System.out.println("peek (null se vazia): " + queue.peek());

        System.out.println("remove: " + queue.remove());
        System.out.println("poll (null se vazia): " + queue.poll());
        System.out.println(queue);

        System.out.println("isEmpty: " + queue.isEmpty());
    }
}
