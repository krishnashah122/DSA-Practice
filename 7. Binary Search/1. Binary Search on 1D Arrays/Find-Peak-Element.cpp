// Find Peak Element (Leetcode)
// Leetcode Link : https://leetcode.com/problems/find-peak-element/description/

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // if the array has only one element than return that element's index i.e. 0
        if(n == 1) return 0;
        // if first element > than second element then return first element's index i.e. 0
        if(nums[0] > nums[1]) return 0;
        // if last element > second last element then return last element's index i.e. (n - 1)
        if(nums[n-1] > nums[n-2]) return (n - 1);

        // search peak element between index 1 and (n - 2)
        int low = 1;
        int high = n - 2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            // if nums[mid] is greater than its predecessor and successor then return mid index
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){
                return mid;
            }

            // if nums[mid] is less than its predecessor
            if(nums[mid - 1] > nums[mid]){
                high = mid - 1; // to search in left part
            }
            // if nums[mid] is less than its successor
            else{
                low = mid + 1; // to search in right part
            }
        }
        return -1;
    }
};