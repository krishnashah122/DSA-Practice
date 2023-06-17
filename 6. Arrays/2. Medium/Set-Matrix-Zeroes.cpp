// Set Matrix Zeroes (Leetcode)
// Leetcode Link : https://leetcode.com/problems/set-matrix-zeroes/description/

// Time Complexity : O(n*m)
// Space Complexity : O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRow = false; // flag to identify whether we need to mark first row to 0 or not
        bool firstCol = false; // flag to identify whether we need to mark first column to 0 or not

        // step 1: traverse the matrix and mark the first row and first column accordingly
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    // check if it is first row then set firstRow == true so that it will be mark 0
                    if(i == 0) firstRow = true;
                    // check if it is first column then set firstCol == true so that it will be mark 0
                    if(j == 0) firstCol = true;

                    // store state of rows and columns in the first row and first column
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // step 2: mark with 0 from (1,1) to (n-1, m-1)
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                // check for the column and row
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // step 3: check if firstRow == true, it means the first row should be marked to 0
        if(firstRow){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        // step 4: check if firstCol == true, it means the first column should be marked to 0
        if(firstCol){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};