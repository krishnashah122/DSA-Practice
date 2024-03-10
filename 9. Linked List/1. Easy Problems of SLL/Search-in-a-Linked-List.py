# Search in a Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/dBIQ6

# Time Complexity : O(n)
# Space Complexity : O(1)

'''
Following is the structure of the Node class already defined.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
'''

def searchInLinkedList(head, k):
    # Your code goes here.
    if head is None:
        return 0
    
    temp = head

    while temp:
        if temp.data == k:
            return 1
        temp = temp.next
    
    return 0