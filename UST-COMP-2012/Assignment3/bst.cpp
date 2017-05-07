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
	if (this->root->key == k)
	{
		return this;
	}
	if (this->root->key > k)
	{
		if (this->left_subtree() != NULL)
		{
			return (dynamic_cast<BST<T, K>*>(this->left_subtree()))->search(k);
		}
		return NULL;
	}
	if (this->right_subtree() != NULL)
	{
		return (dynamic_cast<BST<T, K>*>(this->right_subtree()))->search(k);
	}
	return NULL;
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T,K>* BST<T,K>::find_min()
{
	if (this->left_subtree() == NULL)
	{
		return this;
	}
	return (dynamic_cast<BST<T, K>*>(this->left_subtree()))->find_min();
}

/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k)
{
	if (this->root == NULL)
	{
		this->root = new bt_node(x, k);
		return;
	}
	if (this->root->key > k)
	{
		if (this->left_subtree() == NULL)
		{
			this->left_subtree() = new BST<T, K>();
			(dynamic_cast<BST<T, K>*>(this->left_subtree()))->root = new bt_node(x, k);
			return;
		}
		(dynamic_cast<BST<T, K>*>(this->left_subtree()))->insert(x, k);
		return;
	}
	if (this->root->key < k)
	{
		if (this->right_subtree() == NULL)
		{
			this->right_subtree() = new BST<T, K>();
			(dynamic_cast<BST<T, K>*>(this->right_subtree()))->root = new bt_node(x, k);
			return;
		}
		(dynamic_cast<BST<T, K>*>(this->right_subtree()))->insert(x, k);
	}
	return;
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
	while (!this->istack.empty())
	{
		this->istack.pop();
	}
	this->current = this->root;
}


/* TODO
 * Goal: Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BST<T,K>::iterator_end()
{
	return (this->current == NULL);
}


/* TODO
 * Goal: Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BST<T,K>::iterator_next()
{
	if (this->istack.empty() && this->current == this->root)
	{
		BST<T, K>* tar = this;
		while (tar != NULL)
		{
			this->istack.push(tar->root);
			tar = dynamic_cast<BST<T, K>*>(tar->left_subtree());
		}
		this->current = this->istack.top();
	}
	if (!this->istack.empty())
	{
		bt_node* ret = this->istack.top();
		this->istack.pop();
		if (ret->right != NULL)
		{
			BST<T, K>* tar = dynamic_cast<BST<T, K>*>(ret->right);
			while (tar != NULL)
			{
				this->istack.push(tar->root);
				tar = dynamic_cast<BST<T, K>*>(tar->left_subtree());
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
		return ret->value;
	}
}


#endif /* BST_CPP */
