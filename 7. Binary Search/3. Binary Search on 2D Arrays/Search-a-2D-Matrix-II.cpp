// Search a 2D Matrix II (Leetcode & Code Studio)
// Leetcode Link : https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Code Studio Link : https://shorturl.at/eABU7

// Time Complexity : O(M+N)
// Space Complexity : O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = col - 1;

        while (low < row && high >= 0) {
            if (matrix[low][high] == target){
                return true;
            }
            else if (matrix[low][high] > target) {
                high--; // eliminate the colume
            }
            else {
                low++; // eliminate the row
            }
        }

        return false;
    }
};