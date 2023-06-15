// Rearrange Array Elements by Sign (Leetcode)
// Leetcode Link : https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0); // vector of n size with every elements 0
        int posIndx = 0; // positive index
        int negIndx = 1; // negative index

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[posIndx] = nums[i];
                posIndx += 2;
            }
            else{ // if nums[i] < 0
                ans[negIndx] = nums[i];
                negIndx += 2;
            }
        }
        return ans;
    }
};