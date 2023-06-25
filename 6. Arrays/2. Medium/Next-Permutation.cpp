// Next Permutation (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/next-permutation/description/
// GFG Link : https://bit.ly/3dug78u

// Time Complexity : O(3n) == O(n)
// Space Complexity : O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // step 1: find the break point
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                //index i is the break point
                index = i;
                break;
            }
        }

        // if break point doesn't exit
        if(index == -1){
            // reverse the whole array and return it
            reverse(nums.begin(), nums.end());
            return;
        }

        // step 2: find the next greater element if nums[index] and swap it with nums[index]
        for(int i = n-1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        // step 3: reverse the array right half
        reverse(nums.begin() + index + 1, nums.end());
        return;
    }
};