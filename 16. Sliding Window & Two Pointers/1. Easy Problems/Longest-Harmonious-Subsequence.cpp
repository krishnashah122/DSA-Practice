// Longest Harmonious Subsequence (Leetcode)
// Leetcode Link : https://leetcode.com/problems/longest-harmonious-subsequence/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int longestSubsequence = 0;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++; // Increment the count for the current number
        }

        for(int i = 0; i < nums.size(); i++){
            // Check if the map contains the number that is one more than the current number
            if(mp.find(nums[i] + 1) != mp.end()){
                // Update the length of the longest harmonious subsequence if a longer one is found
                longestSubsequence = max(longestSubsequence, (mp[nums[i]] + mp[nums[i]+1]));
            }
        }

        return longestSubsequence;
    }
};