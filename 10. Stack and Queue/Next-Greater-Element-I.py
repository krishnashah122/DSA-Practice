# Next Greater Element I (Leetcode)
# Leetcode Link : https://leetcode.com/problems/next-greater-element-i/description/

# Time Complexity : O(n1+n2)
# Space Complexity : O(n2)

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = [] # Stack to keep track of next greater element
        map = {} # Dictionary to store the next greater element for each number in nums2
        ans = []

        n1 = len(nums1)
        n2 = len(nums2)
        # Traverse nums2 from the end to the beginning
        for i in range(n2-1, -1, -1):
            # Pop elements from the stack until the top of the stack is greater than nums2[i]
            while stack and stack[-1] <= nums2[i]:
                # Pop the top element of the stack
                stack.pop()
            
            # If the stack is not empty
            if stack:
                # Make a entry nums2[i] : stack's top in the map
                map[nums2[i]] = stack[-1]
            # If the stack is empty
            else:
                # Make a entry nums2[i] : -1 in the map
                map[nums2[i]] = -1
            
            # Push the current element onto the stack
            stack.append(nums2[i])
        
        # Iterate through nums1
        for i in range(n1):
            # Append the entry of map[nums1[i]] in the ans
            ans.append(map[nums1[i]])
        
        return ans
