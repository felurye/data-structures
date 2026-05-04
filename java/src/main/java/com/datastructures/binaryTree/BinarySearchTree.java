package com.datastructures.binaryTree;

public class BinarySearchTree<T extends Comparable<T>> {
    private BinaryNode<T> root;

    public void insert(T value) {
        root = insert(root, new BinaryNode<>(value));
    }

    private BinaryNode<T> insert(BinaryNode<T> current, BinaryNode<T> newNode) {
        if (current == null) return newNode;
        if (newNode.getValue().compareTo(current.getValue()) < 0) {
            current.setLeft(insert(current.getLeft(), newNode));
        } else {
            current.setRight(insert(current.getRight(), newNode));
        }
        return current;
    }

    public void remove(T value) {
        root = remove(root, value);
    }

    private BinaryNode<T> remove(BinaryNode<T> current, T value) {
        if (current == null) return null;
        int cmp = value.compareTo(current.getValue());
        if (cmp < 0) {
            current.setLeft(remove(current.getLeft(), value));
        } else if (cmp > 0) {
            current.setRight(remove(current.getRight(), value));
        } else {
            if (current.getLeft() == null) return current.getRight();
            if (current.getRight() == null) return current.getLeft();
            BinaryNode<T> successor = minimum(current.getRight());
            current.setValue(successor.getValue());
            current.setRight(remove(current.getRight(), successor.getValue()));
        }
        return current;
    }

    private BinaryNode<T> minimum(BinaryNode<T> node) {
        while (node.getLeft() != null) node = node.getLeft();
        return node;
    }

    public void printInOrder() {
        System.out.println("\nIn-order:");
        printInOrder(root);
    }

    private void printInOrder(BinaryNode<T> current) {
        if (current != null) {
            printInOrder(current.getLeft());
            System.out.print(current.getValue() + " ");
            printInOrder(current.getRight());
        }
    }

    public void printPreOrder() {
        System.out.println("\nPre-order:");
        printPreOrder(root);
    }

    private void printPreOrder(BinaryNode<T> current) {
        if (current != null) {
            System.out.print(current.getValue() + " ");
            printPreOrder(current.getLeft());
            printPreOrder(current.getRight());
        }
    }

    public void printPostOrder() {
        System.out.println("\nPost-order:");
        printPostOrder(root);
    }

    private void printPostOrder(BinaryNode<T> current) {
        if (current != null) {
            printPostOrder(current.getLeft());
            printPostOrder(current.getRight());
            System.out.print(current.getValue() + " ");
        }
    }
}
