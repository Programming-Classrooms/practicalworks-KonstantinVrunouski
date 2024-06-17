#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

enum class TreeType {Pine, Leaf};

class Tree
{
protected:
    std::string name;
    size_t age;
    TreeType type;
public:
    Tree();
    Tree(const std::string&, const size_t, const TreeType);
    Tree(const Tree&);
    Tree(Tree&&);

    std::string getName();
    size_t getAge();
    TreeType getType();

    virtual ~Tree(){}

    virtual void print() = 0;
};

#endif