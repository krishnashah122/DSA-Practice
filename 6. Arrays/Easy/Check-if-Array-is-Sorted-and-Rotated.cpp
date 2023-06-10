// Check if Array is Sorted and Rotated (Leetcode)
// Leetcode Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]){
                count++;
            }
        }
        if(count <= 1){
            return true;
        }
        return false;
    }
};

/*
Approach:
if array is sorted and rotated then, there is only 1 break point where (nums[i] > nums[i+1]),
if array is only sorted then, there is 0 break point.

-> Why am I doing %n??

Consider this case: nums = [2,1,3,4]

This case will give you result true without %n but it is not sorted and rotated. So we have to check last and first element also.
*/