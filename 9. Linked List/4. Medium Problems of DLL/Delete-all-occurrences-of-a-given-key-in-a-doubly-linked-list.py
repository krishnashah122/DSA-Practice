# Delete all occurrences of a given key in a doubly linked list (Code Studio)
# Code Studio Link : https://shorturl.at/befuC

# Time Complexity : O(n)
# Space Complexity : O(1)

class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


# Don't change the code above.


def deleteAllOccurrences(head: Node, k: int) -> Node:
    # Write your code here
    temp = head

    while temp:
        if temp.data == k:
            if temp == head:
                head = temp.next
            else:
                temp.prev.next = temp.next
        
        temp = temp.next
    
    return head
