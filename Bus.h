#ifndef BUS_H
#define BUS_H

#include "PublicTransport.h"

/// @brief Класс автобуса - наследник класса общественного транспорта
class Bus : public PublicTransport {
public:
    // Конструктор класса автобуса
    Bus(Route& route);

    // Метод для рассчета стоимости поездки
    void CalculateFare() override;

    // Метод для вывода информации об автобусе
    void PrintTransportInfo() const override;
};

#endif