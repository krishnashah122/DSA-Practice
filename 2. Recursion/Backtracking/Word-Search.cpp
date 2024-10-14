// Word Search (Leetcode)
// Leetcode Link : https://leetcode.com/problems/word-search/description/

// Time Complexity : O(m * n * 4^l) [where, l is the length of the word.]
// Space Complexity : O(l) [For recursive call stack]

class Solution {
public:
    // Function to check if the current point is out of bound, matches the word character, and is not visited
    bool isValid(vector<vector<char>> &board, pair<int, int> point, string word, int index){
        int x = point.first;
        int y = point.second;
        return (x >= 0 && x < board.size()
                && y >= 0 && y < board[0].size()
                && board[x][y] == word[index]
                && board[x][y] != '0');
    }

    // Recursive function to search for the word in the board starting from point and index
    bool solve(vector<vector<char>> &board, string word, pair<int, int> point, int index){
        // If we have matched all characters of the word
        if(index == word.size()-1){
            return true;
        }

        int delRow[] = {-1, 0, 1, 0}; // Row movement directions (up, right, down, left)
        int delCol[] = {0, 1, 0, -1}; // Column movement directions (up, right, down, left)

        // Save the value of current cell in temp and mark it as visited with '0'
        char temp = board[point.first][point.second];
        board[point.first][point.second] = '0';

        // Explore all 4 directions
        for(int k = 0; k < 4; k++){
            // Calculate new row and new column
            int newX = point.first + delRow[k];
            int newY = point.second + delCol[k];

            // Check if next cell is valid
            if(isValid(board, make_pair(newX, newY), word, index+1)){
                bool result = solve(board, word, make_pair(newX, newY), index+1); // Recur for next index
                if(result) return true; // If word is found, return true
            }
        }

        board[point.first][point.second] = temp; // Backtrack: Restore the value of the current cell
        return false; // Return false if no valid path is found
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                // Start search if first character matches
                if(board[i][j] == word[0]){
                    ans = solve(board, word, make_pair(i, j), 0);
                    if(ans) return ans; // Return true if word is found
                }
            }
        }
        
        return ans; // Return false if word is not found in the board
    }
};