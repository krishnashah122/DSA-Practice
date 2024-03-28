# Reverse Nodes in k-Group (Leetcode)
# Leetcode Link : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

# Time Complexity : O(n)
# Space Complexity : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # function to find the kth node
    def findKthNode(self, head, k):
        temp = head
        count = 1

        while count < k and temp:
            count += 1
            temp = temp.next
        
        return temp

    # function to reverse the LL
    def reverseList(self, head):
        temp = head
        prev = None

        while temp:
            front = temp.next
            temp.next = prev
            prev = temp
            temp = front
        
        return prev

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        temp = head
        prevNode = None

        while temp:
            # find the kth node
            kthNode = self.findKthNode(temp, k)
            
            # if kthNode is None
            if kthNode is None:
                # if there is prevNode, then link the last node with the current node (temp)
                if prevNode:
                    prevNode.next = temp

                # exit the loop
                break
            
            # store the next node of the kth node
            nextNode = kthNode.next
            # assign Node to the next of kth node to make it a LL
            kthNode.next = None
            
            self.reverseList(temp)

            # if temp is standing at the head, it means the first kth group is reversed
            # make kth node head
            if temp == head:
                head = kthNode
            else:
                # if temp is not standing at the head
                # link last node of previous LL to the kth node which is the head of the next LL
                prevNode.next = kthNode
            
            # point prevNode to the last node of the previous LL
            prevNode = temp
            # point temp to the first node of the next group
            temp = nextNode
        
        return head