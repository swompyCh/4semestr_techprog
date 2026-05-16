#include "TransportFactory.h"    
#include "Bus.h"                 
#include "Tram.h"                
#include "Taxi.h"                

// Реализация BusCreator 
std::unique_ptr<Transport> BusCreator::createTransport(Route& route) {
    // Метод создаёт автобус
    
    return std::make_unique<Bus>(route);
    // std::make_unique<Bus>(route) - создаёт умный указатель на новый объект Bus
    // Передаём в конструктор Bus ссылку на маршрут
    // make_unique автоматически выделяет память и возвращает unique_ptr
    // Возвращаемый unique_ptr<Transport> может быть преобразован к базовому классу
}

std::unique_ptr<Transport> BusCreator::createTaxi(Route& route, const std::string& driver, const std::string& carNum) {
    // Автобус не может создать такси - это логическое ограничение
    
    return nullptr; // Автобус не может стать такси
    // nullptr - нулевой указатель (ни на что не указывает)
    // При попытке использовать этот указатель программа упадёт (это нормально)
}

// Реализация TramCreator 
std::unique_ptr<Transport> TramCreator::createTransport(Route& route) {
    // Метод создаёт трамвай
    
    return std::make_unique<Tram>(route);
    // std::make_unique<Tram>(route) - создаёт умный указатель на новый объект Tram
    // В конструктор Tram передаётся ссылка на маршрут
}

std::unique_ptr<Transport> TramCreator::createTaxi(Route& route, const std::string& driver, const std::string& carNum) {
    // Трамвай тоже не может создать такси
    
    return nullptr;   // Трамвай тоже не может стать такси
}

//  Реализация TaxiCreator 
std::unique_ptr<Transport> TaxiCreator::createTransport(Route& route) {
    // Такси не может быть создано без водителя и номера машины
    
    return nullptr; // Такси требует доп. параметров
    // Поэтому этот метод возвращает nullptr (не поддерживается)
}

std::unique_ptr<Transport> TaxiCreator::createTaxi(Route& route, const std::string& driver, const std::string& carNum) {
    // Метод создаёт такси с водителем и номером машины
    
    return std::make_unique<Taxi>(driver, carNum, route);
    // std::make_unique<Taxi>(driver, carNum, route) - создаёт умный указатель на новый объект Taxi
    // В конструктор Taxi передаются:
    // driver - имя водителя 
    // carNum - номер машины 
    // route - ссылка на маршрут 
}