#include <iostream>
#include "Taxi.h"

// Конструктор класса такси
Taxi::Taxi(std::string driverName, std::string carNumber, Route& route) : CharterTransport(15, driverName, carNumber, route) {}

// Метод для рассчета стоимости проезда
void Taxi::CalculateFare() {
    Transport::_fare = _farePerKilometer * _route.GetKilometers();
}

// Метод для вывода информации о такси
void Taxi::PrintTransportInfo() const {
    std::cout << "Такси: " << _route.GetRouteNumber() << " (ID транспорта: " << Transport::_id << ")" << std::endl;
    _route.PrintRoute();
    std::cout << "Номер машины: " << _carNumber << std::endl;
    std::cout << "Имя водителя: " << _driverName << std::endl;
    std::cout << "Стоимость поездки: " << _fare << std::endl;
}