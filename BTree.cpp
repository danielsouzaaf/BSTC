//
// Created by daniel on 13/03/19.
//

#include "BTree.h"

template<typename T, typename K>
BTree<T,K>::BTree() {
    tSize = sizeof(T);
    nSize = sizeof(btNode);
}

template<typename T, typename K>
BTree<T,K>::~BTree() {
    btDelete(root);
}
