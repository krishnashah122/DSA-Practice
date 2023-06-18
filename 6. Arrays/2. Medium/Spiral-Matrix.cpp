// Spiral Matrix (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/spiral-matrix/description/
// GFG Link : https://bit.ly/3ppEJ53

// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0;
        int bottom = row-1;
        int left = 0;
        int right = col - 1;

        while(top <= bottom && left <= right){
            // from top to right
            for(int i = top; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // from top to bottom
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // check if there is single row or not, if not then print from right to left
            if(top <= bottom){
                // from right to left
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // check if there is still elements, if not then it will not print from bottom to top
            if(left <= right){
                // from bottom to top
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};