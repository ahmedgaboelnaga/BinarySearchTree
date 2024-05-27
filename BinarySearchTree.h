#pragma once
#include <iostream>
#include <queue>
#include <stack>

// Any recursion will require you to have a root pointer argument in the function

// insertion
// search
// Traversal
// Minimum & maximum
// Height
// deletion


// The node of the binary search tree
template<typename T>
struct Node {
    Node<T>* parent;
    T key;
    Node<T>* left;
    Node<T>* right;

    Node(): parent(nullptr), key(0), left(nullptr), right(nullptr) {}
    explicit Node(T key): parent(nullptr), key(key), left(nullptr), right(nullptr) {}
    explicit Node(T key, Node<T>* parent): parent(parent), key(key), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
private:
    Node<T>* root;

    // Helper method for the destructor
    void delete_subtree(Node<T>* node) {
        if (node != nullptr) {
            delete_subtree(node->left);
            delete_subtree(node->right);
            delete node;
        }
    }


    // Recursive insertion
    Node<T>* recursive_insert(Node<T>* x,Node<T>* parent, T key) {
        if (x == nullptr) {
            x = new Node<T>(key, parent);
        } else if (key < x->key) {
            x->left = recursive_insert(x->left,x , key);
        } else {
            x->right = recursive_insert(x->right, x, key);
        }
        return x;
    }


