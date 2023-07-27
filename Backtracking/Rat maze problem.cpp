//backtracking means checking all paths and finding the desired solution for us
//aur jo path check kr chuke hai and unpe answr nhi mila to unko discard kr do

//to is qusn me we have four steps to go for a mause left(L), right(R), up(U), down(D). aur hume ye alphabeticla order me solution dena hai ...
//means D, L, R, U ..hume isse order me chlna hai ...phle check ki d hai ya nhi ..agr hia tp chl do wrna chekc for l then r , thhen u 
//rat ka possible move tbhi ho skta hau jb jis block pe jaa rhe wo 1 ho , isVisited not equal to 1 ho aur jo block me hum move kr rhe hai 
//wo matrix ke andar ho..

#include <iostream>
using namespace std;

// Maze dimensions
#define N 4

// Function to print the solution matrix
void printPath(int visited[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if (x, y) is a valid position in the maze
bool isValidPosition(int maze[N][N], int visited[N][N], int x, int y)
{
    // If (x, y) is within the maze boundaries and the cell is unvisited
    return (x >= 0 && x < N && y >= 0 && y < N && visited[x][y] == 0 && maze[x][y] == 1);
}

// Recursive function to solve the rat maze problem using backtracking
void findPath(int maze[N][N], int visited[N][N], int x, int y) 
{
    // If the rat reaches the destination (bottom-right corner)
    if (x == N - 1 && y == N - 1) 
    {
        visited[x][y] = 1;
        printPath(visited);
        visited[x][y] = 0; // Backtrack
        return;
    }

    // Move down
    if (isValidPosition(maze, visited, x + 1, y)) 
    {
        visited[x + 1][y] = 1;
        findPath(maze, visited, x + 1, y);
        visited[x + 1][y] = 0; // Backtrack
    }

    // Move left
    if (isValidPosition(maze, visited, x, y - 1)) 
    {
        visited[x][y - 1] = 1;
        findPath(maze, visited, x, y - 1);
        visited[x][y - 1] = 0; // Backtrack
    }

    // Move right
    if (isValidPosition(maze, visited, x, y + 1)) 
    {
        visited[x][y + 1] = 1;
        findPath(maze, visited, x, y + 1);
        visited[x][y + 1] = 0; // Backtrack
    }

    // Move up
    if (isValidPosition(maze, visited, x - 1, y)) 
    {
        visited[x - 1][y] = 1;
        findPath(maze, visited, x - 1, y);
        visited[x - 1][y] = 0; // Backtrack
    }
}

// Function to solve the rat maze problem and print all possible paths
void solveRatMaze(int maze[N][N]) 
{
    int visited[N][N] = {{0}};

    visited[0][0] = 1; // Start from the top-left corner

    findPath(maze, visited, 0, 0);
}

// Driver code
int main() 
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {1, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveRatMaze(maze);

    return 0;
}



/*
This function printPath takes a 2D array path as a parameter and prints its contents. 
It simply iterates over the elements of the array and prints them row by row.
This function isValidPosition checks if the coordinates (x, y) are within the boundaries of the maze and if the cell has not been visited (path[x][y] == 0). 
It also checks if the cell in the maze is unblocked (maze[x][y] == 1).
This is the main recursive function findPath that solves the rat maze problem using backtracking. 
It takes the maze, the path array, and the current coordinates (x, y) as parameters. 
If the current position is the destination (bottom-right corner of the maze), it marks the position in the path array and returns true.
*/
