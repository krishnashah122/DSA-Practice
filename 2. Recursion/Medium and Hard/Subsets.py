# Subsets (Leetcode)
# Leetcode Link : https://leetcode.com/problems/subsets/description/

# Time Complexity : O(2^n)
# Space Complexity : O(2^n)

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        
        def solve(nums, op):
            # If input is empty, add the output i.e. ds to the ans
            if len(nums) == 0:
                ans.append(op)
                return
            
            # Making i/p smaller by erasing 1st element, ignoring element at index '0' for output
            solve(nums[1:], op.copy())
            # Making i/p smaller by erasing 1st element, taking element at index '0' for output
            solve(nums[1:], op + [nums[0]])
        
        solve(nums, [])
        return ans
