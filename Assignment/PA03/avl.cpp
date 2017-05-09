/*
 * avl.cpp
 */

#ifndef AVL_CPP
#define AVL_CPP

#include "avl.h"

/* TODO
 * Goal: To find the balance factor of an AVL tree
 *       balance factor = height of right sub-tree - height of left sub-tree
 * Return: (int) balance factor
 */
template<typename T, typename K>
int AVL<T, K>::bfactor() const{
	int left = -1;
	int right = -1;
	this->fix_height();
	if(this->root->left != NULL){
		left = (dynamic_cast<AVL<T, K>*>(this->root->left))->height();
	}
	if(this->root->right != NULL){
		right = (dynamic_cast<AVL<T, K>*>(this->root->right))->height();
	}
	return right - left;
}

/* TODO
 * Goal: To rectify the height values of each node of of an AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::fix_height() const{
	int left = 0;
	int right = 0;
	if(this->root->left == NULL && this->root->right == NULL){
		this->root->bt_height = 0;
		return;
	}
	if(this->root->left != NULL){
		AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->left);
		target->fix_height();
		left = target->height();
	}
	if(this->root->right != NULL){
		AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->right);
		target->fix_height();
		right = target->height();
	}
	if(left > right){
		this->root->bt_height = left + 1;
	}
	else{
		this->root->bt_height = right + 1;
	}
	return;
}

/* TODO
 * Goal: To perform a single left (anti-clocwise) rotation of the root 
 */
template<typename T, typename K>
void AVL<T, K>::rotate_left(){
	AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->right);
	bt_node* targetNode = target->root;
	this->root->right = targetNode->left;
	target->root = this->root;
	this->root = targetNode;
	this->root->left = target;
	this->fix_height();
}

/* TODO
 * Goal: To perform right (clockwise) rotation of the root 
 */
template<typename T, typename K>
void AVL<T, K>::rotate_right(){
	AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->left);
	bt_node* targetNode = target->root;
	this->root->left = targetNode->right;
	target->root = this->root;
	this->root = targetNode;
	this->root->right = target;
	this->fix_height();
}

/* TODO
 * Goal: To balance an AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::balance(){
	if(this->root->right != NULL){
		dynamic_cast<AVL<T, K>*>(this->root->right)->balance();
	}
	if(this->root->left != NULL){
		dynamic_cast<AVL<T, K>*>(this->root->left)->balance();
	}
	if(this->bfactor() > 1){
		AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->right);
		if(target->bfactor() < 0){
			target->rotate_right();
		}
		this->rotate_left();
	}else if(this->bfactor() < -1){
		AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->left);
		if(target->bfactor() > 0){
			target->rotate_left();
		}
		this->rotate_right();
		}
	return;
}

/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template<typename T, typename K>
void AVL<T, K>::insert(const T& x, const K& k){
	if(this->root == NULL){
		this->root = new bt_node(x, k);
		return;
	}else if(this->root->key > k){
		if(this->root->left == NULL){
			this->root->left = new AVL<T, K>;
			(dynamic_cast<AVL<T, K>*>(this->root->left))->root = new bt_node(x, k);
			this->balance();
			return;
		}
		else{
			(dynamic_cast<AVL<T, K>*>(this->root->left))->insert(x, k);
			this->balance();
		}
	}else{
		if(this->root->right == NULL){
			this->root->right = new AVL<T, K>;
			(dynamic_cast<AVL<T, K>*>(this->root->right))->root = new bt_node(x, k);
			this->balance();
			return;
		}else{
			(dynamic_cast<AVL<T, K>*>(this->root->right))->insert(x, k);
			this->balance();
		}
	}
	this->balance();
}

/* TODO
 * Goal: To remove an item with key k in AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::remove(const K& k){
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
	if(this->root->key == k){
		if(this->root->left == NULL && this->root->right != NULL){
			AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->right);
			this->root->right = NULL;
			delete this->root;
			this->root = target->root;
		}else if(this->root->left != NULL && this->root->right == NULL){
			AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->left);
			this->root->left = NULL;
			delete this->root;
			this->root = target->root;
		}else if(this->root->left != NULL && this->root->right != NULL){
			AVL<T, K>* parent = this;
			AVL<T, K>* child = dynamic_cast<AVL<T, K>*>(this->root->right);
			while (child->root->left != NULL){
				parent = child;
				child = dynamic_cast<AVL<T, K>*>(child->root->left);
			}
			if(child != NULL){
				this->root->key = child->root->key;
				this->root->value = child->root->value;
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
		}else{
			delete this->root;
			this->root = NULL;
			return;
		}
	}else if(this->root->key > k){
		AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->left);
		target->remove(k);
		if(target->root == NULL){
			this->root->left = NULL;
			delete target;
		}
	}else{
		AVL<T, K>* target = dynamic_cast<AVL<T, K>*>(this->root->right);
		target->remove(k);
		if(target->root == NULL){
			this->root->right = NULL;
		}
	}
	this->balance();
	if(!this->iterator_end()){
		bt_node* copy = this->root;
		AVL<T, K>* target = this;
		this->iterator_init();
		while (target->root->left != NULL){
			target = dynamic_cast<AVL<T, K>*>(target->root->left);
		}
		copy = target->root;
		while (copy->key != key){
			this->iterator_next();
			copy = this->current;
		}
	}
}

#endif/* AVL_C*/
