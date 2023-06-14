// Sort Colors / Sort an array of 0s, 1s and 2s / Dutch National Flag Problem (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/sort-colors/description/
// GFG Link : https://bit.ly/3dsROaZ

// Algorithm Used : Dutch National Flag Algorithm (DNF Algorithm)
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3 pointers
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] < 1){ // i.e. nums[mid] == 0
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] > 1){ // i.e. nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};