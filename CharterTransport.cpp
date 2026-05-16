#include "CharterTransport.h"
#include <string>

// Конструктор класса заказного транспорта
CharterTransport::CharterTransport(int farePerKilometer, std::string driverName, std::string carNumber, Route& route) : Transport(farePerKilometer), _driverName(driverName), _carNumber(carNumber), _route(route) {}