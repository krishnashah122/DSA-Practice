# Delete the Middle Node of a Linked List (Leetcode)
# Leetcode Link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return None
        
        fast = slow = head
        prev = slow

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        prev.next = slow.next

        return head