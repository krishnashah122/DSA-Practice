# Implement Queue using Stacks (Leetcode)
# Leetcode Link : https://leetcode.com/problems/implement-queue-using-stacks/description/

# Time Complexity : O(n) or [Amortized O(1)]
# Space Complexity : O(n)

class MyQueue:

    def __init__(self):
        self.s1 = deque()
        self.s2 = deque()
        self.peekElement = -1

    def push(self, x: int) -> None:
        # If s1 is empty, store x as peek element
        if len(self.s1) == 0:
            self.peekElement = x
        
        self.s1.append(x)

    # Amortized O(1)
    def pop(self) -> int:
        # If s2 is empty, move all the elements from s1 to s2
        if len(self.s2) == 0:
            while len(self.s1) != 0:
                self.s2.append(self.s1.pop())
        
        # Return the top element of s2
        return self.s2.pop()

    def peek(self) -> int:
        # If s2 is empty, return peekElement as peek element
        if len(self.s2) == 0:
            return self.peekElement
        
        # Return the top element as peek element
        n = len(self.s2)
        peeked = self.s2[n - 1]

        return peeked

    def empty(self) -> bool:
        if len(self.s1) == 0 and len(self.s2) == 0:
            return True
        else:
            return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()