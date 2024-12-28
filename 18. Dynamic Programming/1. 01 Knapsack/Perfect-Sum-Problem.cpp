// Perfect Sum Problem (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// Time Complexity : O(sum * n)
// Space Complexity : O(sum * n)

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int MOD = 1e9 + 7;
        
        // Step 1: Create DP table, initializing all values to 0
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
        
        // Step 2: Base case - 1 way to make sum 0 (empty subset)
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        // Step 3: Fill DP table based on inclusion/exclusion of current element
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                // If we can include the current element
                if(arr[i-1] <= j){
                    // Calculate number of subsets with the current sum 'j'
                    // dp[i-1][j - arr[i-1]]: Count of subsets including arr[i-1]
                    // dp[i-1][j]: Count of subsets excluding arr[i-1]
                    // Add both counts and take modulo to prevent overflow
                    dp[i][j] = (dp[i-1][j - arr[i-1]] + dp[i-1][j]) % MOD; // Include or exclude the element
                }else{
                    dp[i][j] = dp[i-1][j]; // Exclude the element
                }
            }
        }
        
        return dp[n][sum];
	}
	  
};