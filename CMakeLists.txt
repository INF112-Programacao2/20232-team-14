cmake_minimum_required(VERSION 3.14)
project(20232_team_14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE PROJ_FILES "src/*.cpp" "src/*.c" "src/*.h" "src/*.hpp")
add_executable(20232_team_14 ${PROJ_FILES}
        src/model/Moto.cpp
        src/model/Moto.h
        src/model/Caminhao.cpp
        src/model/Caminhao.h
        src/model/Moto.cpp
        src/exceptions/abortFunctionException.cpp
        src/exceptions/abortFunctionException.h
        src/exceptions/deLoreanException.cpp
        src/exceptions/deLoreanException.h
        src/exceptions/steinsGateException.cpp
        src/exceptions/steinsGateException.h
)

target_include_directories(20232_team_14 PRIVATE src)
