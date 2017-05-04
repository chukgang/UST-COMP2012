#include <iostream>
#include <vector>
#include "BtreeNode.h"
#include "BTreeExercises.h"
#include "BinarySearchTree.h"
#include "PrintBinaryTree.h"
using namespace std;

int main() {
    cout << "---Part1: Binary Tree---" << endl;
    vector<BtreeNode<int> *> trees;
    vector<string> testCaseNames;
    BtreeNode<int> *tree;

    // Tree 1
    tree = new BtreeNode<int>(2, new BtreeNode<int>(1));
    trees.push_back(tree);
    testCaseNames.push_back("Tree 1");

    // Tree 2
    tree = new BtreeNode<int>(2, new BtreeNode<int>(1), new BtreeNode<int>(3));
    trees.push_back(tree);
    testCaseNames.push_back("Tree 2");

    // Tree 3
    tree = new BtreeNode<int>(0, new BtreeNode<int>(1, NULL, new BtreeNode<int>(2)), new BtreeNode<int>(3));
    trees.push_back(tree);
    testCaseNames.push_back("Tree 3");

    for (int i = 0; i < trees.size(); i++) {
        cout << "# " << testCaseNames[i] << endl;
        printTree(trees[i]);
        cout << endl;

        cout << "Nodes: " << countNodes(trees[i]) << endl;
        cout << "Height: " << treeHeight(trees[i]) << endl;

        cout << "Level-order: ";
        printLevelOrder(trees[i]);
        cout << endl;



        BtreeNode<int>* mirror_tree = mirror(trees[i]);
        cout<< "Mirroring: ";
        printTree(mirror_tree);

        cout<<endl;
        delete mirror_tree;
    }

    // Is complete
    cout<< "---[Part 1 Optional] isComplete---"<<endl;
    for(int i = 0; i < trees.size(); i++){
        cout << "# " << testCaseNames[i] << endl;
        cout << "Is Complete: " << (isComplete(trees[i]) ? "Yes" : "No") << endl;
    }

    // Clean up
    for(int i = 0; i < trees.size(); i++){
        delete trees[i];
    }
    cout<<endl;
    cout << "---Part2: Binary Search Tree---" << endl;
    BinarySearchTree<int, float>* bst = new BinarySearchTree<int, float>();
    // minimum value in an empty bst
    bst->printMin();

    bst->insert(4,2.0);
    bst->insert(3,4.0);
    bst->insert(3,2.0);
    bst->insert(5, 3.5);
    bst->insert(6, 4.0);
    bst->insert(5, 4.0);

    bst->printTree();
    cout<<endl;
    std::cout << std::boolalpha;
    cout<<"Contains (3,4.0): "<<bst->contains(3,4.0)<<endl;
    cout<<"Contains (5,3.5): "<<bst->contains(5,3.5)<<endl;
    cout<<"Contains (5,2.0): "<<bst->contains(5, 2.0)<<endl;

    cout<<endl;
    bst->printMin();
    delete bst;
    return 0;
}