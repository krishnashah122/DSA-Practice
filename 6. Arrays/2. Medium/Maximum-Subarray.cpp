// Maximum Subarray / Kadane's Algorithm (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/maximum-subarray/
// GFG Link : https://bit.ly/3dzyloY

// Algorithm Used : Kadane's Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN; // maximum sum
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum > maxSum){
                maxSum = sum;
            }

            // if sum < 0 then discard the sum calculated
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};