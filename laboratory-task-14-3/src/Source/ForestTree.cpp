#include "ForestTree.hpp"

ForestTree::ForestTree() : Tree(), woodAmount(0)
{}

ForestTree::ForestTree(const std::string& newName, 
                       const size_t newAge, 
                       const TreeType newType, 
                       const size_t newWood) : Tree(newName, newAge, newType), woodAmount(newWood) 
{}

ForestTree::ForestTree(const ForestTree& rhs) : Tree(rhs), woodAmount(rhs.woodAmount)
{}

ForestTree::ForestTree(ForestTree&& rhs) : ForestTree(rhs)
{
    std::swap(woodAmount, rhs.woodAmount);
}

void ForestTree::print()
{
    std::cout << "Name: " << name;
    std::cout << "\nAge: " << age;
    if (type == TreeType::Leaf)
    {
        std::cout << "\nType: Leaf";
    }
    else
    {
        std::cout << "\nType: Pine";
    }
    std::cout << "\nWood amount: " << woodAmount << '\n';
}