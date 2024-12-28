// Minimum sum partition (GFG)
// GFG Link : https://tinyurl.com/mr4x26nk

// Time Complexity : O(n*sum)
// Space Complexity : O(n*sum)

class Solution{

  public:
    // Function to find all the possible subset sums
    void subsetSum(int arr[], int n, int sum, vector<int> &s1){
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        
        // Step 1: Initialize dp array for base cases
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0) dp[i][j] = false; // No elements, no sum possible
                if(j == 0) dp[i][j] = true;  // Sum 0 is always possible with empty set
            }
        }
        
        // Step 2: Fill the dp array based on subset sum logic
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // Step 3: Collect possible subset sums up to sum/2
        for(int i = 0; i <= sum/2; i++){
            if(dp[n][i]){
                s1.push_back(i);
            }
        }
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int minDiff = INT_MAX;
        vector<int> s1;
        
        // Step 4: Calculate total sum of the array
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        
        // Step 5: Call subsetSum function to find all subset sums
        subsetSum(arr, n, sum, s1);
        
        // Step 6: Calculate the minimum difference between subset sums
        for(int i = 0; i < s1.size(); i++){
            minDiff = min(minDiff, (sum - 2*s1[i]));
        }
        
        return minDiff;
	} 
};