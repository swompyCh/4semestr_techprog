#ifndef TRANSPORTFACTORY_H       
#define TRANSPORTFACTORY_H

#include <memory>                
#include <string>                
#include "Transport.h"           
#include "Route.h"               

// Абстрактный создатель (интерфейс)
// Это "чисто виртуальный" класс - нельзя создать его объект, только наследоваться
class TransportCreator {
public:
    virtual ~TransportCreator() = default;   // Виртуальный деструктор по умолчанию
    // virtual - метод может быть переопределён в наследниках
    // ~TransportCreator() - деструктор
    // = default - пусть компилятор сам сгенерирует реализацию
    
    virtual std::unique_ptr<Transport> createTransport(Route& route) = 0;
    // Чисто виртуальный метод создания обычного транспорта (автобус/трамвай)
    // = 0 означает, что у класса нет реализации этого метода
    // Наследники ОБЯЗАНЫ его переопределить
    // Route& route - ссылка на маршрут (не копируем, берём оригинал)
    
    virtual std::unique_ptr<Transport> createTaxi(Route& route, const std::string& driver, const std::string& carNum) = 0;
    // Чисто виртуальный метод создания такси с водителем и номером
    // const std::string& - константная ссылка на строку (не копируем, не меняем)
    // driver - имя водителя, carNum - номер машины
};

// Конкретный создатель для автобусов
class BusCreator : public TransportCreator {  // Наследуемся от TransportCreator
public:
    std::unique_ptr<Transport> createTransport(Route& route) override;
    // override - проверяет, что метод действительно переопределяет виртуальный метод родителя
    
    std::unique_ptr<Transport> createTaxi(Route& route, const std::string& driver, const std::string& carNum) override;
};

// Конкретный создатель для трамваев
class TramCreator : public TransportCreator {
public:
    std::unique_ptr<Transport> createTransport(Route& route) override;
    std::unique_ptr<Transport> createTaxi(Route& route, const std::string& driver, const std::string& carNum) override;
};

// Конкретный создатель для такси
class TaxiCreator : public TransportCreator {
public:
    std::unique_ptr<Transport> createTransport(Route& route) override;
    std::unique_ptr<Transport> createTaxi(Route& route, const std::string& driver, const std::string& carNum) override;
};

#endif