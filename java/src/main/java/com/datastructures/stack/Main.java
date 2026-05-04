package com.datastructures.stack;

import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<Car> stack = new Stack<>();

        stack.push(new Car("Ford"));
        stack.push(new Car("Chevrolet"));
        stack.push(new Car("Fiat"));

        System.out.println(stack);
        System.out.println("pop: " + stack.pop());
        System.out.println(stack);

        System.out.println("peek: " + stack.peek());
        System.out.println(stack);

        System.out.println("empty: " + stack.empty());
    }
}
