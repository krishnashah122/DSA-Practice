# The Celebrity Problem (GFG)
# GFG Link : https://shorturl.at/M09cp

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    
    #Function to find if there is a celebrity in the party or not
    def celebrity(self, M, n):
        # code here 
        stack = []
        
        # Push all the people in the stack
        for i in range(n):
            stack.append(i)
        
        # Find the potential celebrity
        while len(stack) > 1:
            # Pop two people from the stack
            first = stack.pop()
            second = stack.pop()
            
            # If first knows second, then first cannot be a celebrity
            if M[first][second] == 1:
                # Push second back onto the stack
                stack.append(second)
                # If first don't know second, then second cannot be a celebrity
            else:
                # Push first back onto the stack
                stack.append(first)
        
        # The last person remaining could be a celebrity
        celebrity = stack.pop()
        for i in range(n):
            # A celebrity should not know anyone and everyone should know the celebrity
            if i != celebrity and (M[celebrity][i] == 1 or M[i][celebrity] == 0):
                # If the candidate knows someone or someone doesn't know the candidate, the candidate is not a celebrity
                return -1
        
        return celebrity