/*
 * bt.cpp
 *
 */

#ifndef BT_CPP
#define BT_CPP
#include <iostream>
#include "bt.h"
using namespace std;
/* TODO
 * Goal: Do preorder traversal on the tree
 * Remark: print both value and key fields of each node
 */
template <typename T, typename K>
void BT<T,K>::preorder_traversal() const{
    //write your codes here
	stack<node*> preorderTraversal;
	if(this->root != NULL){
		cout << "Key: " << this->root->key << "\tValue: " << this->root->value << endl;
	}
	if(this->root->right != NULL){
		preorderTraversal.push(this->root->right->root);
	}
	if(this->root->left != NULL){
		preorderTraversal.push(this->root->left->root);
	}
	while(!preorderTraversal.empty()){
		cout << "Key: " << preorderTraversal.top()->key << "\tValue: " << preorderTraversal.top()->value << endl;
		node* next = preorderTraversal.top();
		preorderTraversal.pop();
		if(next->right != NULL){
			preorderTraversal.push(next->right->root);
		}
		if(next->left != NULL){
			preorderTraversal.push(next->left->root);
		}
	}
}
#endif /* BT_CPP */
