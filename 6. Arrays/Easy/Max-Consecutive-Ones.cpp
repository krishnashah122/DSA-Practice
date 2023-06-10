// Max Consecutive Ones (Leetcode)
// Leetcode Link : https://leetcode.com/problems/max-consecutive-ones/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                maximum = max(maximum, count);
            }
            else if(nums[i] == 0){
                count = 0;
            }
        }
        return maximum;
    }
};