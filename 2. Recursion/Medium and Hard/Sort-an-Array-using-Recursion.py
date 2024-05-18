# Sort an Array using Recursion

# Time Complexity : O(n^2)
# Space Complexity : O(n)

class Solution:
    def insert(self, nums, element):
        n = len(nums)
        if n == 0 or nums[n-1] <= element:
            nums.append(element)
            return
        
        lastElement = nums[n-1]
        nums.pop()
        self.insert(nums, element)
        nums.append(lastElement)

    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if len(nums) == 0:
            return
        
        lastElement = nums[n-1]
        nums.pop()
        self.sortArray(nums)
        self.insert(nums, lastElement)

        return nums