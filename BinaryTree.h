#pragma once
#include <iostream>

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class BinaryTree {
private:
    std::vector<T> tree;  // Vector to store tree nodes
    int capacity;  // Maximum capacity of the tree
    int size;  // Current number of elements in the tree

    // Function to perform in-order traversal starting from a given index
    void inOrderTraversal(int index) {
        if (index >= capacity || tree[index] == -1) return;
        inOrderTraversal(2 * index + 1); // Left child
        std::cout << tree[index] << " ";
        inOrderTraversal(2 * index + 2); // Right child
    }

    // Function to perform pre-orde traversal startinf from a given index
    void preOrderTraversal(int index) {
        if (index >= capacity || tree[index] == -1) {
            return;
        }
            std::cout << tree[index] << " ";
            preOrderTraversal(2 * index + 1); // Left child
            preOrderTraversal(2 * index + 2); // Right child
    }

    // Function to perform pre-orde traversal startinf from a given index
    void postOrderTraversal(int index) {
        if (index >= capacity || tree[index] == -1) {
            return;
        }
            preOrderTraversal(2 * index + 1); // Left child
            preOrderTraversal(2 * index + 2); // Right child
            std::cout << tree[index] << " ";
    }

public:
    // Constructor to initialize tree with a given capacity
    BinaryTree(int cap) : capacity(cap), size(0) {
        tree.resize(capacity, -1);  // Initialize the tree with -1
    }

    // Function to insert the root of the tree
    void insertRoot(int value) {
        if (tree[0] != -1) {
            std::cerr << "Root already exists!" << std::endl;
            return;
        }
        tree[0] = value;
        size++;
    }

    // Function to insert the left child of a node at a given index
    void insertLeftChild(int parentIndex, T value) {
        int leftChildIndex = 2 * parentIndex + 1;
        if (leftChildIndex >= capacity) {
            std::cerr << "Left child index out of bounds!" << std::endl;
            return;
        }
        if (tree[parentIndex] == -1) {
            std::cerr << "Parent node doesn't exist!" << std::endl;
            return;
        }
        if (tree[leftChildIndex] != -1) {
            std::cerr << "Left child already exists!" << std::endl;
            return;
        }
        tree[leftChildIndex] = value;
        size++;
    }

    // Function to insert the right child of a node at a given index
    void insertRightChild(int parentIndex, int value) {
        int rightChildIndex = 2 * parentIndex + 2;
        if (rightChildIndex >= capacity) {
            std::cerr << "Right child index out of bounds!" << std::endl;
            return;
        }
        if (tree[parentIndex] == -1) {
            std::cerr << "Parent node doesn't exist!" << std::endl;
            return;
        }
        if (tree[rightChildIndex] != -1) {
            std::cerr << "Right child already exists!" << std::endl;
            return;
        }
        tree[rightChildIndex] = value;
        size++;
    }

    // General insert function to insert left or right child
    void insert(int parentIndex, int value, bool isLeftChild) {
        if (isLeftChild) {
            insertLeftChild(parentIndex, value);
        } else {
            insertRightChild(parentIndex, value);
        }
    }

    // Function to get the left child of a node at a given index
    int getLeftChild(int index) {
        int leftIndex = 2 * index + 1;
        if (leftIndex < size && tree[leftIndex] != -1) {
            return tree[leftIndex];
        }
        throw std::out_of_range("No left child");
    }

    // Function to get the right child of a node at a given index
    int getRightChild(int index) {
        int rightIndex = 2 * index + 2;
        if (rightIndex < size && tree[rightIndex] != -1) {
            return tree[rightIndex];
        }
        throw std::out_of_range("No right child");
    }

    // Function to get the parent of a node at a given index
    int getParent(int index) {
        if (index == 0) {
            throw std::out_of_range("Root node has no parent");
        }
        int parentIndex = (index - 1) / 2;
        return tree[parentIndex];
    }

    // Function to display the tree structure
    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << "Node " << i << ": " << tree[i] << std::endl;
            try {
                std::cout << "  Left Child: " << getLeftChild(i) << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "  No Left Child" << std::endl;
            }
            try {
                std::cout << "  Right Child: " << getRightChild(i) << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "  No Right Child" << std::endl;
            }
            try {
                std::cout << "  Parent: " << getParent(i) << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "  No Parent (root node)" << std::endl;
            }
        }
    }

    // Function to display the in-order traversal of the tree
    void displayInOrderTraversal() {
        inOrderTraversal(0);
        std::cout << std::endl;
    }

    void displayPreOrderTraversal() {
        preOrderTraversal(0);
        std::cout << std::endl;
    }

    void displayPostOrderTraversal() {
        postOrderTraversal(0);
        std::cout << std::endl;
    }
};