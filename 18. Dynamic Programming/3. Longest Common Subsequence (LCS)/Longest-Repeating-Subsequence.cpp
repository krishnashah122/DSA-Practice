// Longest Repeating Subsequence (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
            
		    // Step 1: Create a copy of the original string
		    string s = str;

            // Step 2: Initialize DP table of size (n+1) x (n+1)
		    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

            // Step 3: Fill the DP table to find length of Longest Repeating Subsequence
		    for(int i = 1; i <= n; i++) {
		        for(int j = 1; j <= n; j++) {
		            if(str[i-1] == s[j-1] && i != j) {
		                // Match found, but at different indices, increment repeating subsequence length
		                dp[i][j] = 1 + dp[i-1][j-1];
		            } else {
		                // If they don’t match, take the maximum length found so far
		                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		            }
		        }
		    }
		    
		    // Step 4: Return the length of longest repeating subsequence
		    return dp[n][n];
		}
		
};