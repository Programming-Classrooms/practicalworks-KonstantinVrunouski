#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include "../BusRoute/BusRoute.hpp"


void transferToMap(std::queue<BusRoute>& busRoutes, std::map<std::string, BusRoute>& mapRoutes)
{
    if (busRoutes.empty())
    {
        throw std::invalid_argument("There are no bus routes");
    }

    BusRoute temp;
    std::pair<std::string, BusRoute> tempPair;
    while (!busRoutes.empty())
    {
        temp = busRoutes.front();
        tempPair.first = temp.getDriver();
        tempPair.second = temp;
        mapRoutes.insert(tempPair);
        busRoutes.pop();
    }
}

void printDriversByRouteNumber(std::map<std::string, BusRoute> mapRoutes, size_t routeNumber)
{
    if (routeNumber == 0 || routeNumber > 250)
    {
        throw std::invalid_argument("Invalid route number.");
    }

    for (const auto& tempPair : mapRoutes)
    {
        if (tempPair.second.getRouteNumber() == routeNumber)
        {
            std::cout << tempPair.first << '\n';
        }
    }
}

std::set<std::string> createAllBrandsSet(const std::map<std::string, BusRoute>& mapRoutes)
{
    std::set<std::string> temp;
    for (auto i : mapRoutes)
    {
        temp.insert(i.second.getBrand());
    }

    return temp;
}

void printDriversByBrand(const std::map<std::string, BusRoute>& mapRoutes)
{ 
    std::set<std::string> temp = createAllBrandsSet(mapRoutes); 
    for (auto i : temp)
    {
        std::cout << i << ":\n";
        for (auto j : mapRoutes)
        {
            if (i == j.second.getBrand())
            {
                std::cout << j.first << '\n';
            }
        }
    }
}

void deleteElement(std::map<std::string, BusRoute>& mapRoutes, const std::string& driver)
{
    if (driver.empty())
    {
        throw std::invalid_argument("There is no such driver.");
    }

    mapRoutes.erase(driver);
}

std::map<size_t, std::set<std::string> > createMapRoutesNumberBrands(
    const std::map<std::string, BusRoute>& mapRoutes)
{
    std::map<size_t, std::set<std::string> > routeNumberBrands;
    std::pair<size_t, std::set<std::string> > tempPair;

    std::map<size_t, std::set<std::string>>::iterator temp;

    for (auto i : mapRoutes)
    {
        tempPair.second.clear();
        tempPair.first = i.second.getRouteNumber();
        tempPair.second.insert(i.second.getBrand());
        temp = routeNumberBrands.find(tempPair.first);
        if (temp != routeNumberBrands.end())
        {
            temp->second.insert(i.second.getBrand());
        }
        else
        {
            routeNumberBrands.insert(tempPair);
        }
    }

    return routeNumberBrands;
}


int main()
{
    std::queue<BusRoute> busRoutes;
    
    std::ifstream in("src/files/input.txt");
    BusRoute temp;
    while (in >> temp)
    {
        busRoutes.push(temp);
    }
    in.close();

    std::map<std::string, BusRoute> mapRoutes;

    transferToMap(busRoutes, mapRoutes);

    size_t tempRouteNumber;
    std::cout << "Input route number:\n";
    std::cin >> tempRouteNumber;
    std::cout << "Drivers on that route:\n";
    printDriversByRouteNumber(mapRoutes, tempRouteNumber);

    std::cout << "\nAll drivers:\n";
    printDriversByBrand(mapRoutes);

    std::string tempDriver;
    std::cout << "\nInput driver to delete:\n";
    std::cin >> tempDriver;
    
    deleteElement(mapRoutes, tempDriver);

    std::map<size_t, std::set<std::string> > routeNumberBrands = createMapRoutesNumberBrands(mapRoutes);

    std::cout << "\nRoutes with buses of the one brand:\n";
    for (auto i : routeNumberBrands)
    {
        if (i.second.size() == 1)
        {
            std::cout << i.first << '\n';
        }
    }

    return 0;
}
