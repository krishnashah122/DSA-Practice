# Implement Queue using Linked List (GFG)
# GFG Link : https://shorturl.at/skF1u

# Time Complexity : O(1)
# Space Complexity : O(1)

# A linked list (LL) node 
# to store a queue entry 
class Node: 
      
    def __init__(self, data): 
        self.data = data 
        self.next = None
        
class MyQueue:
    
    def __init__(self):
        self.front = None
        self.rear = None
    
    #Function to push an element into the queue.
    def push(self, item): 
         
        #Add code here
        if self.front is None or self.rear is None:
            self.rear = Node(item)
            self.front = self.rear
        else:
            node = Node(item)
            self.rear.next = node
            self.rear = self.rear.next
    
    #Function to pop front element from the queue.
    def pop(self):
         
        #add code here
        if self.front is None or self.rear is None:
            return -1
        
        value = self.front.data
        self.front = self.front.next
        
        return value