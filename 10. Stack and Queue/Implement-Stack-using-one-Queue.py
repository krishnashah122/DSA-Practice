# Implement Stack using one Queue (Leetcode)
# Leetcode Link : https://leetcode.com/problems/implement-stack-using-queues/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        # Add x to the q
        self.q.append(x)

        # Pop all the elements of q from front upto q.size-1 & append it to the rear of the q 
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self) -> int:
        return self.q.popleft()

    def top(self) -> int:
        return self.q[0]

    def empty(self) -> bool:
        if len(self.q) == 0:
            return True
        else:
            return False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()