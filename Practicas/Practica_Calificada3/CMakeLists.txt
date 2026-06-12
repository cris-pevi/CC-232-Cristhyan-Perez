cmake_minimum_required(VERSION 3.17)

project(Practica_Calificada_3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -O2)
endif()
 
include_directories(include)

add_executable(executable_programa
    src/main.cpp
    src/solution.cpp
    src/segment_treap.cpp
    src/treap.cpp
)

add_executable(executable_test_treap
	demos/test_treap.cpp
	src/treap.cpp
)

add_executable(executable_test_segtree
    demos/test_segment_treap.cpp
    src/segment_treap.cpp
    src/treap.cpp
)

add_executable(executable_test_solucion
    tests/test_solucion.cpp
    src/solution.cpp
    src/segment_treap.cpp
    src/treap.cpp
)

add_executable(executable_benchmark
	benchmark/benchmark.cpp
	src/solution.cpp
)

#Activacion de CTest
enable_testing()

add_test(NAME pruebas COMMAND executable_test_treap)
add_test(NAME prueba_solucion COMMAND executable_test_solucion)
