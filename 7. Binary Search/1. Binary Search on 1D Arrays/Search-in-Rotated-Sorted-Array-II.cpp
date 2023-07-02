// Search in Rotated Sorted Array II (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// GFG Link : https://bit.ly/3Rm85Nb

// Average Time Complexity : O(Logn)
// Worst Time Complexity : O(n/2) == O(n) [When it ends up reducing search space until low & high intersect.]
// Space Complexity : O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // if nums[mid] points to target
            if(nums[mid] == target) return true;

            // if nums[low], nums[mid] & nums[high] becomes equal
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){ // edge case
                // increament low & decreament high pointers
                low++;
                high--;
                // continue the process to again check the edge case
                continue;
            }

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
        return false;
    }
};