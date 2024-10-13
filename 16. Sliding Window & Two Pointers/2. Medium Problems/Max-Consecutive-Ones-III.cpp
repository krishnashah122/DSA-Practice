// Max Consecutive Ones III (Leetcode)
// Leetcode Link : https://leetcode.com/problems/max-consecutive-ones-iii/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int maxLen = 0;

        for(int j = 0; j < n; j++){
            // Decrease the count of flips when a 0 is encountered
            if(nums[j] == 0){
                k--;
            }

            // Adjust the left boundary when flips exceed allowed `k`
            while(k < 0){
                if(nums[i] == 0){
                    k++;
                }
                i++;
            }
            // Update the maximum length of the window
            maxLen = max(maxLen, (j-i+1));
        }

        return maxLen;
    }
};