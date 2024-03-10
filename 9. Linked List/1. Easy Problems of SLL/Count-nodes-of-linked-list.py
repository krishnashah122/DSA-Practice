# Count nodes of linked list (Code Studio)
# Code Studio Link : https://shorturl.at/iBEH3

# Time Complexity : O(n)
# Space Complexity : O(1)

'''
Following is the structure of the Node class already defined.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
'''

def length(head) :
    #Your code goes here
    length = 0

    temp = head
    while temp:
        temp = temp.next
        length += 1
    
    return length