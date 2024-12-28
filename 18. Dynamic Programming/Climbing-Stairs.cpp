// Climbing Stairs (Leetcode)
// Leetcode Link : https://leetcode.com/problems/climbing-stairs/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int climbStairs(int n) {
        int prevStep = 1; // Initialize prevStep for the previous step
        int currStep = 1; // Initialize currStep for the current step

        for(int i = 2; i <= n; i++){
            int nextStep = prevStep + currStep; // Calculate next step as sum of prevStep and currStep
            prevStep = currStep; // Update prevStep to currStep
            currStep = nextStep; // Update currStep to nextStep
        }

        return currStep; // Return currStep as the final result
    }
};