// Find First and Last Position of Element in Sorted Array (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// GFG Link : https://bit.ly/3QuCFEP

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    // function to find the first occurrence
    int firstOccurrence(vector<int>& nums, int target){
        int first = -1;
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                first = mid;
                high = mid - 1; // to search in left half
            }
            else if(nums[mid] > target){
                high = mid - 1; // to search in left half
            }
            else{
                low = mid + 1; // to search in right half
            }
        }
        return first;
    }

    // function to find the last occurrence
    int lastOccurrence(vector<int>& nums, int target){
        int last = -1;
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                last = mid;
                low = mid + 1; // to search in right half
            }
            else if(nums[mid] > target){
                high = mid - 1; // to search in left half
            }
            else{
                low = mid + 1; // to search in right half
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // first occurrence of element
        int first = firstOccurrence(nums, target);

        // if element not exist then first and last occurrence will be -1
        if(first == -1) return {-1, -1};

        // last occurrence of element
        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};