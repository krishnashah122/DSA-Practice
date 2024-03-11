# Insert at end of Doubly Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/cfgn1

# Time Complexity : O(n)
# Space Complexity : O(1)

class Node:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.prev = prev
        self.next = next


# Please do not change code above.


def insertAtTail(head: Node, k: int) -> Node:
    # Write your code here
    if head is None:
        return Node(k)
    
    temp = head

    while temp.next:
        temp = temp.next
    
    newNode = Node(k)
    temp.next = newNode
    newNode.prev = temp

    return head