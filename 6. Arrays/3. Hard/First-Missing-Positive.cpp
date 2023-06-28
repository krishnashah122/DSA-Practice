// First Missing Positive (Leetcode)
// Leetcode Link : https://leetcode.com/problems/first-missing-positive/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // check first missing from 1 to n
            if(nums[i] > 0 && nums[i] < n){
                // the original index where the element should be is nums[i] - 1
                int originalIndex = nums[i] - 1;

                // check if the element is present at its original index or not
                if(nums[i] != nums[originalIndex]){
                    // swap the current element with the element that is present at its original index
                    swap(nums[i], nums[originalIndex]);
                    i--; // to check the original index of element that swapped from originalIndex to i index
                }
            }
        }
        
        // iterate through the array and search for the first missing positive
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        // if all the element from 1 to n-1 is present then return n as the first missing positive
        return n + 1;
    }
};