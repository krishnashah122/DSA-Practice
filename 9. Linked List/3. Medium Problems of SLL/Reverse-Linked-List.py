# Reverse Linked List (Leetcode)
# Leetcode Link : https://leetcode.com/problems/reverse-linked-list/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Approach 1: Iterative

        # temp = head
        # prev = None

        # while temp:
        #     front = temp.next
        #     temp.next = prev
        #     prev = temp
        #     temp = front
        
        # head = prev
        
        # return head


        # Approach 2: Recursion

        if head is None or head.next is None:
            return head
        
        newHead = self.reverseList(head.next)
        front = head.next
        front.next = head
        head.next = None

        return newHead