    // Recursive-Search
    Node<T>* recursive_search(Node<T>* x, T key) {
        if (x == nullptr || x->key == key) {
            return x;
        }
        if (key < x->key) {
            return recursive_search(x->left, key);
        } else {
            return recursive_search(x->right, key);
        }
    }
    // Iterative-Search
    Node<T>* iterative_search(T key) {
        Node<T>* x = root;
        while (x != nullptr && x->key != key) {
            if (key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return x;
    }


    // Helper function for the in-order-traversal
    void in_order_traversal(Node<T>* x) {
        if (x == nullptr) {
            return;
        }
        in_order_traversal(x->left);
        std::cout << x->key << " ";
        in_order_traversal(x->right);
    }
    // Helper for descending order
    void in_reverse_order_traversal(Node<T>* x) {
        if (x == nullptr) {
            return;
        }
        in_reverse_order_traversal(x->right);
        std::cout << x->key << " ";
        in_reverse_order_traversal(x->left);
    }
    // Helper for the pre-order_traversal
    void pre_order_traversal(Node<T>* x) {
        if (x == nullptr) {
            return;
        }
        std::cout << x->key << " ";
        pre_order_traversal(x->left);
        pre_order_traversal(x->right);
    }
    // Helper for the post-order-traversal
    void post_order_traversal(Node<T>* x) {
        if (x == nullptr) {
            return;
        }
        post_order_traversal(x->left);
        post_order_traversal(x->right);
        std::cout << x->key << " ";
    }
    // Helper for level-order-traversal
    void breadth_first(Node<T>* x) {
        if (x == nullptr) {
            std::cout << "The tree is empty!";
            return;
        }
        std::queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* curr = q.front();
            q.pop();
            std::cout << curr->key << " ";

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

    }

    // pre-order traversal
    void depth_first (Node<T>* x) {
        if (x == nullptr) {
            std::cout << "The tree is emtpy!";
            return;
        }
        std::stack<Node<T>*> s;
        s.push(root);

        while(!s.empty()) {
            Node<T>* curr = s.top();
            s.pop();
            std::cout << curr->key << " ";

            if (curr-> right != nullptr) {
                s.push(curr->right);
            }
            if (curr->left != nullptr) {
                s.push(curr->left);
            }
        }
    }

    // Iterative minimum
    Node<T>* minimum(Node<T>* x) {
        if (x == nullptr) {
            return x;
        }

        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    // Recursive minimum
    Node<T>* r_minimum(Node<T>* x) {
        if (x == nullptr) {
            return x;
        }
        if (x->left == nullptr) {
            return x;
        }

        return r_minimum(x->left);
    }

    // Iterative maximum
    Node<T>* maximum(Node<T>* x) {
        if (x == nullptr) {
            return x;
        }

        while (x->right != nullptr) {
            x = x->right;
        }
        return x;
    }

    // Recursive maximum
    Node<T>* r_maximum(Node<T>* x) {
        if (x == nullptr) {
            return x;
        }
        if (x->right == nullptr) {
            return x;
        }

        return r_maximum(x->right);
    }

    // Helper function to find the maximum for the height function
    int max (int x, int y) {
        if (x > y) {
            return x;
        } else {
            return y;
        }
    }

    // Height of a node
    int height(Node<T>* x) {
        if (x == nullptr) {
            return -1;
        }

        return max(height(x->left), height(x->right)) + 1;
    }

    // Depth of a node iteratively & recursively
    int depth(T target) {
        Node<T>* temp = root;
        int depth = 0;
        while (temp != nullptr && temp->key != target) {
            if (target < temp->key) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
            depth++;
        }

        if (temp == nullptr) {
            return -1;
        }
        return depth;
    }

    int r_depth(Node<T>* curr, T target) {
        if (curr == nullptr) {
            return -1;
        }
        if (curr->key == target) {
            return 0;
        }

        return 1 + max(r_depth(curr->left, target), r_depth(curr->right, target));
    }

    // Check if it is a binary search tree
    // to achieve this we are going to create a function to check if a subtree is lesser
    // and a function to check if a subtree is greater
    // and add them to the call of is a binary search tree
    bool is_subtree_lesser(Node<T>* root, T value) {
        if (root == nullptr) {
            return true;
        }
        if (root->key < value
        && is_subtree_lesser(root->left, value)
        && is_subtree_lesser(root->right, value)) {
            return true;
        }
        return false;
    }

    bool is_subtree_larger(Node<T>* root, T value) {
        if (root == nullptr) {
            return true;
        }
        if (root->key >= value
        && is_subtree_larger(root->left, value)
        && is_subtree_larger(root->right, value)) {
            return true;
        }
        return false;
    }

    bool is_binary_search_tree(Node<T>* root) {
        if (root == nullptr) {
            return true;
        }

        if (is_subtree_lesser(root->left, root->key)
        && is_binary_search_tree(root->left)
        && is_subtree_larger(root->right, root->key)
        && is_binary_search_tree(root->right)) {
            return true;
        }
        return false;
    }

    // another approach with max and min
    bool is_binary_search_tree_better(Node<T>* root) {
        if (root == nullptr) {
            return  true;
        }

        if (root->right != nullptr) {
            Node<T>* right_min = minimum(root->right);
            if (root->key > right_min->key) {
                return false;
            }
        }

        if (root->left != nullptr) {
            Node<T>* left_max = maximum(root->left);
            if (root->key <= left_max->key) {
                return false;
            }
        }
        return is_binary_search_tree_better(root->left) && is_binary_search_tree_better(root->right);
    }

    // delete
    Node<T>* delete_node(Node<T>* root, T target) {
        if (root == nullptr) {
            return root;
        }

        if (target < root->key) {
            root->left = delete_node(root->left, target);
        } else if (target > root->key) {
            root->right = delete_node(root->right, target);
        } else {
            // if it hsa one or no children
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                if (temp != nullptr) {
                    temp->parent = root->parent;
                }
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                Node<T>* temp = root->left;
                if (temp != nullptr) {
                    temp->parent = root->parent;
                }
                delete root;
                return temp;
            }

            // If it has two children
            Node<T>* temp = minimum(root->right);

            root->key = temp->key;

            root->right = delete_node(root->right, temp->key);
        }
        return root;
    }

    // in-order successor
    Node<T>* in_order_successor(Node<T>* root, T key) {
        if (root == nullptr) return root;

        Node<T>* curr = iterative_search(key);
        if (curr == nullptr) return nullptr;

        if(curr->right != nullptr) {
            return minimum(curr->right);
        }
        Node<T>* ancestor = root;
        Node<T>* successor = nullptr;;
        while (ancestor != curr) {
            if (curr->key < ancestor->key) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }

    // in-order predecessor
    Node<T>* in_order_predecessor(Node<T>* root, T key) {
        if (root == nullptr) return root;

        Node<T>* curr = iterative_search(key);

        if (curr->left != nullptr) {
            return maximum(curr->left);
        }

        Node<T>* ancestor = root;
        Node<T>* predecessor = nullptr;
        while (ancestor != curr) {
            if (curr->key < ancestor->key) {
                ancestor = ancestor->left;
            } else {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
        }
        return predecessor;
    }

public:
    // constructor
    BinarySearchTree(): root(nullptr){}

    // Destructor with a helper function
    ~BinarySearchTree() {
        delete_subtree(root);
    }


    // Insertion
    void r_insert(T key) {
        root = recursive_insert(root, nullptr, key);
    }

    void insert(T key) {
        auto new_node = new Node<T>(key);
        Node<T>* y = nullptr;
        Node<T>* x = root;

        while (x != nullptr) {
            y = x;
            if (new_node->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        new_node->parent = y;

        if (y == nullptr) {
            root = new_node; // The tree was empty
        } else if (new_node->key < y->key) {
            y->left = new_node;
        } else {
            y->right = new_node;
        }
    }
// to test insertion if we don't track the parent
//    void insert(T key) {
//        Node<T>* new_node = new Node<T>(key);
//        Node<T>* x = root;
//
//        if (x == nullptr) {
//            root = new_node;
//            return;
//        }
//
//        while (x != nullptr) {
//            if (new_node->key < x->key) {
//                if (x->left == nullptr) {
//                    x->left = new_node;
//                    break;
//                } else {
//                    x = x->left;
//                }
//            } else {
//                if (x->right == nullptr) {
//                    x->right = new_node;
//                    break;
//                } else {
//                    x = x->right;
//                }
//            }
//        }
//    }


    // user search
    void search(T key) {
        auto found = recursive_search(root, key);
        if (found == nullptr) {
            std::cout << "Element not found!" << std::endl;
        } else {
            std::cout << "The element is : " << found->key << std::endl;
        }
    }

    void i_search(T key) {
        auto found = iterative_search(key);
        if (found == nullptr) {
            std::cout << "Element not found!" << std::endl;
        } else {
            std::cout << "The element is : " << found->key << std::endl;
        }
    }


    // display elements in a sorted manner
    void display_in_order() {
        std::cout << "In-order traversal: ";
        in_order_traversal(root);
        std::cout << std::endl;
    }

    // display elements in reversed order
    void display_in_reversed_order() {
        std::cout << "In-reverse-order traversal: ";
        in_reverse_order_traversal(root);
        std::cout << std::endl;
    }

    // pre-order traversal ( for depth first approach)
    void display_pre_order() {
        std::cout << "Pre-order traversal (depth first): ";
        pre_order_traversal(root);
        std::cout << std::endl;
    }

    // post-order traversal
    void display_post_order() {
        std::cout << "Post-order traversal: ";
        post_order_traversal(root);
        std::cout << std::endl;
    }

    // level-order traversal  (for breadth first approach)
    void breadth_first() {
        std::cout << "Breadth first: ";
        breadth_first(root);
        std::cout << std::endl;
    }

    // pre-order traversal (for depth first approach)
    void depth_first() {
        std::cout << "Depth first: ";
        depth_first(root);
        std::cout << std::endl;
    }


    // Minimum & Maximum
    void find_minimum() {
        auto min = minimum(root);
        if (min == nullptr) {
            std::cout << "The tree is empty!" << std::endl;
        } else {
            std::cout << "The min element is: " << min->key << std::endl;
        }
    }

    void find_maximum() {
        auto max = maximum(root);
        if (max == nullptr) {
            std::cout << "The tree is empty!" << std::endl;
        } else {
            std::cout << "The max element is: " << max->key << std::endl;
        }
    }

    void find_r_maximum() {
        auto max = r_maximum(root);
        if (max == nullptr) {
            std::cout << "The tree is empty!" << std::endl;
        } else {
            std::cout << "The max element is: " << max->key << std::endl;
        }
    }

    void find_r_minimum() {
        auto max = r_minimum(root);
        if (max == nullptr) {
            std::cout << "The tree is empty!" << std::endl;
        } else {
            std::cout << "The max element is: " << max->key << std::endl;
        }
    }

    // Height
    void get_height() {
        int h = height(root);
        std::cout << "The height of the tree is: " << h << std::endl;
    }

    // Depth of a node
    void get_depth(T target) {
        int d = depth(target);
        std::cout << "The depth of the node " << target << " is: " << d << std::endl;
    }

    void get_r_depth(T target) {
        int d = r_depth(root, target);
        std::cout << "The depth of the node " << target << " s: " << d << std::endl;
    }

    // is a binary search tree
    void is_bst() {
        bool is_bst = is_binary_search_tree_better(root);
        if (is_bst) {
            std::cout << "It is a binary search tree!" << std::endl;
        } else {
            std::cout << "Not a binary search tree!" << std::endl;
        }
    }

    // Deletion
    void delete_node(T key) {
        root = delete_node(root, key);
    }

    // successor
    void in_order_successor(T key) {
        Node<T>* successor = in_order_successor(root, key);
        if (successor == nullptr) {
            std::cout << "No successor!" << std::endl;
        } else {
            std::cout << "The successor is: " << successor->key << std::endl;
        }
    }

    // predecessor
    void in_order_predecessor(T key) {
        Node<T>* predecessor = in_order_predecessor(root, key);
        if (predecessor == nullptr) {
            std::cout << "No predecessor!" << std::endl;
        } else {
            std::cout << "The predecessor is: " << predecessor->key << std::endl;
        }
    }

};