enable_testing()

file(GLOB SOURCES "*.cpp" "../src/*.cpp" "../src/*.h")
add_executable(Tests ${SOURCES}
        CollectionTest.cpp
        StarredTest.cpp)

target_link_libraries(Tests GTest::gtest_main)