// N-Queens (Leetcode)
// Leetcode Link : https://leetcode.com/problems/n-queens/description/

// Time Complexity : O(n!)
// Space Complexity : O(n^2)

class Solution {
public:
    // Function to check if it's safe to place a queen at board[row][col]
    bool isSafe(int row, int col, vector<string> &board){
        int i = row;
        int j = col;
        
        // Check upper diagonal on the left side
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        // Check the left side of the current row
        i = row;
        j = col;
        while(j >= 0){
            if(board[i][j] == 'Q') return false;
            j--;
        }

        // Check lower diagonal on the left side
        i = row;
        j = col;
        while(j >= 0 && i < board.size()){
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }

        // It's safe to place the queen here
        return true;
    }

    // Recursive helper function to solve N-Queens by placing queens column by column
    void solve(vector<string> &board, int col, vector<vector<string>> &ans){
        // If all queens are placed, add the current board to the solution
        if(col == board.size()){
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each row for this column
        for(int row = 0; row < board.size(); row++){
            // Check if it is safe to place a queen at board[row][col]
            if(isSafe(row, col, board)){
                board[row][col] = 'Q'; // Place the queen
                solve(board, col+1, ans); // Recur to place the rest of the queens
                board[row][col] = '.'; // Backtrack by removing the queen
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, ans);
        return ans;
    }
};