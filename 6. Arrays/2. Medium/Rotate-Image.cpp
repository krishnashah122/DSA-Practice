// Rotate Image / Rotate by 90 degree (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/rotate-image/description/
// GFG Link : https://bit.ly/3PqpeV8

// Time Complexity : O(n^2 / 2) == O(n^2)
// Space Complexity : O(1)

// Rotate Matrix by 90 degree Clockwise
// Step 1: Transpose the matrix. 
// Step 2: Reverse the rows of the transposed matrix.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row and column

        // transpose the matrix
        // O(n/2 *n/2)
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the row of the matrix
        // O(n * n/2)
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Rotate Matrix by 90 degree Anti-Clockwise
// Step 1: First reverse the rows of the matrix.
// Step 2: Transpose the matrix whose rows has been reversed.
class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        // reverse the row of the matrix
        // O(n * n/2)
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // transpose the matrix
        // O(n/2 *n/2)
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    } 
};