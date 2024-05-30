#ifndef BUSTRACK_HPP
#define BUSTRACK_HPP


#include <iostream>
#include <string>


class BusRoute
{
private:
    size_t routeNumber;
    std::string driver;
    size_t busNumber;
    std::string brand;
public:
    //Конструктор по умолчанию
    BusRoute();
    
    //Конструктор по аргументам
    BusRoute(
        size_t newRouteNumber, 
        const std::string& newDriver, 
        size_t newBusNumber,
        const std::string& newBrand);
    
    //Конструктор копирования
    BusRoute(const BusRoute& origin);
    
    //Конструктор перемещения
    BusRoute(BusRoute&& origin);

    //Деструктор
    ~BusRoute() = default;

    //Оператор присваивания
    BusRoute& operator=(const BusRoute& rhs);

    //Гетеры
    size_t getRouteNumber() const;
    std::string getDriver() const;
    size_t getBusNumber() const;
    std::string getBrand() const;    

    //Сетеры
    void setTrackNumber(size_t newRouteNumber);
    void setDriver(const std::string& newDriver);
    void setBusNumber(size_t newBusNumber);
    void setBrand(const std::string& newBrand);
};


#endif