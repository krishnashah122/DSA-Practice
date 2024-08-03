# Largest Rectangle in Histogram (Leetcode)
# Leetcode Link : https://leetcode.com/problems/largest-rectangle-in-histogram/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        leftToRight = {} # Dictionary to store the nearest smaller to left for each height
        rightToLeft = {} # Dictionary to store the nearest smaller to right for each height
        stack = [] # Stack to keep track of the nearest smaller elements

        # Loop through heights array to find the nearest smaller element to the left
        for i in range(n):
            # Pop from stack until we find a height shorter than the current height
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            
            # If stack is empty, no smaller element to the left
            if not stack:
                leftToRight[i] = -1
            # Index at the top of stack has the nearest smaller element to the left
            else:
                leftToRight[i] = stack[-1]
            
            # Push the current index onto the stack
            stack.append(i)
        

        stack = [] # Reset the stack to use for finding nearest smaller to right
        # Loop reverse through heights array to find the nearest smaller element to the right
        for i in range(n-1, -1, -1):
            # Pop from stack until we find a height shorter than the current height
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            
            # If stack is empty, no smaller element to the right
            if not stack:
                rightToLeft[i] = n
            # Index at the top of stack has the nearest smaller element to the right
            else:
                rightToLeft[i] = stack[-1]
            
            # Push the current index onto the stack
            stack.append(i)
        
        maxArea = 0
        for i in range(n):
            # Width of the rectangle is determined by the nearest smaller elements to left and right
            width = rightToLeft[i] - leftToRight[i] - 1
            # Calculate the area with the width and the current height
            area = width * heights[i]
            # Update the maximum area found
            maxArea = max(maxArea, area)
        
        return maxArea
                