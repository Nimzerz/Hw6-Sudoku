#include "gtest/gtest.h"
#include "sudoku.h"

TEST(sudoku, constructor) {
    int answer[9][9];
    for (int i=0; i<9; i++) {
        for (int j = 0; j < 9; j++) {
            answer[i][j] = 9 * i + j;
        }
    }

    Sudoku sudoku(answer);
    sudoku.print();
    Sudoku otherSudoku(sudoku);

    ASSERT_TRUE(sudoku==answer);
    answer[0][0] = 9;
    ASSERT_FALSE(sudoku==answer);

    ASSERT_TRUE(sudoku==otherSudoku);
    otherSudoku.set(0, 0, 9);
    ASSERT_FALSE(sudoku==otherSudoku);
}

TEST(sudoku, case1) {
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int answer[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                        {5, 2, 9, 1, 3, 4, 7, 6, 8},
                        {4, 8, 7, 6, 2, 9, 5, 3, 1},
                        {2, 6, 3, 4, 1, 5, 9, 8, 7},
                        {9, 7, 4, 8, 6, 3, 1, 2, 5},
                        {8, 5, 1, 7, 9, 2, 6, 4, 3},
                        {1, 3, 8, 9, 4, 7, 2, 5, 6},
                        {6, 9, 2, 3, 5, 1, 8, 7, 4},
                        {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    Sudoku sudoku(grid);
    sudoku.print();
    sudoku.solve();
    ASSERT_TRUE(sudoku==answer);
}

TEST(sudoku, case2) {
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int answer[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                        {5, 2, 9, 1, 3, 4, 7, 6, 8},
                        {4, 8, 7, 6, 2, 9, 5, 3, 1},
                        {2, 6, 3, 4, 1, 5, 9, 8, 7},
                        {9, 7, 4, 8, 6, 3, 1, 2, 5},
                        {8, 5, 1, 7, 9, 2, 6, 4, 3},
                        {1, 3, 8, 9, 4, 7, 2, 5, 6},
                        {6, 9, 2, 3, 5, 1, 8, 7, 4},
                        {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    Sudoku sudoku(grid);
    sudoku.solve();
    ASSERT_TRUE(sudoku==answer);
}

// https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html
TEST(sudoku, case3) {
    int grid[9][9] = {{8, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 3, 6, 0, 0, 0, 0, 0},
                      {0, 7, 0, 0, 9, 0, 2, 0, 0},
                      {0, 5, 0, 0, 0, 7, 0, 0, 0},
                      {0, 0, 0, 0, 4, 5, 7, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 3, 0},
                      {0, 0, 1, 0, 0, 0, 0, 6, 8},
                      {0, 0, 8, 5, 0, 0, 0, 1, 0},
                      {0, 9, 0, 0, 0, 0, 4, 0, 0}};

    int answer[9][9] = {{8, 1, 2, 7, 5, 3, 6, 4, 9},
                        {9, 4, 3, 6, 8, 2, 1, 7, 5},
                        {6, 7, 5, 4, 9, 1, 2, 8, 3},
                        {1, 5, 4, 2, 3, 7, 8, 9, 6},
                        {3, 6, 9, 8, 4, 5, 7, 2, 1},
                        {2, 8, 7, 1, 6, 9, 5, 3, 4},
                        {5, 2, 1, 9, 7, 4, 3, 6, 8},
                        {4, 3, 8, 5, 2, 6, 9, 1, 7},
                        {7, 9, 6, 3, 1, 8, 4, 5, 2}};

    Sudoku sudoku(grid);
    sudoku.solve();
    ASSERT_TRUE(sudoku==answer);
}
