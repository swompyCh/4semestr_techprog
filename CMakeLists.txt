cmake_minimum_required(VERSION 3.10.0)
project(lb3 VERSION 0.1.0 LANGUAGES CXX)

set(SOURCES 
    Transport.cpp 
    PublicTransport.cpp 
    Bus.cpp 
    Route.cpp 
    RouteManager.cpp
    Tram.cpp 
    CharterTransport.cpp 
    Taxi.cpp 
    TransportFactory.cpp 
    TransportCalculator.cpp 
    main.cpp
)

add_executable(lb3 ${SOURCES})

target_compile_features(lb3 PRIVATE cxx_std_17)