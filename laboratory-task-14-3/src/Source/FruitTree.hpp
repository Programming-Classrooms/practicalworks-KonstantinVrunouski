#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP

#include "Tree.hpp"

class FruitTree : public Tree
{
private:
    size_t harvestAmount;
    size_t storageTime;

public:
    FruitTree();
    FruitTree(const std::string&, const size_t, const TreeType, const size_t, const size_t);
    FruitTree(const FruitTree&);
    FruitTree(FruitTree&&);

    ~FruitTree(){}

    virtual void print() override;

};

#endif