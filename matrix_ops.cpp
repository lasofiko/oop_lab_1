#include "matrix_ops.h"
#include <iostream>

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
    if (a == nullptr)
        return;

    for (std::size_t i = 0; i < n; ++i)
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
