# Palindrome Linked List (Leetcode)
# Leetcode Link : https://shorturl.at/acryB

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head.next

        # find the middle of the LL
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # reverse the second half of the LL
        prev = None
        temp = slow.next

        while temp:
            front = temp.next
            temp.next = prev
            prev = temp
            temp = front

        # compare the first and the second half of the LL
        while prev:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next
        
        return True