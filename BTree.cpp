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

template<typename T, typename K>
bool BTree<T,K>::insert(K key, T* data, bool updateValue = false) {
    return btInsert(key, &root, data, updateValue);
}

template<typename T, typename K>
bool BTree<T,K>::btInsert(K key, btNode** leaf, T* data, bool uV) {
    if (*leaf == NULL){
        *leaf = (btNode*)malloc(nSize);
        if(!*leaf) {return false;}
        (*leaf)->key = key;
        (*leaf)->left = (*leaf)->right = NULL;
        (*leaf)->data = malloc(tSize);
        if((*leaf)->data) {
            memcpy((*leaf)->data, data, tSize);
            return true;
        } else {
            return false;
        }

    }
    if(key == (*leaf)->key) {
        if(uV) {
            //posso fazer o update da data
            memcpy((*leaf)->data, data, tSize);
            return true;
        } else {
            return false; //
        }
    }
    if(key < (*leaf)->key) {
        //a chave vai estar do lado esquerdo da árvore
        return btInsert(key, &(*leaf)->left, data, uV);
    }
    //a chave vai estar do lado direito da árvore.
    return btInsert(key, &(*leaf)->right, data, uV);
}

template<typename T, typename K>
T* BTree<T, K>::search(K key){
    return btSearch(key, root);
}
template<typename T, typename K>
T* BTree<T, K>::btSearch(K key, btNode* leaf) {
    if(leaf) {
        if(leaf->key == key) {
            return (T*)leaf->data;
        }
        if (key < leaf->key) {
            return btSearch(key, leaf->left);
        } else {
            return btSearch(key, leaf->right);
        }
    } else {
        return NULL;
    }
}
template<typename T, typename K>
size_t BTree<T, K>::count() {
    return btCount(root);
}
template<typename T, typename K>
size_t BTree<T, K>::btCount(btNode* leaf) {
    if (leaf) {
        return 1 + btCount(leaf->left) + btCount(leaf->right);
    }
    return 0;
}


