# Tower Of Hanoi (GFG)
# GFG Link : https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

# Time Complexity : O(2^n)
# Space Complexity : O(n)

class Solution:
    def solve(self, N, fromm, to, aux, count):
        if N == 1:
            print("move disk", N, "from rod", fromm, "to rod", to)
            return 1
        
        count1 = self.solve(N-1, fromm, aux, to, count)
        print("move disk", N, "from rod", fromm, "to rod", to)
        count2 = self.solve(N-1, aux, to, fromm, count)
        count = 1 + count1 + count2
        return count
    
    def toh(self, N, fromm, to, aux):
        # Your code here
        return self.solve(N, fromm, to, aux, 0)