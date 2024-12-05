cmake_minimum_required(VERSION 3.10)
project(PrintQueue)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp
    src/ArgumentParser.cpp
    src/FileReader.cpp
    src/Rule.cpp
    src/Update.cpp
)

set(HEADERS
    src/ArgumentParser.hpp
    src/FileReader.hpp
    src/Rule.hpp
    src/Update.hpp
    src/UpdateCounter.hpp
)

add_executable(PrintQueue ${SOURCES} ${HEADERS})
