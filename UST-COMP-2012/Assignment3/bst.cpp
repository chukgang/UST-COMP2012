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
	node* tar = this->root;
	while (tar != NULL)
	{
		if (tar->key == k)
		{
			return tar;
		}
		if (tar->key < k)
		{
			tar = tar->left;
		}
		else
		{
			tar = tar->right;
		}
	}
	return NULL;
	/* code end */
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
	node* tar = this->root;
	while (tar->left != NULL)
	{
		tar = tar->left;
	}
	return tar;
	/* code end */
}


/* TODO
 * Goal: To insert an item x with key k to a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::insert(const T& x, const K& k)
{
    //write your codes here
	/* code here */
	node* tar = this->root;
	while (true)
	{
		if (tar->key == k)
		{
			return;
		}
		if (tar->key < k)
		{
			if (tar->left == NULL)
			{
				tar->left = new node(x, k);
				return;
			}
			tar = tar->left;
		}
		else
		{
			if (tar->right == NULL)
			{
				tar->right = new node(x, k);
				return;
			}
			tar = tar->right;
		}
	}
	return NULL;
	/* code end */
}


/* TODO
 * Goal: To remove an item with key k in a BST tree 
 */
template <typename T, typename K>
void BST<T,K>::remove(const K& k)
{    
    //write your codes here
	/* code here */

	/* code end */
}

#endif /* BST_CPP */
