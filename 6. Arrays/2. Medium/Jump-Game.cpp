// Jump Game (Leetcode)
// Leetcode Link : https://leetcode.com/problems/jump-game/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int indexToReach = nums.size() - 1; // index that we have to reach

        // traverse from back to reach the first index i.e. 0
        for(int i = nums.size()-1; i >= 0; i--){
            // check if i + nums[i] is greater or equal to the index that we want to reach or not
            if(i + nums[i] >= indexToReach){
                // update the indexToReach to i
                indexToReach = i;
            }
        }

        // if indexToReach == 0, it means we have reach from last index to 0 index so return true
        if(indexToReach == 0) return true;

        // if not reached 0 index then return false
        return false;
    }
};