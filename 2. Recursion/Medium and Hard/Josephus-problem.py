# Josephus problem (GFG)
# GFG Link : https://www.geeksforgeeks.org/problems/josephus-problem/1

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def solve(self, arr, ind, k):
        n = len(arr)
        if n == 1:
            return arr[0]
        
        delInd = (ind + k - 1) % n
        del arr[delInd]
        return self.solve(arr, delInd, k)
    
    def josephus(self,n,k):
        #Your code here
        arr = []
        
        for i in range(n):
            arr.append(i+1)
        
        return self.solve(arr, 0, k)