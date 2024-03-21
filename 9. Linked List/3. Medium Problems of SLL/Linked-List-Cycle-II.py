# Linked List Cycle II (Leetcode)
# Leetcode Link : https://leetcode.com/problems/linked-list-cycle-ii/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # if slow and fast meet, there is a cycle
            if slow == fast:
                entry = head # initialized entry pointer at head

                # move entry and slow pointers by one step at a time until they meet
                while entry != slow:
                    slow = slow.next
                    entry = entry.next
                
                return entry # return the node where they meet, which is the start of the cycle
        
        return None