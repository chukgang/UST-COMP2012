/*
 * avl.cpp
 */

#ifndef AVL_CPP
#define AVL_CPP



/* TODO
 * Goal: To find the balance factor of an AVL tree
 *       balance factor = height of right sub-tree - height of left sub-tree
 * Return: (int) balance factor
 */
template <typename T, typename K>
int AVL<T,K>::bfactor() const{
    //write your codes here
	return this->root->right_subtree()->height() - this->root->left_subtree()->height();
}


/* TODO
 * Goal: To rectify the height values of each node of of an AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::fix_height() const{
    //write your codes here
	int left = 0;
	int right = 0;
	if(this->root->left_subtree() == NULL && this->root->right_subtree() == NULL){
		this->root->bt_height = 0;
		return;
	}
	if(this->root->right_subtree() == NULL){
		AVL<T, K>* target = this->root->left_subtree();
		target->fix_height();
		left = target->height();
	}
	if(this->root->left_subtree() == NULL){
		AVL<T, K>* target = this->root->right_subtree();
		target->fix_height();
		right = target->height();
	}
	if(left > right){
		this->root->height() = left + 1;
	}else{
		this->root->height() = right + 1;
	}
	return;
}


/* TODO
 * Goal: To perform a single left (anti-clocwise) rotation of the root 
 */
template <typename T, typename K>
void AVL<T,K>::rotate_left(){
    //write your codes here
	AVL<T, K>* leftRotate = this->root->right_subtree();
	AVL<T, K>* originalRoot = this->root;
	if(leftRotate->bfactor() > 0){
		leftRotate->left_subtree() = this->root;
		originalRoot->right_subtree() = NULL;
		this->root = leftRotate;
	}else if(leftRotate->bfactor() < 0){
		AVL<T, K>* newRoot = leftRotate->left_subtree();
		newRoot->right_subtree() = leftRotate;
		newRoot->left_subtree() = originalRoot;
		originalRoot->right_subtree() = NULL;
		leftRotate->left_subtree() = NULL;
		this->root = newRoot;
	}
	this->root->fix_height();
	this->root->left_subtree()->fix_height();
	this->root->right_subtree()->fix_height();
}


/* TODO
 * Goal: To perform right (clockwise) rotation of the root 
 */
template <typename T, typename K>
void AVL<T,K>::rotate_right(){
     //write your codes here
	AVL<T, K>* rightRotate = this->root->left_subtree();
	AVL<T, K>* originalRoot = this->root;
	if(rightRotate->bfactor() < 0){
		rightRotate->right_subtree() = this->root;
		originalRoot->left_subtree() = NULL;
		this->root = rightRotate;
	}else if(rightRotate->bfactor() > 0){
		AVL<T, K>* newRoot = rightRotate->right_subtree();
		newRoot->left_subtree() = rightRotate;
		newRoot->right_subtree() = originalRoot;
		originalRoot->left_subtree() = NULL;
		rightRotate->right_subtree() = NULL;
		this->root = newRoot;
	}
	this->root->fix_height();
	this->root->right_subtree()->fix_height();
	this->root->left_subtree()->fix_height();
}

/* TODO
 * Goal: To balance an AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::balance(){
     //write your codes here
	if(this->root->left != NULL){
		this->root->left->balance();
	}
	if(this->root->right != NULL){
		this->root->right->balance();
	}
	if(this->root->bfactor() < -1){
		if(this->root->left->bfactor() < 0){

		}else{

		}
	}
}


/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template <typename T, typename K>
void AVL<T,K>::insert(const T& x, const K& k){
     //write your codes here
	if(this->root == NULL){
		this->root = new AVL<T, K>*(x, k);
	}else{
		if(k > this->root->key){
			this->root->right->insert(x, k);
			this->root->balance();
		}else if(k < this->root->key){
			this->root->left->insert(x, k);
			this->root->balance();
		}
	}
}



/* TODO
 * Goal: To remove an item with key k in AVL tree 
 */
template <typename T, typename K>
void AVL<T,K>::remove(const K& k){
     //write your codes here
	BST<T,K>::remove(k);
	this->root->balance();
}



#endif /* AVL_CPP */
