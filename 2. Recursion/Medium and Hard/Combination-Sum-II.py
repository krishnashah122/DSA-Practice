# Combination Sum II (Leetcode)
# Leetcode Link : https://leetcode.com/problems/combination-sum-ii/description/

# Time Complexity : O(2^n*k) where, k is the average length of the combinations
# Space Complexity : O(k*x) where, k is the average length of the ds and x is the no. of combinations

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        candidates.sort()
        ans = []

        def findCombinationSum(ind, target, ds):
            # If target becomes 0, append the current combination to the answer list
            if target == 0:
                ans.append(ds[:])
                return
            
            for i in range(ind, n):
                # If the current candidate is greater than the remaining target, break the loop
                if target < candidates[i]:
                    break
                # If the current candidate is a duplicate of the previous one, skip it to avoid duplicates
                if i != ind and candidates[i] == candidates[i - 1]:
                    continue
                
                # Add the current candidate to the combination
                ds.append(candidates[i])
                # Recursively call the function with updated parameters
                findCombinationSum(i + 1, target - candidates[i], ds)
                # Remove the last added candidate to backtrack and explore other combinations
                ds.pop()
        
        findCombinationSum(0, target, [])
        return ans
