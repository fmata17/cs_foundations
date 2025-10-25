#include "binTree.hpp"

template <typename Type>
class BinSearchTree : protected BinTree<Type>
{
public:
    BinSearchTree() : BinTree() {}
    ~BinSearchTree();
};