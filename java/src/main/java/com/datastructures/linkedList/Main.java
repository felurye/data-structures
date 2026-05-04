package com.datastructures.linkedList;

public class Main {
    public static void main(String[] args) {
        SinglyLinkedList<String> list = new SinglyLinkedList<>();

        list.add("A");
        list.add("B");
        list.add("C");
        list.add("D");
        System.out.println(list);

        System.out.println("get(0): " + list.get(0));
        System.out.println("get(2): " + list.get(2));
        System.out.println("size: " + list.size());

        System.out.println("remove(1): " + list.remove(1));
        System.out.println(list);

        list.add("E");
        System.out.println(list);
    }
}
