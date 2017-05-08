/*
 * bst.cpp
 *
 */

#ifndef BST_CPP
#define BST_CPP
#include "bst.h"
#include "iostream"
using namespace std;

/* TODO
 * Goal: To search for an item x with key k from the BST tree
 * Return: A pointer to the subtree whose root node contains the item if found,
 *         otherwise a NULL pointer.
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::search(const K& k){
    //write your codes here
	if(this->root == NULL){
		return NULL;
	}
	if(k > this->root->key){
		return dynamic_cast<BST<T, K>*>(this->root->right)->search(k);
	}else if(k < this->root->key){
		return dynamic_cast<BST<T, K>*>(this->root->left)->search(k);
	}else{
		return this;
	}
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min(){
    //write your codes here
	if(this->root->left == NULL){
		return this;
	}else{
		return dynamic_cast<BST<T, K>*>(this->root->left)->find_min();
	}
}


/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k){
    //write your codes here
	if(this->root == NULL){
		this->root = new bt_node(x, k);
	}
	if(k > this->root->key){
		dynamic_cast<BST<T, K>*>(this->root->right)->insert(k);
	}else if(k < this->root->key){
		dynamic_cast<BST<T, K>*>(this->root->left)->insert(k);
	}else{
		this->root->remove(k);
		this->root->insert(x, k);
		return;
	}
}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k){
    //write your codes here
}


/* TODO
 * Goal: Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BST<T,K>::iterator_init(){
    //write your codes here
	while(!this->istack.empty()){
		this->istack.pop();
	}
	this->current = this->root;
}


/* TODO
 * Goal: Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BST<T,K>::iterator_end(){
    //write your codes here
	return (this->current == NULL);
}


/* TODO
 * Goal: Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BST<T,K>::iterator_next(){
    //write your codes here
	if(this->istack.empty() && this->current == this->root){
		while(this->current != NULL){
			this->istack.push(this->current);
			this->current = dynam(this->current->left);
		}
		this->current = this->istack.top();
	}
	if(!this->istack.empty()){
		BT<T, K>* returnNode = this->istack.top();
		this->istack.pop();
		if(returnNode->root->right != NULL){
			this->current = returnNode->root->right;

		}
	}
}


#endif /* BST_CPP */
