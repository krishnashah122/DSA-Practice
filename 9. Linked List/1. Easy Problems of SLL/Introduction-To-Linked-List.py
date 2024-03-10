# Introduction To Linked List (Code Studio)
# Code Studio Link : https://shorturl.at/cqMY8

# Time Complexity : O(n)
# Space Complexity : O(n)

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Do not change code above.


def constructLL(arr: [int]) -> Node:
    # Write your code here
    if not arr:
        return None

    head = Node(arr[0])
    curr = head

    for i in range(1, len(arr)):
        newNode = Node(arr[i])
        curr.next = newNode
        curr = newNode

    return head   