#include <iostream>
using namespace std;

// Function to check if the given number is safe to place at the specified position
bool isSafe(int grid[9][9], int row, int col, int num) 
{
    // Check if the number already exists in the same row
    for (int i = 0; i < 9; i++) 
    {
        if (grid[row][i] == num) 
        {
            return false;
        }
    }

    // Check if the number already exists in the same column
    for (int i = 0; i < 9; i++) 
    {
        if (grid[i][col] == num) 
        {
            return false;
        }
    }

    // Check if the number already exists in the 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (grid[subgridStartRow + i][subgridStartCol + j] == num) 
            {
                return false;
            }
        }
    }

    // If the number is safe to place at the specified position
    return true;
}

// Function to solve the Sudoku puzzle recursively
bool solveSudoku(int grid[9][9]) 
{
    int row, col;

    // Find the first unassigned position in the grid
    bool isUnassigned = false;
    for (row = 0; row < 9; row++) 
    {
        for (col = 0; col < 9; col++) 
        {
            if (grid[row][col] == 0) 
            {
                isUnassigned = true;
                break;
            }
        }
        if (isUnassigned) 
        {
            break;
        }
    }

    // If all positions are assigned, the Sudoku puzzle is solved
    if (!isUnassigned) 
    {
        return true;
    }

    // Try placing numbers from 1 to 9 in the unassigned position
    for (int num = 1; num <= 9; num++) 
    {
        if (isSafe(grid, row, col, num)) 
        {
            // Place the number at the current position
            grid[row][col] = num;

            // Recursively solve the remaining Sudoku puzzle
            if (solveSudoku(grid)) 
            {
                return true;
            }

            // If the current placement leads to an incorrect solution, backtrack and try the next number
            grid[row][col] = 0;
        }
    }

    // If no number can be placed at the current position, backtrack and try a different path
    return false;
}

// Function to display the solved Sudoku puzzle
void displayGrid(int grid[9][9]) 
{
    for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++) 
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int grid[9][9];

    // Input the Sudoku puzzle (0 represents an unassigned position)
    cout << "Enter the Sudoku puzzle (use 0 for unassigned positions):" << endl;
    for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++) 
        {
            cin >> grid[row][col];
        }
    }

    // Solve the Sudoku puzzle
    if (solveSudoku(grid)) 
    {
        cout << "Sudoku puzzle solved successfully:" << endl;
        displayGrid(grid);
    } 
    else 
    {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
