// Single Number (Leetcode)
// Leetcode Link : https://leetcode.com/problems/single-number/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // XOR every element of nums
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};