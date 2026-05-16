#ifndef ROUTEMANAGER_H    
#define ROUTEMANAGER_H     


#include <vector>          
#include <memory>          
#include "Route.h"         

class RouteManager {       // Объявление класса - менеджера маршрутов
private:                   
    std::vector<std::unique_ptr<Route>> _routes;
    // Вектор умных указателей на объекты Route
    // std::vector - шаблонный класс, умеет динамически расширяться
    // std::unique_ptr<Route> - умный указатель, который владеет объектом Route
    // _routes - хранилище всех маршрутов в программе
    // Подчёркивание в начале _routes - это стиль именования (обычно так называют поля класса)
    
public:                    
    
    void addRoute(std::unique_ptr<Route> route);
    // Метод для добавления нового маршрута
    // Параметр принимает умный указатель по значению (владение передаётся в метод)
    
    const Route* getRoute(int index) const;
    // Получить маршрут по индексу (только для чтения)
    // const Route* - указатель на константный Route (нельзя менять маршрут)
    // int index - номер маршрута в списке (начиная с 0)
    // const в конце - метод гарантирует, что не изменит объект RouteManager
    
    int getRoutesCount() const;
    // Получить количество маршрутов
    // int - возвращает целое число
    // const - метод не меняет объект
    
    void displayAllRoutes() const;
    // Вывести на экран все маршруты с нумерацией
    // const - метод не меняет объект
    
    Route* getRouteForEditing(int index);
    // Получить маршрут по индексу (можно редактировать)
    // Route* - указатель на неконстантный Route (можно менять данные маршрута)
    // Отличие от getRoute: этот возвращает указатель без const
};

#endif     