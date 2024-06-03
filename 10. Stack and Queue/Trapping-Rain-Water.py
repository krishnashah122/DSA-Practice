# Trapping Rain Water (Leetcode)
# Leetcode Link : https://leetcode.com/problems/trapping-rain-water/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        maxLeft = [0]*n # To store the max left of each element
        maxRight = [0]*n # To store the max right of each element

        # Set 1st element of height as max left of that 1st element
        maxLeft[0] = height[0]
        # Set last element of height as max right of that last element
        maxRight[n-1] = height[n-1]

        waterTrapped = 0

        # Fill maxLeft with max height to the left of each element
        for i in range(1, n):
            maxLeft[i] = max(maxLeft[i-1], height[i])
        
        # Fill maxRight with max height to the right of each element
        for i in range(n-2, -1, -1):
            maxRight[i] = max(maxRight[i+1], height[i])
        
        # Calculate trapped water at each index
        for i in range(n):
            waterTrapped += min(maxLeft[i], maxRight[i]) - height[i]
        
        return waterTrapped