#include <iostream>
#include "Route.h"
#include "Bus.h"
#include "Tram.h"


int main() {
    Route route1("пл. Батенькова", "пл. Ленина");
    Route route2("Томск", "Кемерово"); 
    Bus bus1(route2);
    Tram tram1(route1);


    bus1.CalculateFare();
    tram1.CalculateFare();


    bus1.PrintTransportInfo();
    std::cout << std::endl;
    tram1.PrintTransportInfo();
    std::cout << std::endl;

    return 0;
}