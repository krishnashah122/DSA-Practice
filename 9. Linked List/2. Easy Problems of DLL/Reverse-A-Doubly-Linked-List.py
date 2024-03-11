# Reverse A Doubly Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/noHY5

# Time Complexity : O(n)
# Space Complexity : O(1)

'''
Following is the structure of the Node class already defined.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
        
'''

def reverseDLL(head):
    # Write your code here
    temp = head

    while temp.next:
        temp.prev, temp.next = temp.next, temp.prev
        temp = temp.prev
    
    temp.prev, temp.next = temp.next, temp.prev
    head = temp

    return head