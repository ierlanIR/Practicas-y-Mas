cmake_minimum_required(VERSION 2.8)
project(Proyecto3 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRCS main.cpp)
add_executable(proyecto3 ${SRCS})
target_include_directories(proyecto3 PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/../include
)