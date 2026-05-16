#ifndef TRAM_H
#define TRAM_H

#include "PublicTransport.h"

/// @brief Класс трамвая - наследник класса общественного транспорта
class Tram : public PublicTransport {
public:
    // Конструктор класса трамвая
    Tram(Route& route);

    // Метод для рассчета стоимости поездки
    void CalculateFare() override;

    // Метод для вывода информации об автобусе
    void PrintTransportInfo() const override;
};

#endif