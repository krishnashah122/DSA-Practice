# Implement Stack using Queues (Leetcode)
# Leetcode Link : https://leetcode.com/problems/implement-stack-using-queues/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class MyStack:

    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x: int) -> None:
        # Add x to the q1
        self.q1.append(x)

        # Move all the elements of q2 to q1
        while len(self.q2) != 0:
            self.q1.append(self.q2.popleft())
        
        # Swap q1 and q2
        self.q1, self.q2 = self.q2, self.q1

    def pop(self) -> int:
        return self.q2.popleft()

    def top(self) -> int:
        return self.q2[0]

    def empty(self) -> bool:
        if len(self.q2) == 0:
            return True
        else:
            return False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()