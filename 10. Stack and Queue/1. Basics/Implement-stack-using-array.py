# Implement stack using array (GFG)
# GFG Link : https://shorturl.at/Ak5jP

# Time Complexity : O(1)
# Space Complexity : O(n)

class MyStack:
    
    def __init__(self):
        self.top = -1
        self.arr=[0]*100
    
    #Function to push an integer into the stack.
    def push(self,data):
        #add code here
        self.top += 1
        self.arr[self.top] = data
    
    #Function to remove an item from top of the stack.
    def pop(self):
        #add code here
        if self.top == -1:
            return -1
        
        data = self.arr[self.top]
        self.top -= 1
        return data
        