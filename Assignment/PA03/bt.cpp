/*
 * bt.cpp
 *
 */

#ifndef BT_CPP
#define BT_CPP


/* TODO
 * Goal: Do preorder traversal on the tree
 * Remark: print both value and key fields of each node
 */
template <typename T, typename K>
void BT<T,K>::preorder_traversal() const{
    //write your codes here
}



/* TODO:
 * Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BT<T,K>::iterator_init(){
    //write your codes here
	while(!istack.empty()){
		istack.pop();
	}
	current = root;
}

/* TODO:
 * Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BT<T,K>::iterator_end(){
     //write your codes here
	if(current == root && !istack.empty && istack.top() == root){
		return true;
	}else{
		return false;
	}
}

/* TODO:
 * Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BT<T,K>::iterator_next()
{
    //write your codes here
	if(istack.empty()){
		while(current->left != 0){
			istack.push(current);
			current = current->left;
		}
		current = istack.top();
		istack.pop();
		return current->left->value;
	}

}

#endif /* BT_CPP */
