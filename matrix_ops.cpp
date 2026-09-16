#include <iostream>
#include <windows.h>

void print()
{
    std:: cout<<"0"<< " Выход"<<"\n";
    std:: cout<<"1"<< " Напечатать"<<"\n";
    std:: cout<<"2"<< " Заполнить значением"<<"\n";
    std:: cout<<"3"<< " Создать матрицу"<<"\n";
    std:: cout<<"4"<< " Алгоритм варианта"<<"\n";
}
int** matrix_create(std::size_t n, std::size_t m)
{
    int** a=new int*[n];
    for(std:: size_t i=0;i<n;++i)
    {
        a[i]=new int[m]; 
    }
    return a;
}
void matrix_delete(int** a, std::size_t n)
{
    for(std:: size_t i=0;i<n;++i)
    {
        delete[] a[i];
    }
    delete[] a;
}
void matrix_fill(int** a, std::size_t n, std::size_t m)
{
    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = 0; j < m; ++j)
        {
            std::cin >> a[i][j];
        }
    }
}
void matrix_print(const int* const* a, std::size_t n, std::size_t m)
{
    for(std:: size_t i=0; i<n;++i)
    {
        for(std:: size_t j=0;j<m;++j)
            std:: cout<<a[i][j]<<" ";
        std:: cout<<"\n";
    }
}
int* matrix_spiral_read(const int* const* a, std::size_t n, std::size_t m, std::size_t& out_size)
{

    if (n == 0 || m == 0)
    {
        out_size = 0;
        return nullptr;
    }

    int *out;
    std:: size_t i=0;
    out= new int [n*m];
    out_size=n*m;
    std:: size_t top=0, bottom=n-1, rg=m-1,lf=0;

    while(top<=bottom && lf<=rg )
    {
        for (std:: size_t j=lf;j<=rg;++j)
        {
            out[i]=a[top][j];
            ++i;
        }
        top++;
        if (top<=bottom)
        {
            for(std:: size_t j=top;j<=bottom;++j)
            {
                out[i]=a[j][rg];
                ++i;
            }
            if (rg == 0)
                break;
            rg--;
        }
        if(lf<=rg && top<=bottom)
        {
            for(std:: size_t j=rg+1;j-->lf;)
            {
                out[i]=a[bottom][j];
                ++i;
            }
            if (bottom == 0)
                break;
            bottom--;
        }    
        if(lf<=rg && top<=bottom)
        {
            for (std::size_t j=bottom+1;j-->top;)
            {
                out[i]=a[j][lf];
                ++i;
            }
            lf++;
        }    
        
    }
    return out;
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
        else if(t==2)
        {
            if (a == nullptr)
                std::cout << "Матрица не создана\n";
        
            else
                std::cout << "Введите элементы матрицы\n";
                matrix_fill(a, n, m);
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