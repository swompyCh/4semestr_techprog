#ifndef ROUTE_H
#define ROUTE_H

#include <string>

/// @brief Класс маршрута
class Route {
private:
    int _numberRoute; // Номер маршрута
    static int _nextRouteNumber; // Статический член для автоматической нумерации
    std::string _departurePoint; // Пункт отправления
    std::string _arrivalPoint; // Пункт прибытия
    int _kilometers; // Расстояние маршрута

public:
    // Конструктор класса маршрута
    // departurePoint пункт отправления
    // arrivalPoint пункт прибытия
    // distanceCoefficient коэффициент расстояния
    Route(const std::string& departurePoint, const std::string& arrivalPoint);

    // Метод для извлечения расстояния маршрута

    int GetKilometers() const;

    // Метод для извлечения номера маршрута
    int GetRouteNumber() const;

    // Метод для отображения информации о маршруте
    void PrintRoute() const;
};

#endif