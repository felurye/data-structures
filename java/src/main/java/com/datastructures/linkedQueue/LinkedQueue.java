package com.datastructures.linkedQueue;

public class LinkedQueue<T> {
    private Node<T> rear;

    public void enqueue(T value) {
        Node<T> newNode = new Node<>(value);
        newNode.setNext(rear);
        rear = newNode;
    }

    public T first() {
        if (isEmpty()) return null;
        Node<T> aux = rear;
        while (aux.getNext() != null) {
            aux = aux.getNext();
        }
        return aux.getValue();
    }

    public T dequeue() {
        if (isEmpty()) return null;
        if (rear.getNext() == null) {
            T value = rear.getValue();
            rear = null;
            return value;
        }
        Node<T> aux = rear;
        while (aux.getNext().getNext() != null) {
            aux = aux.getNext();
        }
        T value = aux.getNext().getValue();
        aux.setNext(null);
        return value;
    }

    public boolean isEmpty() {
        return rear == null;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder sb = new StringBuilder();
        Node<T> aux = rear;
        while (aux != null) {
            sb.append("[").append(aux.getValue()).append("]-->");
            aux = aux.getNext();
        }
        sb.append("null");
        return sb.toString();
    }
}
