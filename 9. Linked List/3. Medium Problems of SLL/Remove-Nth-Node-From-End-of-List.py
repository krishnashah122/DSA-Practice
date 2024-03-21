# Remove Nth Node From End of List (Leetcode)
# Leetcode Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return None
        
        slow = fast = head

        # move fast pointer n steps ahead
        for _ in range(n):
            fast = fast.next
        
        # if the fast is None, means the head node should be deleted so return head.next
        if fast is None:
            return head.next
        
        # move slow and fast both pointers together one step at a time until fast reaches the last node
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        # when fast reaches the last node, slow will be pointing to the previous node of the node which need to be deleted
        slow.next = slow.next.next

        return head