# Copy List with Random Pointer (Leetcode)
# Leetcode Link : https://leetcode.com/problems/copy-list-with-random-pointer/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

"""
NOTE:
1. The copied nodes are created in between the original nodes, so there is no need for extra space for maintaining relationships or indexes. Therefore, no extra space proportional to the number of elements in the list is used.

2. The space used by the nodes themselves is not considered in the space complexity analysis as it is part of the output.
"""

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        temp = head

        # create deep copy of each node and insert the node just after the original node itself
        while temp:
            newNode = Node(temp.val, temp.next)
            temp.next = newNode
            temp = temp.next.next
        
        temp = head

        # point random pointer links among deep copy nodes
        while temp:
            temp.next.random = temp.random.next if temp.random else None
            temp = temp.next.next

        # create a dummy head for the deep copy LL
        dummy = newList = Node(-1)
        temp = head

        # extract deep copy nodes from original LL to form a separate deep copy LL
        while temp:
            newList.next = temp.next
            temp.next = newList.next.next
            newList = newList.next
            temp = temp.next
        
        # return dummy head's next node as the head of the deep copy LL
        return dummy.next
