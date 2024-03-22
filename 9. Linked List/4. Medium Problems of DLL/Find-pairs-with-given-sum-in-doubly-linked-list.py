# Find pairs with given sum in doubly linked list (Code Studio)
# Code Studio Link : https://shorturl.at/dmuG5

# Time Complexity : O(n)
# Space Complexity : O(1)

class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


# Don't change the code above.


def findPairs(head: Node, k: int) -> [[int]]:

    # Write your code here.
    # Return boolean true or false.
    left = right = head
    ans = []

    while right.next:
        right = right.next
    
    while left.data < right.data:
        if left.data + right.data == k:
            ans.append([left.data, right.data])
            left = left.next
            right = right.prev
        elif left.data + right.data < k:
            left = left.next
        else:
            right = right.prev
    
    return ans
