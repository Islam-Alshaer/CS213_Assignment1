cmake_minimum_required(VERSION 3.27)
project(task_4___5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ourvolemachine

        ALU.cpp
        ALU.h
        CPU.cpp
        CPU.h
        CU.cpp
        CU.h
        Machine.cpp
        Machine.h
        main.cpp
        Memory.cpp
        Memory.h
        Register.cpp
        Register.h
        Test.cpp
        Test.h

)

include(FetchContent)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/heads/main.zip)

FetchContent_MakeAvailable(googletest)

add_executable(volemachineTest Test.h Test.cpp)

target_link_libraries(volemachineTest gtest gtest_main)
