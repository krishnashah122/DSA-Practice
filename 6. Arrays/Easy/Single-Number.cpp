// Single Number (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/single-number/description/
// GFG Link : https://bit.ly/3dudCD8

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(int i = 0; i < nums.size(); i++){
            // xor all the elements of the array, at the end it contains that single number
            xor1 = xor1 ^ nums[i];
        }
        return xor1;
    }
};