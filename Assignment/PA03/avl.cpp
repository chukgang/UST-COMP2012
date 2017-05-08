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
template <typename T, typename K>
int AVL<T,K>::bfactor() const{
    //write your codes here
	fix_height();
	int left = 0;
	int right = 0;
	if(this->root->left != NULL){
		left = dynamic_cast<AVL<T, K>*>(this->root->left)->root->bt_height + 1;
	}
	if(this->root->right != NULL){
		right = dynamic_cast<AVL<T, K>*>(this->root->right)->root->bt_height + 1;
	}
	cout << "right " << right << " left " << left << endl;
	return right - left;
}


/* TODO
 * Goal: To rectify the height values of each node of of an AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::fix_height() const{
    //write your codes here
	if(this->root->left != NULL){
		dynamic_cast<AVL<T, K>*>(this->root->left)->fix_height();
	}
	if(this->root->right != NULL){
		dynamic_cast<AVL<T, K>*>(this->root->right)->fix_height();
	}
	int left;
	int right;
	if(this->root->left != NULL){
		left = dynamic_cast<AVL<T, K>*>(this->root->left)->root->bt_height;
	}else{
		left = -1;
	}
	if(this->root->right != NULL){
		right = dynamic_cast<AVL<T, K>*>(this->root->right)->root->bt_height;
	}else{
		right = -1;
	}
	if(left == -1 && right == -1){
		this->root->bt_height = 0;
	}else if(left > right){
		this->root->bt_height = left + 1;
	}else{
		this->root->bt_height = right + 1;
	}

}


/* TODO
 * Goal: To perform a single left (anti-clocwise) rotation of the root 
 */
template <typename T, typename K>
void AVL<T,K>::rotate_left(){
	//write your codes here
	if(this->root != NULL){
		AVL<T, K>* centre = this;
		if(this->root->right != NULL){
			AVL<T, K>* leftRotate = dynamic_cast<AVL<T, K>*>(this->root->right);
			if(centre->root->left == NULL){
				centre->root->left = new AVL<T, K>;
				dynamic_cast<AVL<T, K>*>(centre->root->left)->root = new bt_node(centre->root->value, centre->root->key);
				centre->root->value = leftRotate->root->value;
				centre->root->key = leftRotate->root->key;
				if(leftRotate->bfactor() > 0){
					leftRotate->root->value = dynamic_cast<AVL<T, K>*>(leftRotate->root->right)->root->value;
					leftRotate->root->key = dynamic_cast<AVL<T, K>*>(leftRotate->root->right)->root->key;
					dynamic_cast<AVL<T, K>*>(leftRotate->root->right)->remove(leftRotate->root->key);
				}else if(leftRotate->bfactor() < 0){
					leftRotate->root->value = dynamic_cast<AVL<T, K>*>(leftRotate->root->left)->root->value;
					leftRotate->root->key = dynamic_cast<AVL<T, K>*>(leftRotate->root->left)->root->key;
					dynamic_cast<AVL<T, K>*>(leftRotate->root->left)->remove(leftRotate->root->key);
				}
			}
			this->fix_height();
			dynamic_cast<AVL<T, K>*>(leftRotate->root->left)->fix_height();
			dynamic_cast<AVL<T, K>*>(leftRotate->root->right)->fix_height();
		}
	}
}


/* TODO
 * Goal: To perform right (clockwise) rotation of the root 
 */
template <typename T, typename K>
void AVL<T,K>::rotate_right(){
     //write your codes here
	if(this->root != NULL){
		AVL<T, K>* centre = this;
		if(this->root->left != NULL){
			AVL<T, K>* rightRotate = dynamic_cast<AVL<T, K>*>(this->root->left);
			if(centre->root->right == NULL){
				centre->root->right = new AVL<T, K>;
				dynamic_cast<AVL<T, K>*>(centre->root->right)->root = new bt_node(centre->root->value, centre->root->key);
				centre->root->value = rightRotate->root->value;
				centre->root->key = rightRotate->root->key;
				if(rightRotate->bfactor() > 0){
					rightRotate->root->value = dynamic_cast<AVL<T, K>*>(rightRotate->root->right)->root->value;
					rightRotate->root->key = dynamic_cast<AVL<T, K>*>(rightRotate->root->right)->root->key;
					dynamic_cast<AVL<T, K>*>(rightRotate->root->right)->remove(rightRotate->root->key);
				}else if(rightRotate->bfactor() < 0){
					rightRotate->root->value = dynamic_cast<AVL<T, K>*>(rightRotate->root->left)->root->value;
					rightRotate->root->key = dynamic_cast<AVL<T, K>*>(rightRotate->root->left)->root->key;
					dynamic_cast<AVL<T, K>*>(rightRotate->root->left)->remove(rightRotate->root->key);
				}
			}
			this->fix_height();
			dynamic_cast<AVL<T, K>*>(rightRotate->root->left)->fix_height();
			dynamic_cast<AVL<T, K>*>(rightRotate->root->right)->fix_height();
		}
	}
}

/* TODO
 * Goal: To balance an AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::balance(){
     //write your codes here
	fix_height();
	if(this->root == NULL){
		return;
	}
	if(this->root->left != NULL){
		dynamic_cast<AVL<T, K>*>(this->root->left)->balance();
	}
	if(this->root->right != NULL){
		dynamic_cast<AVL<T, K>*>(this->root->right)->balance();
	}
	if(this->bfactor() < -1){
		this->rotate_right();
	}else if(this->bfactor() > 1){
		this->rotate_left();
	}
	fix_height();
}


/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template <typename T, typename K>
void AVL<T,K>::insert(const T& x, const K& k){
     //write your codes here
	if(this->root == NULL){
		this->root = new bt_node(x, k);
	}
	if(k > this->root->key){
		if(this->root->right == NULL){
			this->root->right = new AVL<T, K>;
			dynamic_cast<AVL<T, K>*>(this->root->right)->root = new bt_node(x, k);
			balance();
			return;
		}else{
			dynamic_cast<AVL<T, K>*>(this->root->right)->insert(x, k);
		}
	}else if(k < this->root->key){
		if (this->root->left == NULL){
			this->root->left = new AVL<T, K>;
			dynamic_cast<AVL<T, K>*>(this->root->left)->root = new bt_node(x, k);
			balance();
			return;
		}else{
			dynamic_cast<AVL<T, K>*>(this->root->left)->insert(x, k);
		}
	}else{
		balance();
		return;
	}
}



/* TODO
 * Goal: To remove an item with key k in AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::remove(const K& k){
     //write your codes here
	BST<T, K>::remove(k);
	balance();
}



#endif /* AVL_CPP */
