# Combination Sum (Leetcode)
# Leetcode Link : https://leetcode.com/problems/combination-sum/description/

# Time Complexity : O(2^t*k) where t is the target, k is the average length
# Space Complexity : O(k*x), k is the average length and x is the no. of combinations

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        ans = []

        def findCombinationSum(ind, target, ds):
            # If reached end of candidates list and target is 0, append combination
            if ind >= n:
                if target == 0:
                    ans.append(ds[:])
                return
            
            # If current candidate can fit in target, add to combination and recurse
            if candidates[ind] <= target:
                ds.append(candidates[ind])
                findCombinationSum(ind, target-candidates[ind], ds)
                ds.pop()
            
            # Move to next index
            findCombinationSum(ind + 1, target, ds)
        
        findCombinationSum(0, target, [])
        return ans