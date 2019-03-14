//
// Created by daniel on 13/03/19.
//

#include <cmath>
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
bool BTree<T,K>::insert(K key, T* data, bool updateValue) {
    return btInsert(key, &root, data, updateValue);
}

template<typename T, typename K>
bool BTree<T,K>::btInsert(K key, BTree<T, K>::btNode** leaf, T* data, bool uV) {
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
T* BTree<T, K>::btSearch(K key, BTree<T, K>::btNode* leaf) {
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
size_t BTree<T, K>::btCount(BTree<T, K>::btNode* leaf) {
    if (leaf) {
        return 1 + btCount(leaf->left) + btCount(leaf->right);
    }
    return 0;
}
template<typename T, typename K>
size_t BTree<T,K>::height() {
    return btHeight(root);
}
template<typename T, typename K>
size_t BTree<T,K>::btHeight(BTree<T, K>::btNode* leaf) {
    if (leaf) {
        return 1 + btMax(btHeight(leaf->left), btHeight(leaf->right));
    }
    return 0;
}
template<typename T, typename K>
size_t BTree<T,K>::btMax(size_t a, size_t b) {
    return (a <= b)?b:a;
}
template<typename T, typename K>
bool BTree<T,K>::isBalanced() {
    return btHeight(root) <= (int)log2(btCount(root)) + 1;
}
template<typename T, typename K>
void BTree<T,K>::btDelete(BTree<T, K>::btNode* leaf) {
    if(leaf) {
        btDelete(leaf->left);
        btDelete(leaf->right);
        free(leaf->data);
        free(leaf);
    }
}
template<typename T, typename K>
void BTree<T,K>::iterate(BTIter callback) {
    btRepeat = true;
    btIterate(root, callback);
}
template<typename T, typename K>
void BTree<T,K>::btIterate(BTree<T, K>::btNode* leaf, BTIter callback) {
    if(leaf && btRepeat) {
        btIterate(leaf->left, callback);
        if(btRepeat) {
            callback(leaf->key, (T *) leaf->data);
            btIterate(leaf->right, callback);
        }
    }
}
template<typename T, typename K>
void BTree<T,K>::rightRotate(BTree<T, K>::btNode** root) {
    btNode *oldLeft, *oldLeftRight;
    oldLeft = (*root)->left;
    oldLeftRight = oldLeft->right;
    oldLeft->right = *root;
    oldLeft->right->left = oldLeftRight;
    *root = oldLeft;
};
template<typename T, typename K>
void BTree<T,K>::treeToVine(BTree<T, K>::btNode** tree) {
    btNode* root = tree;
    if(!root) {
        return;
    }
    while(root->left) {
        rightRotate(&root);
    }
    if(root->right){
        treeToVine(&(root->right));
    }
    *tree = root;
}
template<typename T, typename K>
void BTree<T,K>::leftRotate(BTree<T, K>::btNode** root) {
    btNode *oldRight, *oldRightLeft;
    oldRight = (*root)->right;
    oldRightLeft = oldRight->left;
    oldRight->left = *root;
    oldRight->left->right = oldRightLeft;
    *root = oldRight;
};
/**
 * All binary trees start with one node at the root, then in a balanced tree the next level has two nodes, the next has 4 and so on. Each level, except perhaps the last, should contain a node count that is an increasing power of 2. Thus, given a vine with 9 nodes, we can calculate that the lowest level will have just 2 nodes (9 - (1 + 2 + 4)). So we left rotate the first two odd numbered nodes.
Then we left rotate all the odd numbered nodes from the new start point (key 7 in this case).
Then we do that again.
Which gives us a balanced tree with a height of 4.
 */
template<typename T, typename K>
void BTree<T,K>::vineToTree(BTree<T, K>::btNode** vine) {
    btNode *root = *vine;
    int n = (int) btCount(root);
    int M = (int) pow(2, floor(log2(n + 1))) - 1;
    compress(&root, n-M);
    while(M > 1) {
        M = (int) floor(M/2);
        compress(&root, M);
    }
    *vine = root;
}
template<typename T, typename K>
void BTree<T,K>::compress(BTree<T, K>::btNode **root, int times) {
    for (int i = 0; i < times; i++) {
        rotateOrCompress(&(*root), i);
    }
}
template<typename T, typename K>
void BTree<T,K>::rotateOrCompress(BTree<T, K>::btNode **root, int times) {
    if(times == 0) {
        leftRotate(&(*root));
    } else {
        rotateOrCompress(&((*root)->right), times - 1);
    }
}
template<typename T, typename K>
void BTree<T,K>::balanceTree() {
    dswTreeBalance(&root);
}
template<typename T, typename K>
void BTree<T,K>::dswTreeBalance(BTree<T, K>::btNode** rootP) {
    btNode *root = *rootP;
    treeToVine(&root);
    vineToTree(&root);
    *rootP = root;
}




