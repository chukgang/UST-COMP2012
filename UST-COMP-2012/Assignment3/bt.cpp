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
}

/* TODO:
 * Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BT<T,K>::iterator_end()
{
     //write your codes here
}

/* TODO:
 * Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BT<T,K>::iterator_next()
{
    //write your codes here
}

#endif /* BT_CPP */
