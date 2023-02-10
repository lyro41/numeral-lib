# authors: Люпа Ростислав А.
# description: Библиотека для работы с системами счисления

cmake_minimum_required(VERSION 3.1)
project(numeral-lib 
        VERSION 0.1.0
        LANGUAGES C)
enable_language(C)
set(C_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(numeral numeral.h numeral.c)
