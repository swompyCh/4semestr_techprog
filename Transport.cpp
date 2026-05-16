#include "Transport.h"

// Коструктор класса транспорта
Transport::Transport(int farePerKilometer) : _farePerKilometer(farePerKilometer), _id(_nextId++) {}

// Метод для рассчета стоимости проезда (будет переопределяться в классах-наследниках)
void Transport::CalculateFare() {}

// Метод для извлечения стоимости проезда
int Transport::GetFare() const { return _fare; }

// Метод для отображения информации о транспорте
void Transport::PrintTransportInfo() const {}

// Инициализация статического члена для нумерации транспорта
int Transport::_nextId = 1;