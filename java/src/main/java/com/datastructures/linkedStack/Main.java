package com.datastructures.linkedStack;

public class Main {
    public static void main(String[] args) {
        LinkedStack<Integer> stack = new LinkedStack<>();

        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }
        System.out.println(stack);

        System.out.println("pop: " + stack.pop());
        System.out.println("top: " + stack.top());
        System.out.println(stack);

        stack.push(99);
        System.out.println(stack);
        System.out.println("isEmpty: " + stack.isEmpty());
    }
}
