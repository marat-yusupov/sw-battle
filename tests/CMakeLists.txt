cmake_minimum_required(VERSION 3.27)
project(sw_battle_tests)

## TODO: Разделить на POSITIVE и NEGATIVE, когда будут тесты для негативных сценариев
add_definitions(-DTEST_CASES_DIR="${CMAKE_SOURCE_DIR}/tests/cases/positive/")
add_definitions(-DEXPECTED_RESULTS_DIR="${CMAKE_SOURCE_DIR}/tests/cases/expected/")
add_definitions(-DEXECUTABLE_PATH="${CMAKE_SOURCE_DIR}/build/sw_battle")

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::GTest GTest::Main)
