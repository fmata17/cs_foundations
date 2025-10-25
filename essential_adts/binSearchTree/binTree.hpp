#pragma once
#include <iostream>
using namespace std;

template <typename Type>
class BinTree
{
public:
    BinTree() : root(nullptr), height(0) {} // BinTree constructor
    void printPreOrder(typename BinTree<Type>::BinNode *node) const;
    // TODO IMPLEMENT
    void printInOrder(typename BinTree<Type>::BinNode *node) const;
    void printPostOrder(typename BinTree<Type>::BinNode *node) const;
    void add(Type data, bool isLeft, typename BinTree<Type>::BinNode *node);

protected:
    struct BinNode
    {
        Type data{};
        BinNode *left{};
        BinNode *Right{};

        // BinNode constructors
        BinNode() = default;
        BinNode(Type val) : data(val), left(nullptr), right(nullptr) {}
    };
    BinNode *root;
    int height;
};

template <typename Type>
void BinTree<Type>::printPreOrder(typename BinTree<Type>::BinNode *node) const
{
    if (node != nullptr)
    {
        cout << node->data << " L-> ";
        printPreOrder(node->left);
        cout << " R-> ";
        printPreOrder(node->right);
        cout << endl;
    }
}
