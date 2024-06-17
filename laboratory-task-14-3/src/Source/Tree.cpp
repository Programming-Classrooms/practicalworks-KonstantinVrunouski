#include "Tree.hpp"


Tree::Tree() : name("NaN"), age(0), type(TreeType::Pine)
{}

Tree::Tree(const std::string& newName, const size_t newAge, const TreeType newType) : name(newName),
                                                                                      age(newAge),
                                                                                      type(newType)
{}

Tree::Tree(const Tree& rhs) : name(rhs.name), age(rhs.age), type(rhs.type)
{}

Tree::Tree(Tree&& rhs)
{
    std::swap(name, rhs.name);
    std::swap(age, rhs.age);
    std::swap(type, rhs.type);
}

std::string Tree::getName()
{
    return name;
}

size_t Tree::getAge()
{
    return age;
}

TreeType Tree::getType()
{
    return type;
}