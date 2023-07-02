#include <iostream>
using namespace std;

const int N = 4; // Size of the maze

// Function to print the solution matrix
void printSolution(int solution[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive function to solve the rat in a maze problem
void solveMazeUtil(int maze[N][N], int solution[N][N], int x, int y) 
{
    // Base case: If the rat reaches its destination
    if (x == N - 1 && y == N - 1) 
    {
        solution[x][y] = 1;
        printSolution(solution); // Print the solution path
        solution[x][y] = 0; // Reset the solution path for other paths
        return;
    }

    // Check if the current position is valid
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
    {
        // Mark the current position as part of the solution path
        solution[x][y] = 1;

        // Move right
        solveMazeUtil(maze, solution, x + 1, y);

        // Move down
        solveMazeUtil(maze, solution, x, y + 1);

        // If neither right nor down leads to the destination, backtrack
        solution[x][y] = 0;
    }
}

// Function to solve the rat in a maze problem
void solveMaze(int maze[N][N]) 
{
    int solution[N][N] = {0}; // Initialize solution matrix

    solveMazeUtil(maze, solution, 0, 0);
}

int main() 
{
    int maze[N][N] = 
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}
