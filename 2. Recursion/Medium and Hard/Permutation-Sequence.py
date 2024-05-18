# Permutation Sequence (Leetcode)
# Leetcode Link : https://leetcode.com/problems/permutation-sequence/description/

# Time Complexity : O(n^2)
# Space Complexity : O(n)

class Solution:
    # Function to find factorial
    def fact(self, n):
        factorial = 1
        for i in range(1, n+1):
            factorial = factorial * i
        return factorial

    def getPermutation(self, n: int, k: int) -> str:
        arr = []
        fact = 1
        ans = ''

        for i in range(n):
            arr.append(i + 1)
            fact = fact * (i + 1)
        
        def solve(arr, k, op):
            N = len(arr)
            nonlocal ans
            # If arr has only one element, add it with the 'op' and store it in 'ans'
            if N == 1:
                ans = op + str(arr[0])
                return
            
            # Block in which the the sequence lies
            block = k // self.fact(N - 1)
            # kth index of the block where the sequence lies
            k = k % self.fact(N - 1)
            # Add the element of arr at index 'block'
            op = op + str(arr[block])
            # Delete the element of arr at index 'block'
            del arr[block]
            solve(arr, k, op)
        
        solve(arr, k-1, '')
        return ans