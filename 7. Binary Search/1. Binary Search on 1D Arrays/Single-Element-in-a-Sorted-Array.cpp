// Single Element in a Sorted Array (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// GFG Link : https://bit.ly/3AllLTj

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // if array has only one element then return that element
        if(n == 1) return nums[0];
        // if first element != second element then return that first element
        if(nums[0] != nums[1]) return nums[0];
        // if last element != second last element then return that last element
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        // search element between index 1 and (n - 2)
        int low = 1;
        int high = n - 2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            // if nums[mid] is not equal to its predecessor & successor then return nums[mid]
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

            // if mid is even & nums[mid]==nums[mid+1] || if mid is odd & nums[mid]==nums[mid-1]
            if(mid%2 == 0 && nums[mid]==nums[mid+1] || mid%2 != 0 && nums[mid]==nums[mid-1]){
                low = mid + 1; // to search in right part
            }
            else{
                high = mid - 1; // to search in left part
            }
        }
        return -1;
    }
};