package com.datastructures.doublyLinkedList;

public class Main {
    public static void main(String[] args) {
        DoublyLinkedList<String> list = new DoublyLinkedList<>();

        list.add("A");
        list.add("B");
        list.add("C");
        list.add("D");
        list.add("E");
        System.out.println("forward:  " + list);
        System.out.println("reverse:  " + list.toStringReverse());

        list.remove(2);
        System.out.println("remove(2): " + list);

        list.add(2, "X");
        System.out.println("add(2, X): " + list);

        System.out.println("get(2): " + list.get(2));
        System.out.println("size: " + list.size());
        System.out.println("isEmpty: " + list.isEmpty());
    }
}
