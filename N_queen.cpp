#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at position (row, col)
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check the row on the left side
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: All queens are placed successfully
    if (col == N) {
        // Print the solution
        cout << "Solution:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return true; // Return true to find all solutions
    }

    bool res = false;

    // Try placing the queen in each row of the current column
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place queens in the remaining columns
            res = solveNQueensUtil(board, col + 1, N) || res;

            // Backtrack: If placing queen in the current position doesn't lead to a solution
            board[i][col] = 0;
        }
    }

    return res;
}

// Function to solve the N-Queens problem
void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "No solution exists.\n";
    }
}

int main() {
    // Example usage for 8-Queens
    solveNQueens(4);

    return 0;
}
