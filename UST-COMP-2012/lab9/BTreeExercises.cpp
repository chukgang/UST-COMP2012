#ifndef BTreeExercises_cpp
#define BTreeExercises_cpp

#include "BTreeExercises.h"

#include "BtreeNode.h"

#include <stdarg.h>
#include <queue>

using namespace std;

template <typename T>
int max(int n, ...)
{
	va_list arguments;
	va_start(arguments, n);
	int max = va_arg(arguments, T);
	for (int i = 1; i != n; i++)
	{
		int arg = va_arg(arguments, T);
		if (arg > max)
		{
			max = arg;
		}
	}
	va_end(arguments);
	return max;
}

template<class T>
int treeHeight(BtreeNode<T> *root)
{
	if (root == NULL)
	{
		return -1;
	}
	//return max(2, treeHeight(root->get_left()), treeHeight(root->get_right())) + 1;
	int left = treeHeight(root->get_left());
	int right = treeHeight(root->get_right());
	//return max(2, left, right) + 1;
	if (left > right)
	{
		return left + 1;
	}
	return right + 1;
}

template<class T>
int countNodes(BtreeNode<T> *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return countNodes(root->get_left()) + countNodes(root->get_right()) + 1;
}

template<class T>
void printLevelOrder(BtreeNode<T> *root)
{
	queue<BtreeNode<T>*> bin;
	bin.push(root);
	while (!bin.empty())
	{
		BtreeNode<T>* tar = bin.front();
		if (tar != NULL)
		{
			cout << tar->get_data() << " ";
			bin.push(tar->get_left());
			bin.push(tar->get_right());
		}
		bin.pop();
	}
}

template<class T>
BtreeNode<T>* mirror(BtreeNode<T> *root)
{
	BtreeNode<T>* tar = NULL;
	if (root == NULL)
	{
		return NULL;
	}
	tar = new BtreeNode<T>(root->get_data(), mirror(root->get_right()), mirror(root->get_left()));
	return tar;
}

template<class T>
bool isComplete(BtreeNode<T> *root)
{
	if (root == NULL)
	{
		return false;
	}
	return !(!isComplete(root->get_left()) && isComplete(root->get_right()));
}

#endif
