# Introduction To Doubly Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/vNOY6

# Time Complexity : O(n)
# Space Complexity : O(n)

class Node:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev


def constructDLL(arr: [int]) -> Node:
    # Write your code here
    if not arr:
        return None
    
    head = Node(arr[0])
    curr = head

    for i in range(1, len(arr)):
        newNode = Node(arr[i])
        newNode.next = curr.next
        newNode.prev = curr
        curr.next = newNode
        curr = newNode
    
    return head