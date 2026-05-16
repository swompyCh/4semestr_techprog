#ifndef TAXI_H
#define TAXI_H

#include "CharterTransport.h"

/// @brief Класс такси - наследник класса заказного транспорта
class Taxi : public CharterTransport {
public:
    // Конструктор класса такси
    Taxi(std::string driverName, std::string carNumber, Route& route);

    // Метод для рассчета стоимости проезда
    void CalculateFare() override;
    
    // Метод для вывода информации о такси
    void PrintTransportInfo() const override;
};

#endif