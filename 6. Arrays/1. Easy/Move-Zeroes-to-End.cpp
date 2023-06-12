// Move Zeroes to End (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/move-zeroes/
// GFG Link : https://bit.ly/3PrGIjT

// Algorithm Used : Two Pointer Technique
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        // Find the first zero in the array
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        // Check whether the array length is 1 with zero in it or not
        if(j != -1){
            // Find the non-zero number and swap with zero
            for(int i = j+1; i< nums.size(); i++){
                if(nums[i] != 0){
                    swap(nums[j], nums[i]);
                    j++;
                }
            }
        }
    }
};