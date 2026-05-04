package com.datastructures.circularList;

public class CircularList<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public void add(T value) {
        Node<T> newNode = new Node<>(value);
        if (size == 0) {
            head = newNode;
            tail = head;
            head.setNext(tail);
        } else {
            newNode.setNext(tail);
            head.setNext(newNode);
            tail = newNode;
        }
        size++;
    }

    public void remove(int index) {
        if (index >= size) {
            throw new IndexOutOfBoundsException("Index " + index + " out of bounds for size " + size);
        }
        switch (index) {
            case 0:
                tail = tail.getNext();
                head.setNext(tail);
                break;
            case 1:
                tail.setNext(tail.getNext().getNext());
                break;
            default:
                Node<T> aux = tail;
                for (int i = 0; i < index - 1; i++) {
                    aux = aux.getNext();
                }   aux.setNext(aux.getNext().getNext());
                break;
        }
        size--;
    }

    public T get(int index) {
        return getNode(index).getValue();
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    private Node<T> getNode(int index) {
        if (isEmpty()) {
            throw new IndexOutOfBoundsException("List is empty");
        }
        if (index == 0) {
            return tail;
        }
        Node<T> aux = tail;
        for (int i = 0; i < index && aux != null; i++) {
            aux = aux.getNext();
        }
        return aux;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node<T> aux = tail;
        for (int i = 0; i < size; i++) {
            sb.append("[").append(aux.getValue()).append("]--->");
            aux = aux.getNext();
        }
        sb.append(size != 0 ? "(back to start)" : "[]");
        return sb.toString();
    }
}
