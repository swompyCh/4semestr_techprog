#include <iostream>
#include "Tram.h"

// Конструктор класса автобуса
Tram::Tram(Route& route) : PublicTransport(5, route) {}
/// @brief Метод для рассчета стоимости поездки
void Tram::CalculateFare(){
    Transport::_fare = _farePerKilometer * _route.GetKilometers();
}
/// @brief Метод для вывода информации об автобусе
void Tram::PrintTransportInfo() const {
    std::cout << "Трамвай №"<< _route.GetRouteNumber() << " (ID транспорта: " << Transport::_id << ")" << std::endl;
    _route.PrintRoute();
    std::cout << "Стоимость проезда: " << _fare << std::endl;
} 