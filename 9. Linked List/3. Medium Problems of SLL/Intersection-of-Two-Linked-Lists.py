# Intersection of Two Linked Lists (Leetcode)
# Leetcode Link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/

# Time Complexity : O(n1+n2)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        temp1 = headA
        temp2 = headB

        while temp1 != temp2:
            # if temp1 is not None, keep moving
            # if temp1 is None, point temp1 to headB
            temp1 = temp1.next if temp1 else headB

            # if temp2 is not None, keep moving
            # if temp2 is None, point temp2 to headA
            temp2 = temp2.next if temp2 else headA
        
        return temp1