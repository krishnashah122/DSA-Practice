// Find length of longest subsequence (GFG)
// GFG Link : https://shorturl.at/SL8AI

// Time Complexity : O(N * M)
// Space Complexity : O(N * M)

int maxSubsequenceSubstring(string X, string Y, int N, int M){
    //code
    // Step 1: Initialize a DP table of size (N+1) x (M+1) with values 0
    vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
    
    int maxLen = 0; // Track the maximum subsequence length that matches as a substring in Y
    
    // Step 2: Fill the DP table
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(X[i-1] == Y[j-1]){
                // If character matches, add 1 to the previous common length
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                // If characters don't match, carry forward the previous best subsequence
                // length up to the previous character in X. This keeps the subsequence length 
                // unchanged in X without including X[i-1], which doesn’t match Y[j-1]
                dp[i][j] = dp[i-1][j];
            }
            // Step 3: Update maxLen to keep track of the longest subsequence found 
            // that matches as a substring in Y
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    
    return maxLen;
}