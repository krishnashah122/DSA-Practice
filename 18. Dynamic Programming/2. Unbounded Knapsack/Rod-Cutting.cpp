// Rod Cutting (GFG)
// GFG Link : https://shorturl.at/HTa8Z

// Time Complexity : O(n * p)
// Space Complexity : O(n)

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        // Step 1: Initialize an array of size (n+1) with all values 0
        vector<int> dp(n+1, 0);
        
        // Step 2: Loop through each possible rod length
        for(int i = 1; i <= n; i++){
            // Step 3: Loop through rod lengths from i to n and update dp array
            for(int j = i; j <= n; j++){
                // Step 4: Update dp[j] by considering the maximum of including or excluding piece i
                dp[j] = max(price[i-1] + dp[j-i], dp[j]);
            }
        }
        
        // Step 5: Return the maximum profit obtainable for length n
        return dp[n];
    }
};