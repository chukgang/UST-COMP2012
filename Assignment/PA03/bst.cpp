/*
 * bst.cpp
 *
 */

#ifndef BST_CPP
#define BST_CPP


/* TODO
 * Goal: To search for an item x with key k from the BST tree
 * Return: A pointer to the subtree whose root node contains the item if found,
 *         otherwise a NULL pointer.
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::search(const K& k){
    //write your codes here
	return searchItem(root, k);
}

template <typename T, typename K>
BT<T,K>* BST<T,K>::searchItem(BST<T, K>* root, const K& k){
    //write your codes here
	if(root == NULL){
		return NULL;
	}
	if(k > root->key){
		return searchItem(root->right_subtree(), k);
	}else if(k < root->key){
		return searchItem(root->left_subtree(), k);
	}else{
		return root;
	}
}

/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min(){
    //write your codes here
	findMinItme(root);
}

template <typename T, typename K>
BT<T,K>* BST<T,K>::findMinItem(BST<T, K>* root){
    //write your codes here
	if(root == NULL){
		return NULL;
	}
	if(root->left_subtree() != NULL){
		findMinItem(root->left_subtree());
	}else if(root->right_subtree() != NULL){
		findMinItem(root->right_subtree());
	}else{
		return root;
	}
}



/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k){
    //write your codes here
	if(root != NULL){
		node* insertItem = root;
	}else{
		return;
	}
	while(ture){
		if(k > insertItem->key){
			if(insertItem->right_subtree() != NULL){
				insertItem = insertItem->right_subtree();
			}else{
				insertItem->right_subtree() = new node(x, k, insertItem->height());
				return;
			}
		}else if(k < insertItem->key){
			if(insertItem->left_subtree() != NULL){
				insertItem = insertItem->left_subtree();
			}else{
				insertItem->left_subtree() = new node(x, k, insertItem->height());
				return;
			}
		}else{
			remove(k);
			insert(x, k);
			return;
		}
	}
}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k){
    //write your codes here
	if(searchItem(root, k) != NULL){
		root = removeItem(root, k);
	}
}

template <typename T, typename K>
void BST<T,K>::removeItem(BST<T, K>* root, const K& k){
    //write your codes here
	if(root == NULL){
		return NULL;
	}else if(k > root->key){
		removeItem(root->right_subtree(), k);
	}else if(k < root->key){
		removeItem(root->left_subtree(), k);
	}else{
		BST<T, K>* temp = root;
		if(root->right_subtree() == NULL){
			root = root->left_subtree();
			delete temp;
		}else if(root->left_subtree() == NULL){
			root = root->right_subtree();
			delete temp;
		}else{
			BST<T, K>* minimum = new findMinItem(root->right_subtree());
			minimum
			root = minium;
			delete temp;
		}
	}
}

/* TODO
 * Goal: Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BST<T,K>::iterator_init(){
    //write your codes here
}


/* TODO
 * Goal: Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BST<T,K>::iterator_end(){
    //write your codes here
}


/* TODO
 * Goal: Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BST<T,K>::iterator_next(){
    //write your codes here
}

#endif /* BST_CPP */
