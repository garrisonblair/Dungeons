cmake_minimum_required(VERSION 3.6)
project(Dungeons)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Cell.cpp
        Cell.h
    Character.cpp
        Character.h
    Container.cpp
        Container.h
    Dice.cpp
        Dice.h
        Item.cpp
        Item.h
    main.cpp
    Map.cpp
        Map.h Game.cpp Game.h Builder.cpp Builder.h Campaign.cpp Campaign.h Director.h)

add_executable(Dungeons ${SOURCE_FILES})