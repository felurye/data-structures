package com.datastructures.linkedQueue;

public class Main {
    public static void main(String[] args) {
        LinkedQueue<String> queue = new LinkedQueue<>();

        queue.enqueue("first");
        queue.enqueue("second");
        queue.enqueue("third");
        queue.enqueue("fourth");
        System.out.println(queue);

        System.out.println("dequeue: " + queue.dequeue());
        System.out.println(queue);

        queue.enqueue("fifth");
        System.out.println(queue);

        System.out.println("first: " + queue.first());
        System.out.println("isEmpty: " + queue.isEmpty());
    }
}
