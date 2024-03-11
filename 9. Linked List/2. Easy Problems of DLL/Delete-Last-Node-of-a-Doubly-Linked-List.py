# Delete Last Node of a Doubly Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/zDEI4

# Time Complexity : O(n)
# Space Complexity : O(1)

class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


# Do not change code above.


def deleteLastNode(head: Node) -> Node:
    # Write your code here
    if head is None or head.next is None:
        return None
    
    temp = head

    while temp.next:
        temp = temp.next
    
    temp.prev.next = None

    return head