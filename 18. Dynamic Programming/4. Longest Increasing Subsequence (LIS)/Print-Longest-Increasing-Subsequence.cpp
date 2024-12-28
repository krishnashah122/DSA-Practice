// Print Longest Increasing Subsequence (GFG)
// GFG Link : https://shorturl.at/1ykLF

// Time Complexity : O(n^2)
// Space Complexity : O(n)

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        // Step 1: Initialize DP array to track LIS length at each index
        vector<int> dp(n, 1);

        // Step 2: Hash array to track the previous index for LIS reconstruction
        vector<int> hash(n);
        vector<int> ans;

        // Step 3: Variables to store max LIS length and last index of LIS
        int LIS = 0;
        int lastIdx = 0;

        // Step 4: Build DP and hash arrays to find LIS length and path
        for(int idx = 0; idx < n; idx++){
            hash[idx] = idx;

            // Step 5: Check previous elements to potentially extend subsequence
            for(int prevIdx = 0; prevIdx < idx; prevIdx++){
                if(arr[prevIdx] < arr[idx] && 1 + dp[prevIdx] > dp[idx]){
                    dp[idx] = 1 + dp[prevIdx]; // Update LIS length at idx
                    hash[idx] = prevIdx; // Track previous index
                }
            }
            
            // Step 6: Update LIS length and last index if a longer subsequence is found
            if(dp[idx] > LIS){
                LIS = dp[idx];
                lastIdx = idx;
            }
        }

        // Step 7: Reconstruct the LIS sequence using the hash array
        ans.push_back(arr[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(arr[lastIdx]);
        }
        
        // Step 8: Reverse to get correct order
        reverse(ans.begin(), ans.end());

        // Step 9: Return the LIS
        return ans;
    }
};