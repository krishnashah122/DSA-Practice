// Find Minimum in Rotated Sorted Array (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// GFG Link : https://bit.ly/3Az1OJ3

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high){
            int mid = low + (high - low) / 2;

            // if the search space is already sorted then return the first element
            if(nums[low] < nums[high]) return nums[low];

            // if nums[mid] > nums[high] then it means minimum element is in right part
            if(nums[mid] > nums[high]){
                low = mid + 1; // to search in right part
            }
            // if nums[mid] < nums[high] then it means minimum is in left part
            else{
                high = mid; // to search in left part including mid
            }
        }
        // return nums[low] as minimum element
        return nums[low];
    }
};