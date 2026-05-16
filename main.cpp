#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include "Route.h"
#include "RouteManager.h"
#include "TransportCalculator.h"
#include "TransportFactory.h"

// Функция для выбора маршрута пользователем
Route* selectRoute(RouteManager& routeManager) {
    if (routeManager.getRoutesCount() == 0) {
        std::cout << "Нет доступных маршрутов!\n";
        return nullptr;
    }
    
    std::cout << "\n=== Доступные маршруты ===\n";
    routeManager.displayAllRoutes();
    
    int choice;
    std::cout << "\nВыберите номер маршрута: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choice < 1 || choice > routeManager.getRoutesCount()) {
        std::cout << "Ошибка! Неверный номер маршрута.\n";
        return nullptr;
    }
    
    return routeManager.getRouteForEditing(choice - 1);
}

// Функция для выбора типа транспорта
int selectTransportType() {
    std::cout << "\n=== Выберите тип транспорта ===\n";
    std::cout << "1. Автобус (10 руб/км)\n";
    std::cout << "2. Трамвай (5 руб/км)\n";
    std::cout << "3. Такси (15 руб/км)\n";
    
    int choice;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (choice < 1 || choice > 3) {
        std::cout << "Ошибка! Выберите 1, 2 или 3.\n";
        return 1; // Возвращаем значение по умолчанию
    }
    
    return choice;
}

// Функция для создания транспорта на основе выбора пользователя
std::unique_ptr<Transport> createTransportByType(int type, Route& route) {
    BusCreator busFactory;
    TramCreator tramFactory;
    TaxiCreator taxiFactory;
    
    switch (type) {
        case 1:
            std::cout << "Вы выбрали автобус.\n";
            return busFactory.createTransport(route);
        case 2:
            std::cout << "Вы выбрали трамвай.\n";
            return tramFactory.createTransport(route);
        case 3: {
            std::cout << "Вы выбрали такси.\n";
            std::string driverName, carNumber;
            std::cout << "Введите имя водителя: ";
            std::getline(std::cin, driverName);
            std::cout << "Введите номер машины: ";
            std::getline(std::cin, carNumber);
            return taxiFactory.createTaxi(route, driverName, carNumber);
        }
        default:
            return nullptr;
    }
}

// Функция для отображения главного меню
void displayMainMenu() {
    std::cout << "\n=== ТРАНСПОРТНАЯ СИСТЕМА ===\n";
    std::cout << "1. Добавить поездку\n";
    std::cout << "2. Показать все поездки\n";
    std::cout << "3. Показать общую стоимость\n";
    std::cout << "4. Выйти\n";
}

int main() {
    RouteManager routeManager;
    TransportCalculator calculator;
    
    // Добавляем несколько маршрутов по умолчанию
    routeManager.addRoute(std::make_unique<Route>("пл. Батенькова", "пл. Ленина"));
    routeManager.addRoute(std::make_unique<Route>("Томск", "Кемерово"));
    routeManager.addRoute(std::make_unique<Route>("Аэропорт", "Ж/д вокзал"));
    routeManager.addRoute(std::make_unique<Route>("Университет", "Центральный рынок"));
    
    int choice;
    do {
        displayMainMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: {  // Добавить поездку
                Route* selectedRoute = selectRoute(routeManager);
                if (selectedRoute) {
                    int transportType = selectTransportType();
                    auto transport = createTransportByType(transportType, *selectedRoute);
                    if (transport) {
                        calculator.addTransport(std::move(transport));
                        std::cout << "\nПоездка успешно добавлена!\n";
                    } else {
                        std::cout << "\nОшибка создания транспорта!\n";
                    }
                }
                break;
            }
            
            case 2: {  // Показать все поездки
                if (calculator.getCount() == 0) {
                    std::cout << "Нет добавленных поездок.\n";
                } else {
                    std::cout << "=== СПИСОК ВСЕХ ПОЕЗДОК ===\n\n";
                    calculator.printAllInfo();
                }
                break;
            }
            
            case 3: {  // Показать общую стоимость
                std::cout << "=== ОБЩАЯ СТОИМОСТЬ ===\n";
                std::cout << "Количество поездок: " << calculator.getCount() << "\n";
                std::cout << "Общая стоимость: " << calculator.calculateTotalFare() << " руб.\n";
                break;
            }
            
            case 4:  // Выйти
                break;
                
            default:
                std::cout << "Ошибка! Выберите действие от 1 до 4.\n";
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}