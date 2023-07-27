//queen should satisfy 3 conditions 
//1st is ek row me 1 hi queen hogi 
//2nd is ek column me 1 hi queen hogi 
//3rd is koi queen dsure queen pe atack nhi kregi

//backtracing in this qusn is jb hum recursive call se wapas aaynge to jo queen place ke hai wo hta denge 

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) 
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) 
    {
        if (board[i][col] == 1) 
        {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) 
    {
        if (board[i][j] == 1) 
        {
            return false;
        }
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) 
    {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveNQueensHelper(vector<vector<int>>& board, int row, int n, vector<vector<vector<int>>>& solutions) 
{
    if (row == n) 
    {
        solutions.push_back(board); // Store the current valid solution
        return;
    }

    for (int col = 0; col < n; ++col) 
    {
        if (isSafe(board, row, col, n)) 
        {
            board[row][col] = 1; // Place the queen

            solveNQueensHelper(board, row + 1, n, solutions);

            board[row][col] = 0; // Backtrack and remove the queen
        }
    }
}

vector<vector<vector<int>>> solveNQueens(int n) 
{
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the board with 0's
    vector<vector<vector<int>>> solutions; // Store all valid solutions

    solveNQueensHelper(board, 0, n, solutions);

    return solutions;
}

void printBoard(const vector<vector<int>>& board) 
{
    for (const auto& row : board) 
    {
        for (int cell : row) 
        {
            cout << (cell == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() 
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<vector<int>>> ans = solveNQueens(n);

    if (!ans.empty()) 
    {
        cout << "All solutions found:\n";
        for (const auto& solution : ans) 
        {
            printBoard(solution);
            cout << endl;
        }
    } 
    else 
    {
        cout << "No solution found.\n";
    }

    return 0;
}




/*

This function isSafe checks whether it is safe to place a queen at a specific position (row, col) on the chessboard. 
It takes a reference to the board matrix, the current row and column indices, and the size n of the board. 
It checks three conditions: whether there is a queen in the same column, whether there is a queen in the upper left diagonal, and whether there is a queen in the upper right diagonal. 
If any of these conditions are met, it means placing a queen at the current position is not safe, and it returns false. 
Otherwise, it returns true indicating it is safe to place a queen at the current position.
This function solveNQueensUtil is a helper function that uses backtracking to solve the N-Queens problem. 
It takes a reference to the board matrix, the current row index, and the size n of the board. 
It first checks if the current row index is equal to the size of the board (n). 
If so, it means all queens are successfully placed, and it returns true.

If the current row is not the last row, it iterates through each column index. 
If it is safe to place a queen at the current position (determined by the isSafe function), it sets that cell in the board matrix to 1, 
indicating the placement of a queen. Then, it recursively calls solveNQueensUtil for the next row. 
If a solution is found (returned as true), it immediately returns true.

If a solution is not found with the current placement, it means we need to backtrack. 
In the backtracking step, we set the current cell back to 0, indicating that the queen is removed from that position. 
This allows us to explore other possibilities for placing queens in subsequent iterations.

The function returns false if no solution is found, indicating that we have exhausted all possibilities and cannot place queens on the board without attacking each other.

This function solveNQueens is the entry point for solving the N-Queens problem. It creates a board matrix of size n initialized with all 0s, representing an empty board.

It then calls the solveNQueensUtil function to solve the problem recursively. 
If a solution is found (indicated by solveNQueensUtil returning true), it returns the resulting board. 
Otherwise, it returns an empty board (an empty vector) to indicate that no solution is found.

This function printBoard takes the board matrix as input and prints its contents in a human-readable format. 
It iterates over each row and column of the matrix and prints "Q " if the cell contains a queen (value 1) or ". " if it's empty (value 0).

In the main function, the user is prompted to enter the value of N, which represents the size of the chessboard and the number of queens to be placed.

The solveNQueens function is called with the input value of N, and the resulting board is stored in the solution variable.

If a solution is found (the solution vector is not empty), it prints "Solution found:" and calls the printBoard function to 
display the board with queens represented by "Q" and empty cells represented by ".".

If no solution is found (the solution vector is empty), it prints "No solution found."

*/
