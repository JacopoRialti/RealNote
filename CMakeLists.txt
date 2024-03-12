cmake_minimum_required(VERSION 3.22)
project(RealNote)

set(CMAKE_CXX_STANDARD 14)

add_executable(RealNote
        main.cpp
        Subject.h
        Observer.h
        Note.cpp
        Note.h
        Collection.cpp
        Collection.h
        Starred.cpp
        Starred.h
        GoogleTest/NoteTest.cpp
)

add_subdirectory(GoogleTest)

