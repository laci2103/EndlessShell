cmake_minimum_required(VERSION 3.6)
project(EndlessShell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c shell.c shell.h lib/crypto/crypto.c lib/crypto/crypto.h tests/StrUtil.c tests/AllTests.c tests/AllTests.h tests/CuTest.c tests/CuTest.h)
add_executable(EndlessShell ${SOURCE_FILES})