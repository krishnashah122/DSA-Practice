// Binary Search (Leetcode & GFG & Code Studio)
// Leetcode Link : https://leetcode.com/problems/binary-search/description/
// GFG Link : https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1
// Code Studio Link : https://www.codingninjas.com/studio/problems/binary-search_972

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2; // to avoid overflow

            if(nums[mid] == target){
                return mid;
            }
            // if nums[mid] > target then search in left side
            else if(nums[mid] > target){
                high = mid - 1;
            }
            // if nums[mid] < target then search in right side
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};