package com.datastructures.linkedStack;

public class LinkedStack<T> {
    private Node<T> top;

    public void push(T data) {
        Node<T> newNode = new Node<>(data);
        newNode.setNext(top);
        top = newNode;
    }

    public T pop() {
        if (isEmpty()) return null;
        T data = top.getData();
        top = top.getNext();
        return data;
    }

    public T top() {
        return isEmpty() ? null : top.getData();
    }

    public boolean isEmpty() {
        return top == null;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("------------\n   Stack\n------------\n");
        Node<T> aux = top;
        while (aux != null) {
            sb.append("[").append(aux.getData()).append("]\n");
            aux = aux.getNext();
        }
        sb.append("============");
        return sb.toString();
    }
}
