// Flood Fill (Leetcode)
// Leetcode Link : https://leetcode.com/problems/flood-fill/description/

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& ans, int initialColor, int color, int delRow[], int delCol[]){
        ans[row][col] = color; // Change the color of the current cell
        int n = image.size();
        int m = image[0].size();

        // Explore the four possible directions (up, right, down, left)
        for(int i = 0; i < 4; i++){
            int r = row + delRow[i];
            int c = col + delCol[i];

            // Check if the new position is within bounds, has the initial color, and is not already colored
            if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initialColor && ans[r][c] != color){
                // Recursively perform DFS on the new position
                dfs(image, r, c, ans, initialColor, color, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc]; // Get the initial color at the starting position
        vector<vector<int>> ans = image; // Create a copy of image to store the result
        int delRow[] = {-1, 0, 1, 0}; // Array to move row index in four directions (up, right, down, left)
        int delCol[] = {0, 1, 0, -1}; // Array to move column index in four directions (up, right, down, left)
        dfs(image, sr, sc, ans, initialColor, color, delRow, delCol);
        return ans;
    }
};