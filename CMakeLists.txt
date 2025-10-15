cmake_minimum_required(VERSION 3.10)
project("ContactBookGroupProject")

set(PROJECT_SOURCES src/main.cpp
    src/CSVFileIO.h
    src/CSVFileIO.cpp
    src/Book.h
    src/Book.cpp
    src/Contact.h
    src/Contact.cpp
    src/MenuInterface.h
    src/MenuInterface.cpp)

add_executable(execBinary ${PROJECT_SOURCES})
