#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};

public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%9][i/9] != otherGrid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i=0; i<9*9; i++) {
#ifdef PRINT
            printf("comparing grid(%d, %d)\n", i%9, i/9);
#endif
            if (grid[i%9][i/9] != other.grid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
    }

    // returns true if the given value is valid for the given row and column in the grid,
    // otherwise returns false
    bool valid(int val, int row, int column) {
        // checks if location already is assigned
        if (grid[row][column] != 0) {
            return false;
        }

        // checks if value appears in the same row or column
        for (int i = 0; i < 9; i++) {
            if (grid[row][i] == val || grid[i][column] == val) {
                return false;
            }
        }

        // checks if value appears in the same box
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + (row - row % 3)][j + (column - column % 3)] == val) {
                    return false;}
            }
        }
        return true;
    }

    bool findUnassignedLocation(int &row, int &column) {
        for (row = 0; row < 9; row++) {
            for (column = 0; column < 9; column++) {
                if (grid[row][column] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool solve() {
        // homework
        int row;
        int column;
        if (!findUnassignedLocation(row, column)) {
            return true;
        }
        for (int num = 1; num <= 9; num++) {
            if (valid(num, row, column)) {
                grid[row][column] = num;
                if (solve()) {
                    return true;
                }
                grid[row][column] = 0;
            }
        }
        return false;   // backtrack and try another value
    }
};
