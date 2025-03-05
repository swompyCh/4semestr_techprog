cmake_minimum_required(VERSION 3.10.0)
project(lb3 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(lb3 Transport.cpp PublicTransport.cpp Bus.cpp Route.cpp Tram.cpp CharterTransport.cpp Taxi.cpp main.cpp)
