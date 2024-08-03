# Implement Stack using Linked List (GFG)
# GFG Link : https://shorturl.at/PfGbc

# Time Complexity : O(1)
# Space Complexity : O(1)

class MyStack:


    # class StackNode:

    # # Constructor to initialize a node
    # def __init__(self, data):
    #     self.data = data
    #     self.next = None
    
    def __init__(self):
        self.top = None
        
    #Function to push an integer into the stack.
    def push(self, data):

        # Add code here
        if self.top is None:
            self.top = StackNode(data)
        else:
            node = StackNode(data)
            node.next = self.top
            self.top = node


    #Function to remove an item from top of the stack.
    def pop(self):

        # Add code here
        if self.top is None:
            return -1
        
        value = self.top.data
        self.top = self.top.next
        
        return value