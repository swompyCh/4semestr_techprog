#include "TransportCalculator.h"   
#include <iostream>                

void TransportCalculator::addTransport(std::unique_ptr<Transport> transport) {
    // Метод добавляет транспорт в калькулятор
    // std::unique_ptr<Transport> - умный указатель на объект Transport
    // transport передаётся по значению, владение перемещается внутрь метода
    
    if (transport) {               // Проверяем, что указатель не пустой (транспорт существует)
        transport->CalculateFare();    // Вызываем виртуальный метод расчёта стоимости
        // Стрелка -> означает разыменование указателя и вызов метода
        // CalculateFare() у каждого транспорта свой (автобус считает 10*км, такси 15*км)
        
        transports.push_back(std::move(transport));
        // push_back - добавляем элемент в конец вектора
        // std::move(transport) - преобразуем в ссылку на временный объект
        // Это нужно, чтобы "переместить" владение указателем в вектор
        // После move transport становится пустым (nullptr)
    }
}

int TransportCalculator::calculateTotalFare() const {
    // const в конце означает, что метод не меняет объект
    // int - возвращаем целое число (сумму в рублях)
    
    int total = 0;                 // Переменная для накопления общей суммы
    for (const auto& t : transports) {   // Диапазонный for - перебираем все элементы вектора
        // const auto& t - константная ссылка на текущий элемент вектора
        // auto - компилятор сам определит тип (std::unique_ptr<Transport>)
        // & - ссылка, чтобы не копировать указатель
        
        total += t->GetFare();     // Добавляем стоимость текущего транспорта к общей сумме
        // t->GetFare() - через указатель вызываем метод получения стоимости
    }
    return total;                  // Возвращаем общую сумму
}

void TransportCalculator::printAllInfo() const {
    // Метод выводит информацию о всех поездках на экран
    
    for (const auto& t : transports) {   // Перебираем все элементы вектора
        t->PrintTransportInfo();         // Вызываем виртуальный метод вывода информации
        // У автобуса выведет "Автобус №...", у такси добавит имя водителя и номер машины
        
        std::cout << "-------------------" << std::endl;
        // Выводим разделитель между разными видами транспорта
        // std::endl - переводит строку и сбрасывает буфер вывода
    }
}

void TransportCalculator::clear() {
    transports.clear();            // Очищаем вектор
    // clear() удаляет все элементы вектора
    // Умные указатели unique_ptr автоматически вызовут деструкторы объектов
}

size_t TransportCalculator::getCount() const {
    return transports.size();      // size() возвращает количество элементов в векторе
    // size_t - тип, который возвращает size() (обычно unsigned int)
}