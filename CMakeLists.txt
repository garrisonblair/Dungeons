cmake_minimum_required(VERSION 3.6)
project(Dungeons)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Cell.cpp
    Cell.hpp
    Character.cpp
    Character.hpp
    Container.cpp
    Container.hpp
    Dice.cpp
    Dice.hpp
    Interaction.cpp
    Interaction.hpp
    Item.cpp
    Item.hpp
    main.cpp
    Map.cpp
    Map.hpp)

add_executable(Dungeons ${SOURCE_FILES})