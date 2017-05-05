/*
 * bt.h
 * Abstract base class representing binary tree
 */

#ifndef BT_H
#define BT_H

#include <iostream>
#include <stack>
using namespace std;

template <typename T, typename K> class BT
{
  protected:
    struct node
    {
        T value;
        K key;
        int bt_height;
        BT* left;
        BT* right;
        node(const T& x, const K& k, int h = 0, BT* L = 0, BT* R = 0)
          : value(x), key(k), bt_height(h), left(L), right(R) { }
        ~node() { delete left; delete right; }
    };

    node* root;
    node* current;       // The iterator
    stack<node*> istack; // Used for iterator

    const BT* right_subtree() const { return root->right; }
    const BT* left_subtree() const { return root->left; }
    BT*& right_subtree() { return root->right; }
    BT*& left_subtree() { return root->left; }

  public:
    BT() : root(0), current(0) { }
    virtual ~BT() { delete root; }

    bool is_empty() const { return root == NULL; }
    void print_value() const { cout << root->value << endl; }
    int height() const { return root ? root->bt_height : -1; }

   /* Preorder traversal through the whole tree
    * Print each node (both value and key fields)
    * Please refer to the sample output for the output format
    */
    virtual void preorder_traversal() const;
    
    /* To find the minimum node stored in a BST tree
     * Return: A pointer to the subtree whose root node contains the minimum key
     */
    virtual BT* find_min() = 0;

    // Insert value x with key k to the tree
    virtual void insert(const T& x, const K& k) = 0;

    // Remove nodes whose key equals k from the tree
    virtual void remove(const K& k) = 0;

    /* Search for an item x with key k from the tree
     * Return: A pointer to the subtree whose root node contains the item
    *          if found, otherwise a NULL pointer.
     */
    virtual BT* search(const K& k) = 0;

    /* Print in a readable tree format
     * For each node you only need to print its key
     * You don't need to be exactly the same with sample output
     * The output format of this function will not be tested
     */
    virtual void print(int depth = 0) const = 0;

    /*
     * The following three functions are used by the iterator of BT
     */
    virtual void iterator_init() = 0;
    virtual bool iterator_end() = 0;
    virtual T& iterator_next() = 0;
};

#include "bt.cpp"

#endif /* BT_H */
