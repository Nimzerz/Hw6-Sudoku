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

    // Returns true for every row/column location that is unassigned, returns false
    // if all locations within the grid are assigned. When returning true, the
    // row and column of the unassigned value is saved in the passed parameters.
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

    // https://www.geeksforgeeks.org/sudoku-backtracking-7/
    // Used link above as a reference; combined some sections to simplify the code
    // Returns true if the values chosen lead to a solution for the Sudoku problem,
    // returns false otherwise
    bool solve() {
        int row;
        int column;

        // if all locations are assigned, the Sudoku grid is solved
        if (!findUnassignedLocation(row, column)) {
            return true;
        }

        // test values 1 through 9
        for (int num = 1; num <= 9; num++) {
            // check that value is valid for the location in the grid
            if (valid(num, row, column)) {
                grid[row][column] = num; // assign value to location

                // check if value at location leads to a solution
                if (solve()) {
                    return true;
                }
                grid[row][column] = 0; // value did not lead to a solution
            }
        }

        return false; // backtrack and try another value
    }
};
