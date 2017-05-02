//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"
using namespace std;

template<class T>
int treeHeight(BtreeNode<T> *root){
	int leftHeight;
	int rightHeight;
	if(root->get_left() == 0){
		leftHeight = -1;
	}else{
		leftHeight = treeHeight(root->get_left());
	}
	if(root->get_right() == 0){
		rightHeight = -1;
	}else{
		rightHeight = treeHeight(root->get_right());
	}
	if(leftHeight == -1 && rightHeight == -1){
		return 0;
	}else if(leftHeight > rightHeight){
		return leftHeight + 1;
	}else{
		return rightHeight + 1;
	}
}

template<class T>
int countNodes(BtreeNode<T> *root){
	int leftNode;
	int rightNode;
	if(root->get_left() == 0){
		leftNode = -1;
	}else{
		leftNode = countNodes(root->get_left());
	}
	if(root->get_right() == 0){
		rightNode = -1;
	}else{
		rightNode = countNodes(root->get_right());
	}
	if(leftNode == -1 && rightNode == -1){
		return 1;
	}else{
		return leftNode + rightNode + 1;
	}
}

template<class T>
void printLevelOrder(BtreeNode<T> *root){
	queue<BtreeNode<T>*> order;
	order.push(root);
	if(!root->get_left() == 0){
		order.push(root->get_left());
	}
	if(!root->get_right() == 0){
		order.push(root->get_right());
	}
	cout << order.front()->get_data();
	order.pop();
	while(!order.empty()){
		cout << " " << order.front()->get_data();		
		if(!order.front()->get_left() == 0){
			order.push(order.front()->get_left());
		}
		if(!order.front()->get_right() == 0){
			order.push(order.front()->get_right());
		}
		order.pop();
	}
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){
	BtreeNode<int> *mirrorTreeLeft = 0;
	BtreeNode<int> *mirrorTreeRight = 0;
	if(!root->get_left() == 0){
		mirrorTreeLeft = mirror(root->get_left());
	}
	if(!root->get_right() == 0){
		mirrorTreeRight = mirror(root->get_right());
	}
	BtreeNode<int> *mirrorTree = new BtreeNode<int>(root->get_data(), mirrorTreeRight, mirrorTreeLeft);
	return mirrorTree;
}

template<class T>
bool isComplete(BtreeNode<T> *root){
	if(!root->get_left() == 0){
		return isComplete(root->get_left());
	}else if(!root->get_right() == 0){
		return false;
	}else{
		return true;
	}
}

#endif //LAB9_BTREEEXERCISES_H
