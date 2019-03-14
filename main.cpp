#include <iostream>

#include "BTree.h"

int main() {
    int keys[] = { 5, 3, 8, 2, 7, 6, 4, 9, 1 };

    auto *tree = new BTree<int, int>();
    for(int i = 0; i < 9; i++)
    {

        tree->insert(keys[i], keys);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}