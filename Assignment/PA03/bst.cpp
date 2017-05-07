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
	if(this->root == NULL){
		return NULL;
	}
	BST<T,K>* next = this->root;
	while(next != NULL){
		if(k > next->key){
			next = next->right_subtree();
		}else if(k < next->key){
			next = next->left_subtree();
		}else{
			return next;
		}
	}
	return NULL;
}

//template <typename T, typename K>
//BT<T,K>* searchItem(node* root, const K& k){
//    //write your codes here
//	if(root == NULL){
//		return NULL;
//	}
//	if(k > root->key){
//		return searchItem(root->right_subtree(), k);
//	}else if(k < root->key){
//		return searchItem(root->left_subtree(), k);
//	}else{
//		return root;
//	}
//}

template <typename T, typename K>
BT<T,K>* searchParent(BST<T, K>* root, const K& k){
    //write your codes here
	if(root == NULL){
		return NULL;
	}
	if(k > root->key){
		if(search(k) == root->right_subtree()){
			return root;
		}else{
			return searchParent(root->right_subtree(), k);
		}
	}else if(k < root->key){
		if(search(k) == root->left_subtree()){
			return root;
		}else{
			return searchParent(root->left_subtree(), k);
		}
	}else{
		return NULL;
	}
}

/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min(){
    //write your codes here
	if(this->root == NULL){
		return NULL;
	}
	BST<T, K>* smallest = this->root;
	while(smallest->left != NULL){
		smallest = smallest->left;
	}
	return smallest;
}

//template <typename T, typename K>
//BT<T,K>* findMinItem(BST<T, K>* root){
//    //write your codes here
//	if(root == NULL){
//		return NULL;
//	}
//	if(root->left_subtree() != NULL){
//		findMinItem(root->left_subtree());
//	}else{
//		return root;
//	}
//}

template <typename T, typename K>
BT<T,K>* findMinParent(BST<T, K>* root){
    //write your codes here
	if(BST<T, K>::find_min() == root->left_subtree()){
		return root;
	}else if(root->left_subtree() != NULL){
		return findMinParent(root->left_subtree);
	}else{
		return NULL;
	}
}

/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k){
    //write your codes here
	if(this->root != NULL){
		BST<T, K>* insertItem = this->root;
		while(true){
			if(k > insertItem->key){
				if(insertItem->right_subtree() != NULL){
					insertItem = insertItem->right_subtree();
				}else{
					insertItem->right_subtree() = new BST<T, K>*(x, k, insertItem->height());
					return;
				}
			}else if(k < insertItem->key){
				if(insertItem->left_subtree() != NULL){
					insertItem = insertItem->left_subtree();
				}else{
					insertItem->left_subtree() = new BST<T, K>*(x, k, insertItem->height());
					return;
				}
			}else{
				remove(k);
				insert(x, k);
				return;
			}
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
	BST<T, K>* target = search(k);
	if(target != this->root){
		if(target->right_subtree() == NULL && target->left_subtree() == NULL){
			target = NULL;
		}else if(target->right_subtree() == NULL){
			BST<T, K>* parent = searchParent(this->root, k);
			if(parent->left_subtree() == target){
				parent->left_subtree() = target->left_subtree();
				target = NULL;
			}else if(parent->right_subtree() == target){
				parent->right_subtree() = target->left_subtree();
				target = NULL;
			}
		}else if(target->left_subtree() == NULL){
			BST<T, K>* parent = searchParent(this->root, k);
			if(parent->left_subtree() == target){
				parent->left_subtree() = target->right_subtree();
				target = NULL;
			}else if(parent->right_subtree() == target){
				parent->right_subtree() = target->right_subtree();
				target = NULL;
			}
		}else{
			BST<T, K>* right = target->right_subtree();
			if(right->right_subtree() == NULL && right->left_subtree() == NULL){
				target->value = right->value;
				target->key = right->key;
				right = NULL;
			}else{
				BST<T, K>* smallest = right->find_min();
				target->value = smallest->value;
				target->key = smallest->key;
				smallest = NULL;
			}
		}
	}else{
		if(target->right_subtree() == NULL && target->left_subtree() == NULL){
			this->root = NULL;
		}else if(target->right_subtree() == NULL){
			this->root = this->root->left_subtree();
			target = NULL;
		}else if(target->left_subtree() == NULL){
			this->root = this->root->right_subtree();
			target = NULL;
		}else{
			BST<T, K>* right = target->right_subtree();
			if(right->right_subtree() == NULL && right->left_subtree() == NULL){
				target->value = right->value;
				target->key = right->key;
				right = NULL;
				target->right_subtree() = NULL;
			}else{
				BST<T, K>* smallest = right->find_min();
				BST<T, K>* parent = findMinParent(right);
				target->value = smallest->value;
				target->key = smallest->key;
				smallest = NULL;
				parent->left_subtree() = NULL;
			}
		}
	}
}

//template <typename T, typename K>
//void removeItem(BST<T, K>* root, const K& k){
//    //write your codes here
//	if(root == NULL){
//		return NULL;
//	}else if(k > root->key){
//		removeItem(root->right_subtree(), k);
//	}else if(k < root->key){
//		removeItem(root->left_subtree(), k);
//	}else{
//		BST<T, K>* temp = root;
//		if(root->right_subtree() == NULL){
//			root = root->left_subtree();
//			delete temp;
//		}else if(root->left_subtree() == NULL){
//			root = root->right_subtree();
//			delete temp;
//		}else{
//			BST<T, K>* minimum = new findMinItem(root->right_subtree());
//			minimum
//			root = minium;
//			delete temp;
//		}
//	}
//}

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
			this->current = this->current->left_subtree();
		}
		this->current = this->istack.top();
	}
	if(!this->istack.empty()){
		BST<T, K>* returnNode = this->istack.top();
		this->istack.pop();
		if(returnNode->right_subtree() != NULL){
			this->current = returnNode->right_subtree();
			while(this->current != NULL){
				this->istack.push(this->current);
				this->current = this->current->left_subtree();
			}
		}
		if(!this->istack.empty()){
			this->current = this->istack.top();
		}else{
			this->current = NULL;
		}
		return returnNode->value;
	}
}

#endif /* BST_CPP */
