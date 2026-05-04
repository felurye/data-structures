package com.datastructures.doublyLinkedList;

public class DoublyLinkedList<T> {
    private DoubleNode<T> head;
    private DoubleNode<T> tail;
    private int size;

    public void add(T value) {
        DoubleNode<T> newNode = new DoubleNode<>(value);
        newNode.setPrev(tail);
        if (head == null) {
            head = newNode;
        } else {
            tail.setNext(newNode);
        }
        tail = newNode;
        size++;
    }

    public void add(int index, T value) {
        DoubleNode<T> current = getNode(index);
        DoubleNode<T> newNode = new DoubleNode<>(value);
        newNode.setNext(current);

        if (newNode.getNext() != null) {
            newNode.setPrev(current.getPrev());
            newNode.getNext().setPrev(newNode);
        } else {
            newNode.setPrev(tail);
            tail = newNode;
        }
        if (index == 0) {
            head = newNode;
        } else {
            newNode.getPrev().setNext(newNode);
        }
        size++;
    }

    public void remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index " + index + " out of bounds");
        }
        if (index == 0) {
            head = head.getNext();
            if (head != null) {
                head.setPrev(null);
            } else {
                tail = null;
            }
        } else {
            DoubleNode<T> node = getNode(index);
            node.getPrev().setNext(node.getNext());
            if (node != tail) {
                node.getNext().setPrev(node.getPrev());
            } else {
                tail = node.getPrev();
            }
        }
        size--;
    }

    public T get(int index) {
        return getNode(index).getValue();
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int size() {
        return size;
    }

    private DoubleNode<T> getNode(int index) {
        DoubleNode<T> aux = head;
        for (int i = 0; i < index && aux != null; i++) {
            aux = aux.getNext();
        }
        return aux;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("null<-->");
        DoubleNode<T> aux = head;
        while (aux != null) {
            sb.append("[").append(aux.getValue()).append("]<-->");
            aux = aux.getNext();
        }
        sb.append("null");
        return sb.toString();
    }

    public String toStringReverse() {
        StringBuilder sb = new StringBuilder("null<-->");
        DoubleNode<T> aux = tail;
        while (aux != null) {
            sb.append("[").append(aux.getValue()).append("]<-->");
            aux = aux.getPrev();
        }
        sb.append("null");
        return sb.toString();
    }
}
