package com.datastructures.node;

public class Main {
    public static void main(String[] args) {
        Node<String> node1 = new Node<>("First");
        Node<String> node2 = new Node<>("Second");
        Node<String> node3 = new Node<>("Third");

        node1.setNext(node2);
        node2.setNext(node3);

        System.out.println(node1);
        System.out.println(node1.getNext());
        System.out.println(node1.getNext().getNext());
    }
}
