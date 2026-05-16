#include "PublicTransport.h"

// Конструктор класса общественного транспорта
PublicTransport::PublicTransport(int farePerKilometer, Route& route) : Transport(farePerKilometer), _route(route) {}