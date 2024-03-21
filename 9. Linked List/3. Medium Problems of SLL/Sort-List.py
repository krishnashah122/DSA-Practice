# Sort List (Leetcode)
# Leetcode Link : https://shorturl.at/nsCM7

# Time Complexity : O(nLogn)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # function to find the middle element of the LL
    def findMiddle(self, head):
        slow = head
        fast = head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow
    
    # function to merge two LL in sorted way
    def merge(self, leftHead, rightHead):
        dummy = ListNode(-1)
        temp = dummy

        while leftHead and rightHead:
            if leftHead.val <= rightHead.val:
                temp.next = leftHead
                leftHead = leftHead.next
            else:
                temp.next = rightHead
                rightHead = rightHead.next
            
            temp = temp.next
        
        temp.next = leftHead if leftHead else rightHead

        return dummy.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        middle = self.findMiddle(head)
        leftHead = head
        rightHead = middle.next
        middle.next = None

        leftLL = self.sortList(leftHead) # sort left LL
        rightLL = self.sortList(rightHead) # sort right LL
        
        return self.merge(leftLL, rightLL) # merge left LL and right LL