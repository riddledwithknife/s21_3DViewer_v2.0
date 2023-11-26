cmake_minimum_required(VERSION 3.5)
project(3DViewerTest LANGUAGES CXX)

enable_testing()
find_package(GTest)

set(APP_TESTS
        s21_objparser_test.cc
        s21_transformation_test.cc
        tests.cc

        ../Model/s21_objparser.cc
        ../Model/s21_objparser.h
        ../Model/s21_transformation.cc
        ../Model/s21_transformation.h
)

add_executable(3DViewerTest ${APP_TESTS})

target_link_libraries(3DViewerTest PRIVATE GTest::GTest GTest::Main)

add_test(NAME 3DViewerTest COMMAND 3DViewerTest)