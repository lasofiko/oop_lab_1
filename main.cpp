#include <iostream>
#include <windows.h>
#include "matrix_ops.h"

void print()
{
    std:: cout<<"0"<< " Выход"<<"\n";
    std:: cout<<"1"<< " Напечатать"<<"\n";
    std:: cout<<"2"<< " Заполнить значением"<<"\n";
    std:: cout<<"3"<< " Создать матрицу"<<"\n";
    std:: cout<<"4"<< " Алгоритм варианта"<<"\n";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::size_t n = 0, m = 0,t;
    int** a=nullptr;

    while(true){
        print();
        std:: cin>>t;
        if (t==0)
        {
            break;
        }
        else if(t==1)
        {
                if (a == nullptr)
                    std::cout << "Матрица не создана\n";
                
                else
                    matrix_print(a, n, m);
        }
        else if (t == 2)
            {
                if (a == nullptr)
                {
                    std::cout << "Матрица не создана\n";
                }
                else
                {
                    std::cout << "Введите элементы матрицы:\n";
                    matrix_fill(a, n, m);
                }
            }

        else if (t==3)
        {
                if (a != nullptr)
                {
                    matrix_delete(a, n);
                    a = nullptr;
                }

                std::cout << "Введите количество строк и столбцов\n";
                std::cin >> n >> m;

                a = matrix_create(n, m);
        }
        else if(t==4)
        {
                if (a == nullptr)
                    std::cout << "Матрица не создана\n";
                else
                {
                    std::size_t out_size;

                    int* out = matrix_spiral_read(a, n, m, out_size);

                    for (std::size_t i = 0; i < out_size; ++i)
                        std::cout << out[i] << " ";

                    std::cout << "\n";

                    delete[] out;
                }
        }
    }
    matrix_delete(a, n);
}