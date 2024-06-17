#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include "../Source/Tree.hpp"
#include "../Source/ForestTree.hpp"
#include "../Source/FruitTree.hpp"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

class MyVector {
private:
    std::vector<Tree*> trees;
public:
    MyVector(size_t = 0);

    size_t getSize() const;

    void push(Tree*);

    void printTrees(std::ostream&) const;

    int32_t countTreesType(TreeType) const;

    int32_t  countTreesKind(Tree*) const;

    bool compareTrees(Tree*, Tree*);

    void sortTrees();

    void readFromFile(std::ifstream&);
};

#endif