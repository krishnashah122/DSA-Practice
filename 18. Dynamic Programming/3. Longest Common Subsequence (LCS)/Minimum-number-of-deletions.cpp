// Minimum number of deletions (GFG)
// GFG Link : https://shorturl.at/WJcvr

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

int minDeletions(string str, int n) { 
    //complete the function here
    // Step 1: Copy 'str' & reverse it to compare with the original
    string s = str;
    reverse(s.begin(), s.end());

    // Step 2: Initialize DP table of size (n+1) x (n+1)
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // Step 3: Fill the DP table to find the LCS length
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(str[i-1] == s[j-1]){
                // If characters match, increase the length of common subsequence
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                // If they don’t match, take the maximum length found so far
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // Step 4: Minimum no. of deletions (i.e, str.size() - LCS length)
    return (n - dp[n][n]);
} 