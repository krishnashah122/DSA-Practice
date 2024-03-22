# Remove duplicates from a sorted Doubly Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/dkpuw

# Time Complexity : O(n)
# Space Complexity : O(1)

class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


# Don't change the code above.


def removeDuplicates(head: Node) -> Node:
    # Write your code here
    curr = head

    while curr and curr.next:
        if curr.data == curr.next.data:
            temp = curr.next.next
            curr.next = temp
        else:
            curr = curr.next
        
    return head