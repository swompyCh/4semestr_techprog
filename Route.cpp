#include "Route.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

// Реализация конструктора класса маршрута
Route::Route(const std::string& departurePoint, const std::string& arrivalPoint)
    : _departurePoint(departurePoint), _arrivalPoint(arrivalPoint) {
    _numberRoute = _nextRouteNumber++;
    
    // Генерация случайного расстояния (1-100 км)
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(1, 100);
    _kilometers = dist(rng);
}

// Метод для извлечения расстояния маршрута
int Route::GetKilometers() const { 
    return _kilometers; 
}

// Метод для извлечения номера маршрута
int Route::GetRouteNumber() const { 
    return _numberRoute; 
}

// Метод для отображения информации о маршруте
void Route::PrintRoute() const {
    std::cout << _departurePoint << " -> " << _arrivalPoint << ": " << _kilometers << " км" << std::endl;
}

// Инициализация статического члена для нумерации маршрутов
int Route::_nextRouteNumber = 1;