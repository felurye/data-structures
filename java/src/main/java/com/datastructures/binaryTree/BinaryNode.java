package com.datastructures.binaryTree;

public class BinaryNode<T extends Comparable<T>> {
    private T value;
    private BinaryNode<T> left;
    private BinaryNode<T> right;

    public BinaryNode(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public BinaryNode<T> getLeft() {
        return left;
    }

    public void setLeft(BinaryNode<T> left) {
        this.left = left;
    }

    public BinaryNode<T> getRight() {
        return right;
    }

    public void setRight(BinaryNode<T> right) {
        this.right = right;
    }

    @Override
    public String toString() {
        return "BinaryNode{" + value + '}';
    }
}
