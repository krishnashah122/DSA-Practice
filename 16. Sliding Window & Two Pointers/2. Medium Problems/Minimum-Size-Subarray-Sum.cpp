// Minimum Size Subarray Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/minimum-size-subarray-sum/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int sum = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            // Add the current element to the sum.
            sum += nums[right];

            // Check if the current sum is greater than or equal to the target.
            while(sum >= target){
                // Update the minimum length if the current window size is smaller.
                minLen = min(minLen, (right - left + 1));

                // Shrink the window by subtracting the element at the left pointer.
                sum -= nums[left];

                // Move the left pointer to the right.
                left++;
            }
        }

        // If minLen was never updated (no valid subarray was found),
        // return 0. Otherwise, return the found minimum length.
        return minLen > nums.size() ? 0 : minLen;
    }
};