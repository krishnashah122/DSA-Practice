// Count Number of Nice Subarrays (Leetcode)
// Leetcode Link : https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k){
        // If k is negative, there are no valid subarrays
        if(k < 0) return 0;

        int sum = 0;
        int countSubarr = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            // Increase the sum by adding remainder (i.e. 1) if the current number is odd
            sum += (nums[right] % 2);

            // Shrink the window from the left if there are more than 'k' odd numbers
            while(sum > k){
                sum -= (nums[left] % 2);
                left++;
            }

            // Add the number of valid subarrays ending at 'right' to the count
            countSubarr += (right - left + 1);
        }

        return countSubarr;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // Count subarrays with at most 'k' odd numbers
        int countSubarr1 = countSubarrays(nums, k);
        // Count subarrays with at most 'k-1' odd numbers
        int countSubarr2 = countSubarrays(nums, k-1);

        // Subtract countSubarr2 from countSubarr1 to get the no. of subarrays having 'k' odd numbers
        // Return the subtracted result
        return (countSubarr1 - countSubarr2);
    }
};