# Maximal Rectangle (Leetcode)
# Leetcode Link : https://leetcode.com/problems/maximal-rectangle/description/

# Time Complexity : O(m*n)
# Space Complexity : O(n)

class Solution:
    # Function to calculate the maximum area of a histogram
    def maximumAreaHistogram(self, histogram):
        N = len(histogram)
        stack = [] # Stack to keep track of the nearest smaller element
        leftToRight = {}  # To store the nearest smaller element to the left
        rightToLeft = {}  # To store the nearest smaller element to the right

        # Loop to find the nearest smaller element from left to right
        for i in range(N):
            # Pop from stack until we find histogram height smaller than the current histogram
            while stack and histogram[stack[-1]] >= histogram[i]:
                stack.pop()
            
            # If stack is empty, there is no smaller element to the left
            if not stack:
                leftToRight[i] = -1
            # Index at the top of the stack has the nearest element to the left
            else:
                leftToRight[i] = stack[-1]
            
            stack.append(i)  # Push current index to the stack


        stack = []
        # Loop reverse to find the nearest smaller element from right to left
        for i in range(N-1, -1, -1):
            # Pop from stack until we find histogram height smaller than the current histogram
            while stack and histogram[stack[-1]] >= histogram[i]:
                stack.pop()
            
            # If stack is empty, there is no smaller element to the right
            if not stack:
                rightToLeft[i] = N
            # Index at the top of the stack has the nearest element to the left
            else:
                rightToLeft[i] = stack[-1]
            
            stack.append(i)  # Push current index to the stack


        maxHistogramArea = 0
        for i in range(N):
            # Width is determined by the nearest smaller elements to left and right
            width = rightToLeft[i] - leftToRight[i] - 1
            # Calculate the area with the width and the current bar
            histogramArea = width * histogram[i]
            # Update the maximum area found
            maxHistogramArea = max(maxHistogramArea, histogramArea)
        
        return maxHistogramArea

    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m = len(matrix)  # No. of rows
        n = len(matrix[0])  # No. of columns

        histogram = [0] * n  # Initialize histogram with zeros
        maxArea = 0
        # Loop through each row in the matrix
        for i in range(m):
            for j in range(n):
                # If matrix element is 0, reset the histogram bar
                if matrix[i][j] == '0':
                    histogram[j] = 0  # Reset the histogram bar if the matrix element is 0
                # If matrix element is 1, add it with the histogram bar
                else:
                    histogram[j] = histogram[j] + 1
                
            # Calculate the maximum area for the current histogram
            area = self.maximumAreaHistogram(histogram)
            maxArea = max(maxArea, area)  # Update the maximum area if a larger area is found
        
        return maxArea
