// Search in Rotated Sorted Array (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// GFG Link : https://bit.ly/3QH471y

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // if nums[mid] points to target
            if(nums[mid] == target) return mid;

            // if left part is sorted
            if(nums[low] <= nums[mid]){
                // if target lies between nums[low] & nums[mid] then search in left part otherwise in right part
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1; // to search in left part
                }
                else{
                    low = mid + 1; // to search in right part
                }
            }
            // if right part is sorted
            else{
                // if target lies between nums[mid] & nums[high] then search in right part otherwise in left part
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1; // to search in right part
                }
                else{
                    high = mid - 1; // to search in left part
                }
            }
        }
        return -1;
    }
};