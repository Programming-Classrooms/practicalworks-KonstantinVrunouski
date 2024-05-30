#include "BusRoute.hpp"

BusRoute::BusRoute() : 
    routeNumber(1),
    driver(std::string("Driver")),
    busNumber(1),
    brand(std::string("Brand"))
{}

BusRoute::BusRoute(
    size_t newRouteNumber, 
    const std::string &newDriver, 
    size_t newBusNumber, 
    const std::string &newBrand)
{
    if (newRouteNumber == 0 || newRouteNumber > 250)
    {
        throw std::invalid_argument("Invalid track number.");
    }
    if (newDriver.empty())
    {
        throw std::invalid_argument("Invalid driver.");
    }
    if (newBusNumber == 0 || newBusNumber > 1000)
    {
        throw std::invalid_argument("Invalid bus number.");
    }
    if (newBrand.empty())
    {
        throw std::invalid_argument("Invalid brand.");
    }

    routeNumber = newRouteNumber;
    driver = newDriver;
    busNumber = newBusNumber;
    brand = newBrand;
}

BusRoute::BusRoute(const BusRoute &origin) : 
    routeNumber(origin.routeNumber),
    driver(origin.driver),
    busNumber(origin.busNumber),
    brand(origin.brand)
{}

BusRoute::BusRoute(BusRoute &&origin) : 
    routeNumber(1),
    driver(std::string("Driver")),
    busNumber(1),
    brand(std::string("Brand"))
{
    std::swap(routeNumber, origin.routeNumber);
    std::swap(driver, origin.driver);
    std::swap(busNumber, origin.busNumber);
    std::swap(brand, origin.brand);
}

BusRoute &BusRoute::operator=(const BusRoute &rhs)
{
    if (this != &rhs)
    {
        routeNumber = rhs.routeNumber;
        driver = rhs.driver;
        busNumber = rhs.busNumber;
        brand = rhs.busNumber;
    }

    return *this;
}

size_t BusRoute::getRouteNumber() const
{
    return routeNumber;
}

std::string BusRoute::getDriver() const
{
    return driver;
}

size_t BusRoute::getBusNumber() const
{
    return busNumber;
}

std::string BusRoute::getBrand() const
{
    return brand;
}

void BusRoute::setTrackNumber(size_t newRouteNumber)
{
    if (newRouteNumber == 0 || newRouteNumber > 250)
    {
        throw std::invalid_argument("Invalid route number.");
    }

    routeNumber = newRouteNumber;
}

void BusRoute::setDriver(const std::string &newDriver)
{
    if (newDriver.empty())
    {
        throw std::invalid_argument("Invalid driver.");
    }

    driver = newDriver;
}

void BusRoute::setBusNumber(size_t newBusNumber)
{
    if (newBusNumber == 0 || newBusNumber > 1000)
    {
        throw std::invalid_argument("Invalid bus number.");
    }

    busNumber = newBusNumber;
}

void BusRoute::setBrand(const std::string &newBrand)
{
    if (newBrand.empty())
    {
        throw std::invalid_argument("Invalid driver.");
    }

    brand = newBrand;
}
