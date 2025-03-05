#ifndef CHARTERTRANSPORT_H
#define CHARTERTRANSPORT_H
#include "Route.h"
#include "Transport.h"

/// @brief Класс заказного транспорта - наследник класса транспорта
class CharterTransport: public Transport {
protected:
    Route _route; // Маршрут
    std::string _driverName; // Имя водителя
    std::string _carNumber; // Номер машины

    // Конструктор класса заказного транспорта
    // farePerKilometer стоимость проезда за километр
    // driverName имя водителя
    // carNumber номер машины 
    // route маршрут
    CharterTransport(int farePerKilometer, std::string driverName, std::string carNumber, Route& route);
};

#endif