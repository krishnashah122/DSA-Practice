// Binary Subarrays With Sum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int countSubarrays(vector<int>& nums, int goal){
        // If goal is negative, there can be no valid subarrays
        if(goal < 0) return 0;

        int sum = 0;
        int countSubarr = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right]; // Add the current element to the sum

            // Shrink the window from the left until the sum is less than or equal to goal
            while(sum > goal){
                sum -= nums[left];
                left++;
            }

            // Count all subarrays ending at 'right' and starting from any index between 'left' and 'right'
            countSubarr += (right - left + 1);
        }

        return countSubarr;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Count subarrays with sum <= goal
        int countSubarr1 = countSubarrays(nums, goal);
        // Count subarrays with sum <= (goal - 1) (to exclude those with exactly 'goal')
        int countSubarr2 = countSubarrays(nums, (goal-1));

        // Subtract countSubarr2 from countSubarr1 to get the no. of subarrays with sum 'goal'
        // Return the subtracted result
        return (countSubarr1 - countSubarr2);
    }
};