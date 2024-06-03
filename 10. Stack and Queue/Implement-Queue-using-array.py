# Implement Queue using array (GFG)
# GFG Link : https://shorturl.at/WF7Ns

# Time Complexity : O(1)
# Space Complexity : O(n)

class MyQueue:
    
    def __init__(self):
        self.front = -1
        self.rear = -1
        self.arr = [0]*100000
    
    #Function to push an element x in a queue.
    def push(self, x):
        #add code here
        n = len(self.arr)
        if self.rear == n - 1:
            exit(1)
        
        if self.front == self.rear == -1:
            self.front += 1
        
        self.rear += 1
        self.arr[self.rear] = x
     
    #Function to pop an element from queue and return that element.
    def pop(self): 
        # add code here
        if self.front == -1:
            return -1
        
        if self.front == self.rear:
            x = self.arr[self.front]
            self.front = self.rear = -1
        else:
            x = self.arr[self.front]
            self.front += 1
        
        return x
        