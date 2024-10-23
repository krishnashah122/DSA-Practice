// Jump Game (Leetcode)
// Leetcode Link : https://leetcode.com/problems/jump-game/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0; // Maximum reachable index
        
        for(int i = 0; i < nums.size(); i++){
            // If current index is greater than the max reachable index, return false
            if(i > maxi) return false;
            maxi = max(maxi, i + nums[i]); // Update the maximum reachable index
        }

        return true; // If loop completes, jumping to the end is possible
    }
};