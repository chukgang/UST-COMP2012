//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

template<class T>
int treeHeight(BtreeNode<T> *root);

template<class T>
int countNodes(BtreeNode<T> *root);

template<class T>
void printLevelOrder(BtreeNode<T> *root);

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root);

template<class T>
bool isComplete(BtreeNode<T> *root);

#include "BTreeExercises.cpp"

#endif //LAB9_BTREEEXERCISES_H
