// Rat in a Maze Problem - I (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Time Complexity : O(3^(n^2))
// Space Complexity : O(l*m) [where, l is the length of the path and m is the number of paths.]

class Solution {
  public:
    // Check if the next position is within bounds and is a valid path (1)
    bool isValid(int x, int y, vector<vector<int>> &mat){
        return (x >= 0 && x < mat.size() && y >= 0 && y < mat.size() && mat[x][y] == 1);
    }
  
    void solve(vector<vector<int>> &mat, int x, int y, string &path, vector<string> &ans){
        // If the destination is reached, add the current path to the answer list
        if(x == mat.size()-1 && y == mat.size()-1){
            ans.push_back(path);
            return;
        }
        
        // Arrays to track possible movements in all 4 directions (Up, Right, Down, Left)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // Map directions to their respective characters (U, R, D, L)
        map<int, char> mp = {
            {0, 'U'},
            {1, 'R'},
            {2, 'D'},
            {3, 'L'}
        };
        
        // Mark the current cell as visited (set it to 0)
        mat[x][y] = 0;
        
        // Explore all 4 directions
        for(int i = 0; i < 4; i++){
            int newX = x + delRow[i]; // Calculate new row
            int newY = y + delCol[i]; // Calculate new column
            
            // Check if the new position is valid
            if(isValid(newX, newY, mat)){
                path += mp[i]; // Add the direction to the path
                solve(mat, newX, newY, path, ans); // Recursively solve for the next position
                path.pop_back(); // Backtrack by removing the last direction
            }
        }
        
        // Unmark the current cell (set it back to 1) after exploring all directions
        mat[x][y] = 1;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        string path;
        // Start if the initial cell is not blocked
        if(mat[0][0] != 0){
            solve(mat, 0, 0, path, ans);
        }
        return ans;
    }
};