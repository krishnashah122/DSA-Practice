# Delete Node Of Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/bdkBE

# Time Complexity : O(n)
# Space Complexity : O(1)

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Please do not change code above.


def deleteLast(list: Node) -> Node:
    # Write your code here
    if list is None or list.next is None:
        return None
    
    temp = list
    
    while temp.next.next:
        temp = temp.next

    temp.next = None

    return list