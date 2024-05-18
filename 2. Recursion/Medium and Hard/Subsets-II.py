# Subsets II (Leetcode)
# Leetcode Link : https://leetcode.com/problems/subsets-ii/description/

# Time Complexity : O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

# Space Complexity : O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        subsets = []

        def findSubsets(ind, ds):
            # Append the current subset to the list of subsets
            subsets.append(list(ds))
            for i in range(ind, n):
                # Check for duplicates
                if i != ind and nums[i] == nums[i-1]:
                    continue # Skip duplicates
                
                # Add the current number to the subset
                ds.append(nums[i])
                # Recursively call the function with updated index and subset
                findSubsets(i + 1, ds)
                # Backtrack by removing the last added element
                ds.pop()
        
        findSubsets(0, [])
        return subsets