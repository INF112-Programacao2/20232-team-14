cmake_minimum_required(VERSION 3.26)
project(20232_team_14)

set(CMAKE_CXX_STANDARD 14)


file(GLOB_RECURSE PROJ_FILES "src/*.cpp" "src/*.c" "src/*.h" "src/*.hpp")
add_executable(20232_team_14 ${PROJ_FILES})
target_include_directories(20232_team_14 PUBLIC src)