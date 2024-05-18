# Subset Sums (GFG)
# GFG Link : https://www.geeksforgeeks.org/problems/subset-sums2234/1

# Time Complexity : O(2^n)
# Space Complexity : O(2^n)

class Solution:
    def findSubsets(self, arr, n, ind, s, subsetSum):
        if ind >= n:
            subsetSum.append(s)
            return
        
        # pick the element at index 'ind'
        self.findSubsets(arr, n, ind + 1, s + arr[ind], subsetSum)
        
        # don't pick the element at index 'ind'
        self.findSubsets(arr, n, ind + 1, s, subsetSum)
    
	def subsetSums(self, arr, n):
		# code here
        s = 0
        subsetSum = []
        self.findSubsets(arr, n, 0, s, subsetSum)
        
        return subsetSum