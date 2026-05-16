#ifndef TRANSPORTCALCULATOR_H     
#define TRANSPORTCALCULATOR_H     

#include <vector>                 
#include <memory>                
#include "Transport.h"            
#include "Route.h"           

class TransportCalculator {       
private:           
    // Вектор умных указателей на транспорт
    // std::vector - динамический массив
    // std::unique_ptr - умный указатель, который сам удалит объект
    // Transport - базовый класс для всех видов транспорта               
    std::vector<std::unique_ptr<Transport>> transports;  
    
public:                          
    // Добавить транспорт в калькулятор
    void addTransport(std::unique_ptr<Transport> transport);  
    // Посчитать общую стоимость всех поездок (const - не меняет объект)
    int calculateTotalFare() const;      
    // Вывести информацию о всех поездках
    void printAllInfo() const;           
    // Очистить список всех поездок
    void clear();                        
    // Получить количество поездок (size_t - беззнаковый тип)
    size_t getCount() const;             
};

#endif 