#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>


bool checkFile(std::ifstream &);

/* Записывает улов каждого рыбака из файла */
void readFile(std::set<std::string>&, std::ifstream&);

/* Демонстрация видов рыб каждого рыбака */
void printFish(const std::set<std::string>&);

/* Какие виды рыб есть у каждого рыбака */
void fishEveryone(const std::set<std::string>&, const std::set<std::string>&, const std::set<std::string>&);

/* Какие из видов выловид хотя бы один рыбак */
void fishInAll(const std::set<std::string>&, const std::set<std::string>&, const std::set<std::string>&);

/* Какие рыбы есть в озере, но не в улове любого из рыбаков Какие из видов выловид хотя бы один рыбак */
void uniqueFish(const std::set<std::string>&, const std::set<std::string>&, const std::set<std::string>&, const std::set<std::string>&);

#endif // Funcs.hpp


