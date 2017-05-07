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
template<typename T, typename K>
int AVL<T, K>::bfactor() const
{
	int left = 0;
	int right = 0;
	this->fix_height();
	if (this->left_subtree() != NULL)
	{
		left = (dynamic_cast<AVL<T, K>*>(this->left_subtree()))->height();
	}
	if (this->right_subtree() != NULL)
	{
		right = (dynamic_cast<AVL<T, K>*>(this->right_subtree()))->height();
	}
	return right - left;
}

/* TODO
 * Goal: To rectify the height values of each node of of an AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::fix_height() const
{
	int left = 0;
	int right = 0;
	if (this->left_subtree() == NULL && this->right_subtree() == NULL)
	{
		this->root->bt_height = 0;
		return;
	}
	if (this->left_subtree() != NULL)
	{
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->left_subtree());
		tar->fix_height();
		left = tar->height();
	}
	if (this->right_subtree() != NULL)
	{
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->right_subtree());
		tar->fix_height();
		right = tar->height();
	}
	if (left > right)
	{
		this->root->bt_height = left + 1;
	} else
	{
		this->root->bt_height = right + 1;
	}
	return;
}

/* TODO
 * Goal: To perform a single left (anti-clocwise) rotation of the root 
 */
template<typename T, typename K>
void AVL<T, K>::rotate_left()
{
	//write your codes here
}

/* TODO
 * Goal: To perform right (clockwise) rotation of the root 
 */
template<typename T, typename K>
void AVL<T, K>::rotate_right()
{
	//write your codes here
}

/* TODO
 * Goal: To balance an AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::balance()
{
	//write your codes here
}

/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template<typename T, typename K>
void AVL<T, K>::insert(const T& x, const K& k)
{
	//write your codes here
}

/* TODO
 * Goal: To remove an item with key k in AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::remove(const K& k)
{
	//write your codes here
}

#endif /* AVL_CPP */
