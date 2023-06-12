// Missing Number (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/missing-number/description/
// GFG Link : https://bit.ly/3A2pKTh

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 0; i < nums.size(); i++){
            // xor the first n natural numbers
            xor1 = xor1 ^ (i+1);
            // xor the nums[] elements
            xor2 = xor2 ^ nums[i];
        }
        // xor1 ^ xor2 will give the missing number
        return (xor1 ^ xor2);
    }
};