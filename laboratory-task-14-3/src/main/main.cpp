#include <iostream>
#include <fstream>
#include "../Source/MyVector.hpp"
#include "../Source/Tree.hpp"

int main() {
    MyVector container;
    std::ifstream file("src/files/trees.txt");
    container.readFromFile(file);

    container.printTrees(std::cout);

    std::cout << "Count of leaf trees: " << container.countTreesType(TreeType::Leaf) << std::endl;
    std::cout << "Count of pine trees: " << container.countTreesType(TreeType::Pine) << std::endl;
    std::cout << "Count of forest trees: " << container.countTreesKind(new ForestTree()) << std::endl;
    std::cout << "Count of fruit trees: " << container.countTreesKind(new FruitTree()) << std::endl;

    container.sortTrees();
    std::cout << "Sorted trees:" << std::endl;
    container.printTrees(std::cout);

    return 0;
}