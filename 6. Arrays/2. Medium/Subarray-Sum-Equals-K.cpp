// Subarray Sum Equals K (Leetcode & Code Studio)
// Leetcode Link : https://leetcode.com/problems/subarray-sum-equals-k/description/
// Code Studio Link : https://bit.ly/3p8JVxH

// Time Complexity : O(nLogn)
// Space Complexity : O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map will store the prefix sum and their count
        map<int, int>preSumMap;
        // set the value of 0 as 1 in the preSumMap
        preSumMap[0] = 1;
        int preSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            // calculate prefix sum
            preSum += nums[i];
            // calculate the prefix sum (i.e., preSum - k) of remaining subarray
            int rem = preSum - k;
            // add the occurrence of prefix sum (i.e., preSum - k) to our answer
            count += preSumMap[rem];
            // store the current prefix sum in preSumMap increasing its occurrence by 1
            preSumMap[preSum] += 1;
        }
        return count;
    }
};