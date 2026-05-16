#ifndef PUBLICTRANSPORT_H
#define PUBLICTRANSPORT_H

#include "Transport.h"
#include "Route.h"

/// @brief Класс общественного транспорта - наследник класса транспорта
class PublicTransport : public Transport {
protected:
    Route _route; // Маршрут

    // Конструктор класса общественного транспорта
    PublicTransport(int farePerKilometer, Route& route);
};

#endif