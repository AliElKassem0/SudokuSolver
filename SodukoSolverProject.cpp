#include <iostream>
#include <chrono>
using namespace std;

int grid[9][9] = {
{1, 2, 0, 9, 6, 0, 0, 0, 8},
{0, 5, 0, 0, 0, 3, 6, 0, 0},
{0, 0, 8, 1, 0, 0, 0, 2, 0},
{0, 6, 0, 4, 0, 0, 0, 0, 0},
{2, 0, 9, 0, 5, 0, 4, 0, 7},
{0, 0, 0, 0, 0, 2, 0, 1, 0},
{0, 1, 0, 0, 0, 7, 5, 0, 0},
{0, 0, 2, 8, 0, 0, 0, 7, 0},
{8, 0, 0, 0, 2, 9, 0, 6, 3}
};

bool is_Valid(int matrix[9][9], int row, int col, int num) {
    for (int x = 0; x < 9;x++) {
        if (matrix[row][x] == num || matrix[x][col] == num)
            return false;
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 3;j++) {
            if (matrix[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

bool solve(int matrix[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (matrix[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_Valid(matrix, row, col, num)) {
                        matrix[row][col] = num;
                        if (solve(matrix))
                            return true;
                        matrix[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(int matrix[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    if (solve(grid)) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Sudoku Solved:" << endl;
        printGrid(grid);
        cout << "\nTime taken for the entire program to run: " << elapsed.count() << " seconds.\n";
    }
    else {
        cout << " No Solution exists" << endl;
    }
    return 0;
}