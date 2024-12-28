// Subset Sum Problem (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Time Complexity : O(sum * n)
// Space Complexity : O(sum * n)

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // Step 1: Create a dp table of size (n+1) x (sum+1), initialized to -1
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        // Step 2: Initialize the base cases
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0) dp[i][j] = false;  // No elements, can't form any non-zero sum
                if(j == 0) dp[i][j] = true;   // Sum 0 is possible with empty subset
            }
        }
        
        // Step 3: Fill the dp table iteratively based on inclusion/exclusion of current element
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(arr[i-1] <= j){  // Check if we can include the current element
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];  // Include or exclude
                }else{
                    dp[i][j] = dp[i-1][j];  // Exclude current element if it's larger than sum
                }
            }
        }
        
        return dp[n][sum];
    }
};