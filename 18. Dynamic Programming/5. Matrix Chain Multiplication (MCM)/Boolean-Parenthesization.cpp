// Boolean Parenthesization (GFG)
// GFG Link : https://shorturl.at/juEkF

// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

class Solution{
public:
    int solve(string &s, int i, int j, int isTrue, vector<vector<vector<long long>>> &dp){
        // Step 1: Base case - if the substring is invalid
        if(i > j) return 0;

        // Step 2: Base case - if the substring has only one character
        if(i == j){
            if(isTrue){
                return s[i] == 'T' ? 1 : 0;
            }else{
                return s[i] == 'F' ? 1 : 0;
            }
        }

        // Step 3: Check memoized result
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        long long ways = 0;
        int mod = 1003;

        // Step 4: Partition the expression around operators and recursively evaluate left and right substrings
        for(int k = i+1; k < j; k += 2){
            long long LT = solve(s, i, k-1, 1, dp) % mod; // True result for left part
            long long RT = solve(s, k+1, j, 1, dp) % mod; // True result for right part
            long long LF = solve(s, i, k-1, 0, dp) % mod; // False result for left part
            long long RF = solve(s, k+1, j, 0, dp) % mod; // False result for right part

            // Step 5: Calculate ways based on the current operator
            if(s[k] == '&'){
                if(isTrue){
                    ways = (ways + (LT * RT) % mod) % mod;
                }else{
                    ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
                }
            }else if(s[k] == '|'){
                if(isTrue){
                    ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LT * RT) % mod) % mod;
                }else{
                    ways = (ways + (LF * RF) % mod) % mod;
                }
            }else if(s[k] == '^'){
                if(isTrue){
                    ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
                }else{
                    ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
                }
            }
        }

        // Step 6: Memoize and return the result
        return dp[i][j][isTrue] = ways % mod;
    }

    int countWays(int n, string s){
        // code here
        // Step 7: Initialize a 3D DP table of size (n x n x 2) with all values set to -1
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (n, vector<long long> (2, -1)));

        // Step 8: Solve for the entire string with the desired result as true
        return solve(s, 0, n-1, 1, dp);
    }
};