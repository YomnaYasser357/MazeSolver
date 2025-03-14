#include <iostream>
#include <vector>
#include <stack>

// Constants to represent the maze
#define ROWS 5  // Row size of the maze
#define COLS 5  // Column size of the maze

using namespace std;

// Directions for navigating the maze (up, right, down, left)
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

// Class to represent the maze and solve it
class MazeSolver {
public:
    MazeSolver(int rows, int cols, vector<vector<int>> &maze) 
        : rows(rows), cols(cols), maze(maze) {}

    // Function to check if a position is within bounds and not a wall
    bool isSafe(int x, int y) {
        return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
    }

    // Function to solve the maze using DFS
    bool solveMaze(int startX, int startY, int endX, int endY) {
        // Stack to keep track of the path
        stack<pair<int, int>> path;
        // Visited array to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Start the DFS from the starting point
        path.push({startX, startY});
        visited[startX][startY] = true;

        while (!path.empty()) {
            auto [x, y] = path.top();
            path.pop();

            // If we've reached the destination
            if (x == endX && y == endY) {
                cout << "Solution Path (from start to end):\n";
                printPath(visited);
                return true;
            }

            // Explore all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];

                if (isSafe(newX, newY) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    path.push({newX, newY});
                }
            }
        }

        cout << "No path found!" << endl;
        return false;
    }

private:
    int rows, cols;
    vector<vector<int>> maze;

    // Function to print the visited path
    void printPath(const vector<vector<bool>>& visited) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j]) {
                    cout << "1 ";  // Mark visited cells
                } else {
                    cout << "0 ";  // Unvisited cells
                }
            }
            cout << endl;
        }
    }
};

int main() {
    // Example maze (0 = open path, 1 = wall)
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

    // Create MazeSolver object with the given maze
    MazeSolver solver(ROWS, COLS, maze);

    // Define start and end positions
    int startX = 0, startY = 0, endX = 4, endY = 4;

    // Solve the maze and print the path
    if (!solver.solveMaze(startX, startY, endX, endY)) {
        cout << "No path exists between the start and end!" << endl;
    }

    return 0;
}
