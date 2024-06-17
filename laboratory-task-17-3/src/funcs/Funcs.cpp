#include "Funcs.hpp"


bool checkFile(std::ifstream & in)
{
    if (!in.good()) {
		throw std::invalid_argument("File is not good !!!");
	}
	if (!in) {
		throw std::ios_base::failure("File is bad !!!");
	}
	if (in.peek() == EOF) { 
		throw std::runtime_error("File is empty !!!");
	}
	return true;
}

void readFile(std::set<std::string>& mySet,std::ifstream& in)
{
    std::string word;
    while(in >> word)
    {
        mySet.insert(word);
    }

}

void printFish(const std::set<std::string>& mySet)
{
    std::cout << "\nУлов рыбака: ";
    for(const auto& elem: mySet)
    {
        std::cout << elem << " ";
    }
}

void fishEveryone(const std::set<std::string>& f1, const std::set<std::string>& f2, const std::set<std::string>& f3)
{
    std::set<std::string> intersect;
    set_intersection(f1.begin(), f1.end(), f2.begin(), f2.end(),std::inserter(intersect, intersect.begin()));
    set_intersection(intersect.begin(), intersect.end(), f3.begin(), f3.end(),std::inserter(intersect, intersect.begin()));
    if(!intersect.empty())
    {
        std::cout << "\nВиды рыб которые есть у каждого рыбака: ";
        for(std::string elem: intersect)
        {
            std::cout << elem << " ";
        }
    }
    else
    {
        std::cout << "\nУ всех рыбаков разные виды рыб";
    }
}

void fishInAll(const std::set<std::string>& f1, const std::set<std::string>& f2, const std::set<std::string>& f3)
{
    std::set<std::string> intersect;
    set_union(f1.begin(), f1.end(), f2.begin(), f2.end(),std::inserter(intersect, intersect.begin()));
    set_union(intersect.begin(), intersect.end(), f3.begin(), f3.end(),std::inserter(intersect, intersect.begin()));
    if(!intersect.empty())
    {
        std::cout << "\nВиды рыб которые есть хотя бы у одного рыбака: ";
        for(std::string elem: intersect)
        {
            std::cout << elem << " ";
        }
    }
    else
    {
        std::cout << "\nВсе рыбаки без рыб(((";
    }
}

void uniqueFish(const std::set<std::string>& fishAll, const std::set<std::string>& f1, const std::set<std::string>& f2, const std::set<std::string>& f3)
{
    std::set<std::string> intersect;
    set_union(f1.begin(), f1.end(), f2.begin(), f2.end(),std::inserter(intersect, intersect.begin()));
    set_union(intersect.begin(), intersect.end(), f3.begin(), f3.end(),std::inserter(intersect, intersect.begin()));
    std::set<std::string> result;
    set_difference(fishAll.begin(),fishAll.end(), intersect.begin(), intersect.end(),std::inserter(result,result.begin()));
    if(!result.empty())
    {
        std::cout << "\nВиды рыб которых не поймали: ";
        for(std::string elem: result)
        {
            std::cout << elem << " ";
        }              
    }
    else
    {
        std::cout << "\nПоймали всех рыбок(((";
    }
}
