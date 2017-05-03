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
void BT<T,K>::preorder_traversal() const
{
    //write your codes here
}



/* TODO:
 * Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BT<T,K>::iterator_init()
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

/* TODO:
 * Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BT<T,K>::iterator_end()
{
     //write your codes here
	/* code here */
	return (this->current == NULL);
	/* code end */
}

/* TODO:
 * Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BT<T,K>::iterator_next()
{
    //write your codes here
	/* code here */
	node* tar = NULL;
	if (this->istack.empty())
	{
		this->istack.push(this->root);
		while (this->current != NULL)
		{
			this->istack.push(this->current);
			this->current = this->current->left;
		}
	}
	tar = this->istack.top();
	this->istack.pop();
	if (tar->right != NULL)
	{
		this->current = tar->right;
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
	return tar->value;
	/* code end */
}

#endif /* BT_CPP */
