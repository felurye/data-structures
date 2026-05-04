package com.datastructures.circularList;

public class Main {
    public static void main(String[] args) {
        CircularList<String> list = new CircularList<>();

        list.add("A");
        System.out.println(list);

        list.remove(0);
        System.out.println("remove(0): " + list);

        list.add("B");
        list.add("C");
        list.add("D");
        System.out.println(list);

        System.out.println("get(0): " + list.get(0));
        System.out.println("get(2): " + list.get(2));
        System.out.println("size: " + list.size());
    }
}
