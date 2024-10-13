// Longest Subarray of 1's After Deleting One Element (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int longestSubarr = 0;
        int length = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            // Shrink the window when k is less than 0 (i.e., more than one 0 has been encountered)
            while(k < 0){
                // If the left pointer points to a 0, increase k
                if(nums[left] == 0){
                    k++;
                } else {
                    // Otherwise, decrease the length since the left pointer points to a 1
                    length--;
                }
                // Move the left pointer to the right
                left++;
            }

            // If the current number is 0, we will remove it
            if(nums[right] == 0){
                k--; // Decrease k to indicate removal of 0
                length--;  // Decrease length for 0
            }

            // Otherwise, increase the length for this subarray
            length++;
            
            // Update the longest subarray length
            longestSubarr = max(longestSubarr, length);
        }

        // If the array has only 1's then return (size-1) as one 0 must be deleted, else return longestSubarr
        return (longestSubarr == nums.size()) ? nums.size() - 1 : longestSubarr;
    }
};