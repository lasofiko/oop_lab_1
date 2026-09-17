#include <gtest/gtest.h>
#include "matrix_ops.h"

TEST(MatrixTest, Create)
{
    int** a = matrix_create(2, 3);

    ASSERT_NE(a, nullptr);
    ASSERT_NE(a[0], nullptr);
    ASSERT_NE(a[1], nullptr);

    matrix_delete(a, 2);
}


TEST(MatrixTest, Fill)
{
    int** a = matrix_create(2, 2);

    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(a[0][1], 2);
    EXPECT_EQ(a[1][0], 3);
    EXPECT_EQ(a[1][1], 4);

    matrix_delete(a, 2);
}

TEST(SpiralTest, OneByOne)
{
    int** a = matrix_create(1, 1);

    a[0][0] = 7;

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 1, 1, out_size);

    ASSERT_EQ(out_size, 1);
    EXPECT_EQ(out[0], 7);

    delete[] out;
    matrix_delete(a, 1);
}

TEST(SpiralTest, OneRow)
{
    int** a = matrix_create(1, 4);

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 1, 4, out_size);

    ASSERT_EQ(out_size, 4);

    EXPECT_EQ(out[0], 1);
    EXPECT_EQ(out[1], 2);
    EXPECT_EQ(out[2], 3);
    EXPECT_EQ(out[3], 4);

    delete[] out;
    matrix_delete(a, 1);
}

TEST(SpiralTest, OneColumn)
{
    int** a = matrix_create(4, 1);

    a[0][0] = 1;
    a[1][0] = 2;
    a[2][0] = 3;
    a[3][0] = 4;

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 4, 1, out_size);

    ASSERT_EQ(out_size, 4);

    EXPECT_EQ(out[0], 1);
    EXPECT_EQ(out[1], 2);
    EXPECT_EQ(out[2], 3);
    EXPECT_EQ(out[3], 4);

    delete[] out;
    matrix_delete(a, 4);
}

TEST(SpiralTest, TwoByTwo)
{
    int** a = matrix_create(2, 2);

    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 2, 2, out_size);

    ASSERT_EQ(out_size, 4);

    int expected[] = {1, 2, 4, 3};

    for (std::size_t i = 0; i < out_size; ++i)
    {
        EXPECT_EQ(out[i], expected[i]);
    }

    delete[] out;
    matrix_delete(a, 2);
}

TEST(SpiralTest, ThreeByThree)
{
    int** a = matrix_create(3, 3);

    int value = 1;

    for (std::size_t i = 0; i < 3; ++i)
    {
        for (std::size_t j = 0; j < 3; ++j)
        {
            a[i][j] = value++;
        }
    }

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 3, 3, out_size);

    ASSERT_EQ(out_size, 9);

    int expected[] =
    {
        1, 2, 3,
        6, 9, 8,
        7, 4, 5
    };

    for (std::size_t i = 0; i < out_size; ++i)
    {
        EXPECT_EQ(out[i], expected[i]);
    }

    delete[] out;
    matrix_delete(a, 3);
}

TEST(SpiralTest, TwoByThree)
{
    int** a = matrix_create(2, 3);

    int value = 1;

    for (std::size_t i = 0; i < 2; ++i)
    {
        for (std::size_t j = 0; j < 3; ++j)
        {
            a[i][j] = value++;
        }
    }

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 2, 3, out_size);

    ASSERT_EQ(out_size, 6);

    int expected[] =
    {
        1, 2, 3,
        6, 5, 4
    };

    for (std::size_t i = 0; i < out_size; ++i)
    {
        EXPECT_EQ(out[i], expected[i]);
    }

    delete[] out;
    matrix_delete(a, 2);
}

TEST(SpiralTest, ThreeByTwo)
{
    int** a = matrix_create(3, 2);

    int value = 1;

    for (std::size_t i = 0; i < 3; ++i)
    {
        for (std::size_t j = 0; j < 2; ++j)
        {
            a[i][j] = value++;
        }
    }

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 3, 2, out_size);

    ASSERT_EQ(out_size, 6);

    int expected[] =
    {
        1, 2, 4,
        6, 5, 3
    };

    for (std::size_t i = 0; i < out_size; ++i)
    {
        EXPECT_EQ(out[i], expected[i]);
    }

    delete[] out;
    matrix_delete(a, 3);
}

TEST(SpiralTest, EmptyMatrix)
{
    std::size_t out_size = 100;

    int* out =
        matrix_spiral_read(nullptr, 0, 0, out_size);

    EXPECT_EQ(out, nullptr);
    EXPECT_EQ(out_size, 0);
}

TEST(SpiralTest, FourByFour)
{
    int** a = matrix_create(4, 4);

    int value = 1;

    for (std::size_t i = 0; i < 4; ++i)
    {
        for (std::size_t j = 0; j < 4; ++j)
        {
            a[i][j] = value++;
        }
    }

    std::size_t out_size = 0;
    int* out = matrix_spiral_read(a, 4, 4, out_size);

    ASSERT_EQ(out_size, 16);

    int expected[] =
    {
        1, 2, 3, 4,
        8, 12, 16,
        15, 14, 13,
        9, 5,
        6, 7, 11, 10
    };

    for (std::size_t i = 0; i < out_size; ++i)
    {
        EXPECT_EQ(out[i], expected[i]);
    }

    delete[] out;
    matrix_delete(a, 4);
}