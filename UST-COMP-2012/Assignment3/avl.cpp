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
template<typename T, typename K>
int AVL<T, K>::bfactor() const
{
	int left = -1;
	int right = -1;
	this->fix_height();
	if (this->left_subtree() != NULL)
	{
		left = (dynamic_cast<AVL<T, K>*>(this->root->left))->height();
	}
	if (this->right_subtree() != NULL)
	{
		right = (dynamic_cast<AVL<T, K>*>(this->root->right))->height();
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
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->root->left);
		tar->fix_height();
		left = tar->height();
	}
	if (this->right_subtree() != NULL)
	{
		const AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->root->right);
		tar->fix_height();
		right = tar->height();
	}
	if (left > right)
	{
		this->root->bt_height = left + 1;
	}
	else
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
	AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->right_subtree());
	bt_node* tar_node = tar->root;
	this->root->right = tar_node->left;
	tar->root = this->root;
	this->root = tar_node;
	this->root->left = tar;
	this->fix_height();
}

/* TODO
 * Goal: To perform right (clockwise) rotation of the root 
 */
template<typename T, typename K>
void AVL<T, K>::rotate_right()
{
	AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->left_subtree());
	bt_node* tar_node = tar->root;
	this->root->left = tar_node->right;
	tar->root = this->root;
	this->root = tar_node;
	this->root->right = tar;
	this->fix_height();
}

/* TODO
 * Goal: To balance an AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::balance()
{
	if (this->root == NULL)
	{
		return;
	}
	if (this->bfactor() == 2)
	{
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->root->right);
		if (tar->bfactor() < 0)
		{
			tar->rotate_right();
		}
		this->rotate_left();
	}
	else if (this->bfactor() == -2)
	{
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->root->left);
		if (tar->bfactor() > 0)
		{
			tar->rotate_left();
		}
		this->rotate_right();
	}
}

/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template<typename T, typename K>
void AVL<T, K>::insert(const T& x, const K& k)
{
	if (this->root == NULL)
	{
		this->root = new bt_node(x, k);
	}
	else if (this->root->key > k)
	{
		if (this->left_subtree() == NULL)
		{
			this->left_subtree() = new AVL<T, K>;
			(dynamic_cast<AVL<T, K>*>(this->left_subtree()))->root = new bt_node(x, k);
		}
		else
		{
			(dynamic_cast<AVL<T, K>*>(this->left_subtree()))->insert(x, k);
		}
	}
	else if (this->root->key < k)
	{
		if (this->right_subtree() == NULL)
		{
			this->right_subtree() = new AVL<T, K>;
			(dynamic_cast<AVL<T, K>*>(this->right_subtree()))->root = new bt_node(x, k);
		}
		else
		{
			(dynamic_cast<AVL<T, K>*>(this->right_subtree()))->insert(x, k);
		}
	}
	this->balance();
	return;
}

/* TODO
 * Goal: To remove an item with key k in AVL tree 
 */
template<typename T, typename K>
void AVL<T, K>::remove(const K& k)
{
	K key = k;
	if (!this->iterator_end())
	{
		key = this->current->key;
		this->iterator_next();
		if (key == k)
		{
			if (!this->iterator_end())
			{
				key = this->current->key;
				this->iterator_next();
			}
		}
	}
	if (this->root->key == k)
	{
		if (this->left_subtree() == NULL && this->right_subtree() != NULL)
		{
			AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->right_subtree());
			this->root->right = NULL;
			delete this->root;
			this->root = tar->root;
		}
		else if (this->left_subtree() != NULL && this->right_subtree() == NULL)
		{
			AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->left_subtree());
			this->root->left = NULL;
			delete this->root;
			this->root = tar->root;
		}
		else if (this->left_subtree() != NULL && this->right_subtree() != NULL)
		{
			AVL<T, K>* parent = this;
			AVL<T, K>* child = dynamic_cast<AVL<T, K>*>(this->right_subtree());
			while (child->left_subtree() != NULL)
			{
				parent = child;
				child = dynamic_cast<AVL<T, K>*>(child->left_subtree());
			}
			if (child != NULL)
			{
				this->root->key = child->root->key;
				this->root->value = child->root->value;
				child->remove(child->root->key);
				if (child->root == NULL)
				{
					if (parent->root->left == child)
					{
						parent->root->left = NULL;
					}
					else
					{
						parent->root->right = NULL;
					}
					delete child;
				}
			}
		}
		else
		{
			delete this->root;
			this->root = NULL;
			return;
		}
	}
	else if (this->root->key > k)
	{
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->left_subtree());
		tar->remove(k);
		if (tar->root == NULL)
		{
			this->root->left = NULL;
			delete tar;
		}
	}
	else
	{
		AVL<T, K>* tar = dynamic_cast<AVL<T, K>*>(this->right_subtree());
		tar->remove(k);
		if (tar->root == NULL)
		{
			this->root->right = NULL;
		}
	}
	this->balance();
	if (!this->iterator_end())
	{
		bt_node* duplicate = this->root;
		AVL<T, K>* tar = this;
		this->iterator_init();
		while (tar->left_subtree() != NULL)
		{
			tar = dynamic_cast<AVL<T, K>*>(tar->left_subtree());
		}
		duplicate = tar->root;
		while (duplicate->key != key)
		{
			this->iterator_next();
			duplicate = this->current;
		}
	}
}

#endif /* AVL_CPP */
