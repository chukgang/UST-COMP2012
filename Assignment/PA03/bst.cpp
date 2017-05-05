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
	stack<typename T, typename K> searchKey;
	searchKey.push(root);
	while(!searchKey.empty()){
		if(k > searchKey.top()->key){
			searchKey.push(searchKey.top()->right_subtree());
		}else if(k < searchKey.top->key){
			searchKey.push(searchKey.top()->left_subtree());
		}else{
			return searchKey.top();
		}
	}
	return NULL;
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min(){
    //write your codes here
	if(root != NULL){
		node* minimum = root;
	}else{
		return;
	}
	while(ture){
		if(minimum->left_subtree() != 0){
			minimum = minimum->left_subtree();
		}else if(minimum->right_subtree() != 0){
			minimum = minimum->right_subtree();
		}else{
			return minimum;
		}
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
	if(root != NULL){
		node* removeItem = root;
	}else{
		return;
	}
	while(ture){
		if(k > removeItem->key){
			if(removeItem->right_subtree() != NULL){
				removeItem = removeItem->right_subtree();
			}else{
				return;
			}
		}else if(k < removeItem->key){
			if(removeItem->left_subtree() != NULL){
				removeItem = removeItem->left_subtree();
			}else{
				return;
			}
		}else{

			return;
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
