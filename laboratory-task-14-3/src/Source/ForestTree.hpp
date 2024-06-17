#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP

#include "Tree.hpp"

class ForestTree : public Tree
{
private:
    size_t woodAmount;

public:
    ForestTree();
    ForestTree(const std::string&, const size_t, const TreeType, const size_t);
    ForestTree(const ForestTree&);
    ForestTree(ForestTree&&);

    ~ForestTree(){}

    virtual void print() override;

};

#endif