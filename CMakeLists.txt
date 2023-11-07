cmake_minimum_required(VERSION 3.14)
project(20232_team_14)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE PROJ_FILES "src/*.cpp" "src/*.c" "src/*.h" "src/*.hpp")
add_executable(20232_team_14 ${PROJ_FILES}
        src/model/Moto.cpp
        src/model/Moto.h
        src/model/Caminhao.cpp
        src/model/Caminhao.h)

find_package(SQLite3 REQUIRED)
target_include_directories(20232_team_14 PRIVATE ${SQLite3_INCLUDE_DIRS} src)
target_link_libraries(20232_team_14 ${SQLite3_LIBRARIES})