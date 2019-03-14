//
// Created by daniel on 13/03/19.
//

#ifndef BSTC_BTREE_H
#define BSTC_BTREE_H

#include <clocale>
#include <cstddef>

template<typename T, typename K>
class BTree {
public:
    using BTIter = bool(*)(K, T*);
    BTree();
    ~BTree();
    bool insert(K, T*, bool=false);
    size_t count();
    size_t height();
    T* search(K);
    void iterate(BTIter);
    bool isBalanced();
    void balanceTree();
private:
    struct btNode {
        K key;
        void* data;
        btNode* left;
        btNode* right;
    };
    btNode* root = NULL;
    size_t tSize, nSize;
    bool btInsert(K, btNode**, T*, bool);
    void btDelete(btNode*);
    size_t btCount(btNode*);
    size_t btHeight(btNode*);
    size_t btMax(size_t, size_t);
    T* btSearch(K, btNode*);
    void btIterate(btNode*, BTIter);
    bool btRepeat; //usado pelo btIterate
    void rightRotate(btNode**);
    void treeToVine(btNode**);
    void leftRotate(btNode**);
    void vineToTree(btNode**);
    void compress(btNode**, int);
    void rotateOrCompress(btNode**, int);
    void dswTreeBalance(btNode**);
};


#endif //BSTC_BTREE_H
