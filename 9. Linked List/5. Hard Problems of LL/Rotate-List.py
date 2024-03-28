# Rotate List (Leetcode)
# Leetcode Link : https://leetcode.com/problems/rotate-list/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # if the LL is empty or has only one node, return the head
        if head is None or head.next is None:
            return head
        
        temp = head
        count = 0

        # calculate the length of the LL
        while temp:
            count += 1
            temp = temp.next
        
        # if LL length == k, return head of same LL
        if count == k:
            return head
        elif count < k:
            # if LL length < k, update k with (k % count) 
            k = k % count
        
        slow = fast = head

        # move fast pointer k steps ahead
        for _ in range(k):
            fast = fast.next
        
        # move slow and fast pointer with same speed until fast reaches the last node
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        # last node will point to the LL head
        fast.next = head
        # slow.next node is made head of the LL
        head = slow.next
        # slow.next will point to None as it is the tail node of the rotated LL
        slow.next = None

        return head