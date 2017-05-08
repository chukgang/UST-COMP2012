/*
 * bt.cpp
 *
 */

#ifndef BT_CPP
#define BT_CPP

#include "bt.h"

/* TODO
 * Goal: Do preorder traversal on the tree
 * Remark: print both value and key fields of each node
 */
template<typename T, typename K>
void BT<T, K>::preorder_traversal() const
{
	if (this->root != NULL)
	{
		cout << "Key: " << this->root->key << "\tValue: " << this->root->value << "\n";
		if (this->left_subtree() != NULL)
		{
			this->left_subtree()->preorder_traversal();
		}
		if (this->right_subtree() != NULL)
		{
			this->right_subtree()->preorder_traversal();
		}
	}
}

#endif /* BT_CPP */
