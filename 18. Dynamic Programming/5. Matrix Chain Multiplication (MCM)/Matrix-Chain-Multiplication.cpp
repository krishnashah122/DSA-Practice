// Matrix Chain Multiplication (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Time Complexity : O(N^3)
// Space Complexity : O(N^2)

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // Step 1: Initialize DP table with 0
        vector<vector<int>> dp(N, vector<int> (N, 0));
        
        // Step 2: Traverse all chain lengths from 1 to N-2
        for(int len = 1; len < N-1; len++){
            // Step 3: Set start and end points of the chain
            for(int i = 0; i < N - len; i++){
                int j = len + i;
                int minimum = INT_MAX;
                
                // Step 4: Find minimum cost for splitting chain at each possible position
                for(int k = i; k < j; k++){
                    int temp = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    minimum = min(minimum, temp);
                }
                
                // Step 5: Update DP table with minimum cost for this chain
                dp[i][j] = minimum;
            }
        }
        
        // Step 6: Return minimum cost for multiplying matrices from 1 to N-1
        return dp[1][N-1];
    }
};