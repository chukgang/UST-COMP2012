//
// Binary Tree Node Class.
// Should not be modified.
//

#ifndef LAB9_BTREE_NODE_H
#define LAB9_BTREE_NODE_H

template<class T>
class BtreeNode {
public:
    BtreeNode(const T &x, BtreeNode *L = 0, BtreeNode *R = 0) :
            data(x), left(L), right(R) {}

    ~BtreeNode() {
        delete left;
        delete right;
    }

    const T &get_data() const { return data; }

    BtreeNode *get_left() const { return left; }

    BtreeNode *get_right() const { return right; }



private:
    T data;
    BtreeNode *left;
    BtreeNode *right;
};

#endif //LAB9_BTREE_NODE_H
