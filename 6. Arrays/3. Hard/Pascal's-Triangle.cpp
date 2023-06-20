// Pascal's Triangle (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/pascals-triangle/
// GFG Link : https://bit.ly/3C95qlR

// Time Complexity : O(n^2)
// Space Complexity : O(1) [We are only using space to store the answer. So, Space Complexity can be O(1).]

class Solution {
public:
    // generate elements of pascal's triangle for a given row
    vector<int> generateRow(int row){
        int ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        // calculate nCr [i.e. (row-1)C(col-1)]
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        // store the entire pascal's triangle
        for(int row = 1; row <= numRows; row++){
            pascalTriangle.push_back(generateRow(row));
        }
        return pascalTriangle;
    }
};