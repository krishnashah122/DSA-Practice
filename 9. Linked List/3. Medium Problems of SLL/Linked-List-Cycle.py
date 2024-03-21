# Linked List Cycle (Leetcode)
# Leetcode Link : https://leetcode.com/problems/linked-list-cycle/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Approach 1: Using Hashmap
        # Time Complexity : O(n*2*Logn)
        # Space Complexity : O(n)

        # map = {}
        # temp = head

        # while temp:
        #     if temp in map:
        #         return True
            
        #     map[temp] = 1
        #     temp = temp.next
        
        # return False


        # Approach 2: Tortoise and Hare Algorithm OR Floyd's Cycle Finding Algorithm
        # Time Complexity : O(n)
        # Space Complexity : O(1)

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True
        
        return False