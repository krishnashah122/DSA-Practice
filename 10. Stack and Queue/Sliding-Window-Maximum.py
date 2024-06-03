# Sliding Window Maximum (Leetcode)
# Leetcode Link : https://leetcode.com/problems/sliding-window-maximum/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        que = deque() # Deque to store indices of the elements
        ans = []

        for i in range(n):
            # While que is not empty and element at indices at last of the que is >= to the current element
            while que and nums[que[-1]] <= nums[i]:
                # Pop the index from the rear
                que.pop()
            
            # Append the current index in the que
            que.append(i)

            # Remove the first element of que if it is outside the window
            if que[0] == i - k:
                # Pop the index front the front
                que.popleft()
            
            # If the window has k elements, append the max element of the current window in the ans
            if i >= k - 1:
                ans.append(nums[que[0]])
        
        return ans