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
		if(this->root->right != NULL){
			return dynamic_cast<BST<T, K>*>(this->root->right)->search(k);
		}else{
			return NULL;
		}
	}else if(k < this->root->key){
		if(this->root->left != NULL){
			return dynamic_cast<BST<T, K>*>(this->root->left)->search(k);
		}else{
			return NULL;
		}
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
		if(this->root->right == NULL){
			this->root->right = new BST<T, K>;
			dynamic_cast<BST<T, K>*>(this->root->right)->root = new bt_node(x, k);
			return;
		}else{
			dynamic_cast<BST<T, K>*>(this->root->right)->insert(x, k);
		}
	}else if(k < this->root->key){
		if (this->root->left == NULL){
			this->root->left = new BST<T, K>;
			dynamic_cast<BST<T, K>*>(this->root->left)->root = new bt_node(x, k);
			return;
		}else{
			dynamic_cast<BST<T, K>*>(this->root->left)->insert(x, k);
		}

	}else{
		return;
	}
}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k){
    //write your codes here
	K key = k;
	if(!this->iterator_end()){
		key = this->current->key;
		this->iterator_next();
		if(key == k){
			if(!this->iterator_end()){
				key = this->current->key;
				this->iterator_next();
			}
		}
	}
	if(k == this->root->key){
		if(this->root->right != NULL){
			BST<T, K>* parent  = this;
			BST<T, K>* child = dynamic_cast<BST<T, K>*>(this->root->right);
			if(this->root->left == NULL){
				parent->root->key = child->root->key;
				parent->root->value = child->root->value;
				parent->root->left = child->root->left;
				parent->root->right = child->root->right;
			}else{
				while(child->root->left != NULL){
					parent = child;
					child = dynamic_cast<BST<T, K>*>(child->root->left);
				}
				if(child != NULL){
					parent->root->key = child->root->key;
					parent->root->value = child->root->value;
					child->remove(child->root->key);
					if(child->root == NULL){
						if(parent->root->left == child){
							parent->root->left = NULL;
						}else{
							parent->root->right = NULL;
						}
						delete child;
					}
				}
			}
		}else if(this->root->left != NULL){
			BST<T, K>* target = dynamic_cast<BST<T, K>*>(this->root->left);
			this->root->value = target->root->value;
			this->root->key = target->root->key;
			target->remove(target->root->key);
			if(target->root == NULL){
				this->root->left = NULL;
				delete target;
			}
		}else{
			this->root = NULL;
			delete this->root;
			return;
		}
	}else if(k < this->root->key){
		BST<T, K>* target = dynamic_cast<BST<T, K>*>(this->root->left);
		target->remove(k);
		if(target->root == NULL){
			this->root->left = NULL;
			delete target;
		}
	}else{
		BST<T, K>* target = dynamic_cast<BST<T, K>*>(this->root->right);
		target->remove(k);
		if(target->root == NULL){
			this->root->right = NULL;
		}
	}
	if(!this->iterator_end()){
		bt_node* copy = this->root;
		BST<T, K>* target = this;
		this->iterator_init();
		while(target->root->left != NULL){
			target = dynamic_cast<BST<T, K>*>(target->root->left);
		}
		copy = target->root;
		while(copy->key != key){
			this->iterator_next();
			copy = this->current;
		}
	}
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
			if(this->current->left != NULL){
				this->current = dynamic_cast<BST<T, K>*>(this->current->left)->root;
			}else{
				break;
			}
		}
		this->current = this->istack.top();
	}
	if(!this->istack.empty()){
		this->current = this->istack.top();
		T& returnValue = this->current->value;
		if(this->current->right != NULL){
			this->current = dynamic_cast<BST<T, K>*>(this->current->right)->root;
			this->istack.pop();
			while(this->current != NULL){
				this->istack.push(this->current);
				if(this->current->left != NULL){
					this->current = dynamic_cast<BST<T, K>*>(this->current->left)->root;
				}else{
					break;
				}
			}
			this->current = this->istack.top();
			return returnValue;
		}else{
			this->istack.pop();
			if(!this->istack.empty()){
				this->current = this->istack.top();
			}else{
				this->current = NULL;
			}
			return returnValue;
		}
	}else{
		this->current = NULL;
	}
}


#endif /* BST_CPP */
