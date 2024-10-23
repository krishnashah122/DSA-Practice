// Jump Game II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/jump-game-ii/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0; // Range's left boundary
        int right = 0; // Range's right boundary
        int jumps = 0;

        // Loop until we reach the last position
        while(right < nums.size()-1){
            int farthest = 0;
            // Explore all positions within the current range
            for(int i = left; i <= right; i++){
                farthest = max(i + nums[i], farthest); // Calculate the farthest reachable position
            }
            left = right + 1; // Move left boundary next to the current range
            right = farthest; // Set farthest as the new right boundary
            jumps++; // Increment jump count
        }

        return jumps;
    }
};