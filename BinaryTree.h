#pragma once
#include <iostream>

template<typename T>
struct Node {
    Node* left;
    T data;
    Node* right;

    Node(T data): left(nullptr), right(nullptr), data(data) {}
};


template<typename T>
class BinaryTree {
    Node<T>* head = nullptr;
};
