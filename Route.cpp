#include "Route.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>


// Метод для извлечения расстояния маршрута
int Route::GetKilometers() const { return _kilometers; }

// Метод для извлечения номера маршрута
int Route::GetRouteNumber() const { return _numberRoute; }

// Метод для отображения информации о маршруте
void Route::PrintRoute() const {
    std::cout << _departurePoint << " -> " << _arrivalPoint << ": " << _kilometers << " км" << std::endl;
}

// Инициализация статического члена для нумерации маршрутов
int Route::_nextRouteNumber = 1;