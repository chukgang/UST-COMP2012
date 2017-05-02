#ifndef LAB9_PRINTBINARYTREE_H
#define LAB9_PRINTBINARYTREE_H

/*
 *      Adopted from: http://leetcode.com/2010/09/how-to-pretty-print-binary-tree.html
 */

#include "BtreeNode.h"
#include "BTreeExercises.h"
#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

// Convert an integer value to string
std::string intToString(int val) {
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
template<class T>
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel,
                   const std::deque<BtreeNode<T> *> &nodesQueue, std::ostream &out) {
    typename std::deque<BtreeNode<T> *>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {

        out << ((i == 0) ? std::setw(startLen - 1) : std::setw(nodeSpaceLen - 2)) << "" << ((*iter++) ? "/" : " ");

        out << std::setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << std::endl;
}

// Print the branches and node (eg, ___10___ )
template<class T>
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel,
                const std::deque<BtreeNode<T> *> &nodesQueue,
                std::ostream &out) {
    typename std::deque<BtreeNode<T> *>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << ""
            << ((*iter && (*iter)->get_left()) ? std::setfill('_') : std::setfill(' '));
        out << std::setw(branchLen + 2) << ((*iter) ? intToString((*iter)->get_data()) : "");
        out << ((*iter && (*iter)->get_right()) ? std::setfill('_') : std::setfill(' ')) << std::setw(branchLen) << ""
            << std::setfill(' ');
    }
    out << std::endl;
}

// Print the leaves only (just for the bottom row)
template<class T>
void
printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<BtreeNode<T> *> &nodesQueue,
            std::ostream &out) {
    typename std::deque<BtreeNode<T> *>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(indentSpace + 2) : std::setw(2 * level + 2))
            << ((*iter) ? intToString((*iter)->get_data()) : "");
    }
    out << std::endl;
}

// Pretty formatting of a binary tree to the output stream
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
template<class T>
void printTree(BtreeNode<T> *root, int level, int indentSpace, std::ostream &out) {
    int h = treeHeight(root)+1;
    int nodesInThisLevel = 1;

    int branchLen = 2 * ((int) pow(2.0, h) - 1) -
                    (3 - level) * (int) pow(2.0, h - 1);  // eq of the length of branch for each node of each level
    int nodeSpaceLen = 2 + (level + 1) * (int) pow(2.0,
                                                   h);  // distance between left neighbor node's right arm and right neighbor node's left arm
    int startLen = branchLen + (3 - level) +
                   indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

    std::deque<BtreeNode<T> *> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen / 2 - 1;
        nodeSpaceLen = nodeSpaceLen / 2 + 1;
        startLen = branchLen + (3 - level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
            BtreeNode<T> *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->get_left());
                nodesQueue.push_back(currNode->get_right());
            } else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

template<class T>
void printTree(BtreeNode<T> *root) {
    printTree(root, 1, 0, std::cout);
}

#endif //LAB9_PRINTBINARYTREE_H
