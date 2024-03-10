# Insert Node At The Beginning (Code Studio)
# Code Studio Link : https://shorturl.at/hDER6

# Time Complexity : O(1)
# Space Complexity : O(1)

class Node:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next


# Do not change code above.


def insertAtFirst(list: Node, newValue: int) -> Node:
    # Write your code here
    newNode = Node(newValue, list)
    head = newNode
    
    return newNode