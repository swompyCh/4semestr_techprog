#ifndef TRANSPORT_H
#define TRANSPORT_H

/// @brief Класс транспорта
class Transport {
protected:
    int _id; // айди транспорта
    static int _nextId; // Статический член для автоматической нумерации
    int _fare; // Стоимость проезда
    int _farePerKilometer;
public:
    // Коструктор класса транспорта
    Transport(int farePerKilometr);

    // Метод для рассчета стоимости проезда (будет переопределяться в классах-наследниках)
    virtual void CalculateFare();

    // Метод для извлечения стоимости проезда
    int GetFare() const;

    // Метод для отображения информации о транспорте
    virtual void PrintTransportInfo() const;
};

#endif