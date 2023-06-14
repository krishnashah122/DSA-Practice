// Max sum in sub-arrays (GFG)
// GFG Link : https://bit.ly/3SLFFhs

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long maxSum = INT_MIN;
        
        for(int i = 0; i < N-1; i++){
            maxSum = max(maxSum, arr[i] + arr[i+1]);
        }
        
        return maxSum;
    }
};