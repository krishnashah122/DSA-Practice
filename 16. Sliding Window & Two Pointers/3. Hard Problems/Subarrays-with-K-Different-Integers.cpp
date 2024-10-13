// Subarrays with K Different Integers (Leetcode)
// Leetcode Link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// Time Complexity : O(n)
// Space Complexity : O(k)

class Solution {
public:
    // This function finds the number of subarrays that have at most 'k' distinct elements.
    int findSubarrays(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int countSubarr = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            mp[nums[right]]++; // Add the current element to the map and update its frequency.

            // If the map size is greater than 'k', shrink the window from the left.
            while(mp.size() > k) {
                mp[nums[left]]--; // Decrease the frequency of the element at 'left'.

                // If the frequency becomes 0, remove the element from the map.
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++; // Move the 'left' pointer to the right.
            }

            // The no. of subarrays ending at 'right' with at most 'k' distinct elements is (right - left + 1).
            countSubarr += (right - left + 1);
        }

        return countSubarr;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Count of subarrays with at most 'k' distinct elements.
        int countSubarr1 = findSubarrays(nums, k);

        // Count of subarrays with at most 'k-1' distinct elements.
        int countSubarr2 = findSubarrays(nums, k-1);

        // The difference gives the number of subarrays with exactly 'k' distinct elements.
        return (countSubarr1 - countSubarr2);
    }
};