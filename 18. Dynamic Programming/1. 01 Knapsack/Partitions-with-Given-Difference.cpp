// Partitions with Given Difference (GFG)
// GFG Link : https://shorturl.at/ia3NO

// Time Complexity : O(n * s1)
// Space Complexity : O(n * s1)

class Solution {
  public:
    // Function to count the number of subsets with sum s1
    int countSubsetSum(int n, vector<int> &arr, int s1){
        int MOD = 1e9 + 7;
        
        // Step 1: Create a DP table to store the number of ways to achieve each sum
        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));

        // Step 2: There is one way to make sum 0 (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Step 3: Fill the DP table using the subset sum logic
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % MOD; // Include or exclude current element
                } else {
                    dp[i][j] = dp[i - 1][j]; // Exclude current element
                }
            }
        }

        // Step 4: Return the result from the last cell
        return dp[n][s1];
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        // Step 1: Calculate the total sum of the array
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        // Step 2: Check if (sum + d) is even; if not, return 0
        if ((sum + d) % 2 != 0) {
            return 0;
        }

        // Step 3: Calculate the target subset sum s1
        int s1 = (sum + d) / 2;

        // Step 4: Find the number of subsets with sum equal to s1, return it
        return countSubsetSum(n, arr, s1);
    }
};