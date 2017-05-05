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
BT<T,K>* BST<T,K>::search(const K& k)
{
    //write your codes here
	/* code here */
	if (this->root->key == k)
	{
		return this;
	}
	if (this-root->key > k)
	{
		if (this->left_subtree() != NULL)
		{
			return (dynamic_cast<BST<T, K>*>(this->left_subtree())).search(k);
		}
		return NULL;
	}
	if (this->right_subtree() != NULL)
	{
		return (dynamic_cast<BST<T, K>*>(this->right_subtree())).search(k);
	}
	return NULL;
	/* code here */
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min()
{
    //write your codes here
	/* code here */
	if (this->left_subtree() == NULL)
	{
		return this;
	}
	return (dynamic_cast<BST<T, K>*>(this->left_subtree())).find_min();
	/* code end */
}

/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k)
{
    //write your codes here
}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k)
{    
    //write your codes here
}


/* TODO
 * Goal: Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BST<T,K>::iterator_init()
{
    //write your codes here
	/* code here */
	while (!this->istack.empty())
	{
		this->istack.pop();
	}
	this->current = this->root;
	/* code end */
}


/* TODO
 * Goal: Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BST<T,K>::iterator_end()
{
    //write your codes here
	/* code here */
	return (this->current == NULL);
	/* code end */
}


/* TODO
 * Goal: Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BST<T,K>::iterator_next()
{
    //write your codes here
	/* code here */
	if (this->istack.empty() && this->current == this->root)
	{
		while (this->current != NULL)
		{
			this->istack.push(this->current);
			this->current = this->current->left;
		}
		this->current = this->istack.top();
	}
	if (!this->istack.empty())
	{
		T val = this->current->value;
		this->istack.pop();
		if (this->current->right != NULL)
		{
			this->current = this->current->right;
			while (this->current != NULL)
			{
				this->istack.push(this->current);
				this->current = this->current->left;
			}
		}
		if (!this->istack.empty())
		{
			this->current = this->istack.top();
		}
		else
		{
			this->current = NULL;
		}
		return val;
	}
	/* code end */
}


#endif /* BST_CPP */
