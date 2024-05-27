#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> bst;
//    bst.find_maximum();
//    bst.find_minimum();
//    bst.find_r_maximum();
//    bst.find_r_minimum();
    bst.is_bst();
    bst.display_in_order();
    bst.display_post_order();
    bst.display_in_reversed_order();
    bst.display_pre_order();
    bst.depth_first();
    bst.breadth_first();

    bst.insert(5);
    bst.insert(10);
    bst.insert(17);
    bst.insert(3);
    bst.insert(4);
    bst.r_insert(50);
//    bst.search(10);
//    bst.search(50);
//    bst.i_search(50);
//    bst.i_search(10);
//    bst.find_maximum();
//    bst.find_minimum();
//    bst.find_r_maximum();
//    bst.find_r_minimum();

    bst.display_in_order();
    bst.display_in_reversed_order();
    bst.display_pre_order();
    bst.display_post_order();

    bst.breadth_first();
    bst.depth_first();

    bst.is_bst();
    bst.delete_node(50);
    bst.display_in_order();
    bst.insert(50);
    bst.display_in_order();
    bst.in_order_successor(50);
    bst.in_order_successor(4);
    bst.in_order_predecessor(10);
    bst.in_order_predecessor(3);

//    bst.get_height();
//    bst.get_depth(5);
//    bst.get_r_depth(5);

    return 0;
}
