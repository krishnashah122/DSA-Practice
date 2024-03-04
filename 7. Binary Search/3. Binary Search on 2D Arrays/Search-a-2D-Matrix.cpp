// Search a 2D Matrix (Leetcode & Code Studio)
// Leetcode Link : https://leetcode.com/problems/search-a-2d-matrix/description/
// Code Studio Link : https://shorturl.at/iqUZ9

// Time Complexity : O(Log(m*n))
// Space Complexity : O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int rowIdx = mid / cols;
            int colIdx = mid % cols;

            if(matrix[rowIdx][colIdx] == target){
                return true;
            }
            else if(matrix[rowIdx][colIdx] < target){
                low = mid + 1; // to search in right part
            }
            else{
                high = mid - 1; // to search in left part
            }
        }
        return false;
    }
};