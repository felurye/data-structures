package com.datastructures.linkedList;

public class SinglyLinkedList<T> {
    private Node<T> head;
    private int size;

    public void add(T value) {
        Node<T> newNode = new Node<>(value);
        if (head == null) {
            head = newNode;
        } else {
            Node<T> aux = head;
            while (aux.getNext() != null) {
                aux = aux.getNext();
            }
            aux.setNext(newNode);
        }
        size++;
    }

    public T get(int index) {
        return getNode(index).getValue();
    }

    public T remove(int index) {
        validateIndex(index);
        Node<T> removed = getNode(index);
        if (index == 0) {
            head = removed.getNext();
        } else {
            Node<T> prev = getNode(index - 1);
            prev.setNext(removed.getNext());
        }
        size--;
        return removed.getValue();
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return head == null;
    }

    private Node<T> getNode(int index) {
        validateIndex(index);
        Node<T> aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux.getNext();
        }
        return aux;
    }

    private void validateIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index " + index + " out of bounds for size " + size);
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node<T> aux = head;
        while (aux != null) {
            sb.append("[").append(aux.getValue()).append("]-->");
            aux = aux.getNext();
        }
        sb.append("null");
        return sb.toString();
    }
}
