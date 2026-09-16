// matrix_ops.h
#pragma once
#include <cstddef>
int** matrix_create(std::size_t n, std::size_t m); // массив указателей на строки
void matrix_delete(int** a, std::size_t n); // каждая строка, затем массив строк
void matrix_fill(int** a, std::size_t n, std::size_t m, int value);
void matrix_print(const int* const* i, std::size_t n, std::size_t m);