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
	stack<typename T, typename K> preorderTraversal;
	preorderTraversal.push(root);
	while(!preorderTraversal.empty()){
		cout << preorderTraversal.top()->value << " " << preorderTraversal.top()->key << endl;
		if(preorderTraversal.top()->right_subtree() != NULL){
			preorderTraversal.push(preorderTraversal.top()->right_subtree());
		}
		if(preorderTraversal.top()->left_subtree() != NULL){
			preorderTraversal.push(preorderTraversal.top()->left_subtree());
		}
	}
}


#endif /* BT_CPP */
