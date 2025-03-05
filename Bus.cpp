#include <iostream>
#include "Bus.h"

// Конструктор класса автобуса
Bus::Bus(Route& route) : PublicTransport(10, route) {}
/// @brief Метод для рассчета стоимости поездки
void Bus::CalculateFare(){
    Transport::_fare = _farePerKilometer * _route.GetKilometers();
}
/// @brief Метод для вывода информации об автобусе
void Bus::PrintTransportInfo() const {
    std::cout << "Автобус №"<< _route.GetRouteNumber() << " (ID транспорта: " << Transport::_id << ")" << std::endl;
    _route.PrintRoute();
    std::cout << "Стоимость проезда: " << _fare << std::endl;
} 