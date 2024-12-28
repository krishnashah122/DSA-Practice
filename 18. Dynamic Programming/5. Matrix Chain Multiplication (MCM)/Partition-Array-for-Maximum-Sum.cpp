// Partition Array for Maximum Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/partition-array-for-maximum-sum/description/

// Time Complexity : O(n * k)
// Space Complexity : O(n)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // Step 1: Initialize DP table with 0
        vector<int> dp(n+1, 0);

        // Step 2: Traverse the array from the end to the beginning
        for(int i = n-1; i >= 0; i--){
            int len = 0;
            int maxi = INT_MIN;
            int maxSum = INT_MIN;

            // Step 3: Explore all possible partitions of length up to 'k' starting at 'i'
            for(int j = i; j < min(i+k, n); j++){
                len++; // Increase current partition length
                maxi = max(maxi, arr[j]); // Track the maximum element in the partition

                // Step 4: Calculate the sum for the current partition + remaining partitions
                int sum = len * maxi + dp[j+1];
                maxSum = max(maxSum, sum); // Update maxSum for the partition ending at 'i'
            }

            // Step 5: Store the maximum sum for position 'i' in dp table
            dp[i] = maxSum;
        }

        // Step 6: Return the maximum sum for partitioning starting from index 0
        return dp[0];
    }
};