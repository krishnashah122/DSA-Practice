// Remove Duplicates from Sorted Array (Leetcode & GFG)

// Algorithm Used : Two Pointer Technique
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Two Pointers
        int first = 0;
        int second = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[first] == nums[second]){
                // Do noting
            }
            else{
                first++;
                nums[first] = nums[second];
            }
            second++;
        }
        return (first+1);
    }
};