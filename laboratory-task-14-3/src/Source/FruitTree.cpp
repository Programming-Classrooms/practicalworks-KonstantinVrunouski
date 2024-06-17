#include "FruitTree.hpp"

FruitTree::FruitTree() : Tree(), harvestAmount(0), storageTime(0)
{}

FruitTree::FruitTree(const std::string& newName,
                     const size_t newAge, 
                     const TreeType newType, 
                     const size_t newHarvest, 
                     const size_t newStorage) : Tree(newName, newAge, newType), 
                                                harvestAmount(newHarvest),
                                                storageTime(newStorage)
{}

FruitTree::FruitTree(const FruitTree& rhs) : Tree(rhs), 
                                             harvestAmount(rhs.harvestAmount), 
                                             storageTime(rhs.storageTime)
{}

FruitTree::FruitTree(FruitTree&& rhs) : Tree(rhs)
{
    std::swap(harvestAmount, rhs.harvestAmount);
    std::swap(storageTime, rhs.storageTime);
}

void FruitTree::print()
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
    std::cout << "\nHarvest amount: " << harvestAmount;
    std::cout << "\nStorage time: " << storageTime << '\n';
}