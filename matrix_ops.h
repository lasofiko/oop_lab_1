#pragma once
#include <cstddef>
int** matrix_create(std::size_t n, std::size_t m); 
void matrix_delete(int** a, std::size_t n); 
void matrix_fill(int** a, std::size_t n, std::size_t m);
void matrix_print(const int* const* i, std::size_t n, std::size_t m);
int* matrix_spiral_read(const int* const* a, std::size_t n, std::size_t m, std::size_t& out_size);