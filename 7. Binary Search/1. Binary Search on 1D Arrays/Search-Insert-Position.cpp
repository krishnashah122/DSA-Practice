// Search Insert Position (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/search-insert-position/description/
// GFG Link : https://bit.ly/3pFDbUN

// Time Complexity : O(Logn)
// Space Complexity : O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1; // to search in left half
            }
            else{
                low = mid + 1; // to search in right half
            }
        }
        // if the target value can't be inserted between index 0 & n-1 then it will return n (default) index 
        return ans;
    }
};