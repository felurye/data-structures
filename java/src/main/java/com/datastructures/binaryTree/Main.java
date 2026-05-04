package com.datastructures.binaryTree;

import com.datastructures.binaryTree.model.IntValue;

public class Main {
    public static void main(String[] args) {
        BinarySearchTree<IntValue> tree = new BinarySearchTree<>();

        for (int v : new int[]{13, 10, 25, 2, 12, 20, 31, 29, 32}) {
            tree.insert(new IntValue(v));
        }

        System.out.println("Full tree:");
        tree.printInOrder();
        tree.printPreOrder();
        tree.printPostOrder();

        tree.remove(new IntValue(2));
        System.out.println("\n\nAfter removing 2 (leaf):");
        tree.printInOrder();

        tree.remove(new IntValue(31));
        System.out.println("\n\nAfter removing 31 (one child):");
        tree.printInOrder();

        tree.remove(new IntValue(13));
        System.out.println("\n\nAfter removing 13 (root, two children):");
        tree.printInOrder();
        System.out.println();
    }
}
