cmake_minimum_required(VERSION 3.30)
project(Trie C)

set(CMAKE_C_STANDARD 11)

add_executable(Trie main.c
        Dict.c
        Dict.h)
