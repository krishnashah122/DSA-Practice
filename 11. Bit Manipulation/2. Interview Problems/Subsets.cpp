// Subsets (Leetcode)
// Leetcode Link : https://leetcode.com/problems/subsets/description/

// Time Complexity : O(2^n * n)
// Space Complexity : O(2^n * n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int noOfSubsets = (1 << n);
        vector<vector<int>> subsets;

        for(int i = 0; i < noOfSubsets; i++){
            vector<int> subset;
            // Iterate through each element of the input array
            for(int j = 0; j < n; j++){
                // Check if the jth bit of i is set
                if(i & 1 << j){
                    // If yes, include the jth element of nums in the current subset
                    subset.push_back(nums[j]);
                }
            }
            subsets.push_back(subset);
        }

        return subsets;
    }
};