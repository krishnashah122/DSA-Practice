// Largest Divisible Subset (Leetcode)
// Leetcode Link : https://leetcode.com/problems/largest-divisible-subset/description/

// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Initialize DP table for subset length at each index
        vector<int> dp(n, 1);
        vector<int> hash(n); // To track previous index for subset reconstruction
        vector<int> ans;
        
        int maxi = 0; // To track the maximum subset length
        int lastIdx = 0; // To track the last index of the largest subset

        // Step 2: Sort the array to ensure divisible condition works correctly
        sort(nums.begin(), nums.end());

        // Step 3: Fill DP and hash arrays for maximum subset length and path reconstruction
        for(int idx = 0; idx < n; idx++) {
            hash[idx] = idx;
            
            // Step 4: Check all previous elements to extend the divisible subset
            for(int prev = 0; prev < idx; prev++) {
                if(nums[idx] % nums[prev] == 0 && 1 + dp[prev] > dp[idx]) {
                    dp[idx] = 1 + dp[prev]; // Update subset length at idx
                    hash[idx] = prev; // Track previous index in subset
                }
            }

            // Step 5: Update maxi and lastIdx if a larger subset is found
            if(dp[idx] > maxi) {
                maxi = dp[idx];
                lastIdx = idx;
            }
        }

        // Step 6: Reconstruct the largest divisible subset using hash array
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }

        // Step 7: Return the largest divisible subset
        return ans;
    }
};