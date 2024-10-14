// Sudoku Solver (Leetcode)
// Leetcode Link : https://leetcode.com/problems/sudoku-solver/description/

// Time Complexity : O(n^(n^2))
// Space Complexity : O(1)

class Solution {
public:
    // Checks if it's safe to place 'num' in board[row][col]
    bool isSafe(vector<vector<char>> &board, int row, int col, int num){
        // Check the row and column for conflicts
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;
        }

        // Check the 3x3 sub-grid for conflicts
        int sRow = (row/3)*3;
        int sCol = (col/3)*3;
        for(int i = sRow; i < sRow+3; i++){
            for(int j = sCol; j < sCol+3; j++){
                if(board[i][j] == num) return false;
            }
        }

        return true; // It's safe to place 'num'
    }

    // Recursive helper function to solve the Sudoku board
    bool solve(vector<vector<char>> &board, int row, int col){
        // If the end of the board is reached, solution is found
        if(row == board.size()) return true;

        // Move to the next row if the end of the current row is reached
        if(col == board.size()) return solve(board, row+1, 0);

        // If the current cell is already filled, move to the next column
        if(board[row][col] != '.'){
            return solve(board, row, col+1);
        }else{
            // Try placing numbers '1' to '9' in the current cell
            for(char num = '1'; num <= '9'; num++){
                // If it's safe to place 'num', place it and continue solving
                if(isSafe(board, row, col, num)){
                    board[row][col] = num;
                    bool result = solve(board, row, col+1); // Recur for the next cell
                    if(result) return true; // If a solution is found, return true
                    board[row][col] = '.'; // Backtrack if placing 'num' didn't lead to a solution
                }
            }
        }
        return false; // Return false if no solution exists for this configuration
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
        return;
    }
};