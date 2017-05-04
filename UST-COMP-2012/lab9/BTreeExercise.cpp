#include "BTreeExercises.h"

#include <stdarg.h>
#include <queue>

using namespace std;

int max(int n, ...)
{
	va_list arguments;
	va_start(arguments, n);
	int max = va_arg(arguments, int);
	for (int i = 1; i != n; i++)
	{
		int arg = va_arg(arguments, int);
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
		return 0;
	}
	return max(2, treeHeight(root->left), treeHeight(root->right)) + 1;
}

template<class T>
int countNodes(BtreeNode<T> *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
}

template<class T>
void printLevelOrder(BtreeNode<T> *root)
{
	queue<BtreeNode<T>*> bin;

}
