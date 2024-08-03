# Min Stack (Leetcode)
# Leetcode Link : https://leetcode.com/problems/min-stack/description/

# Time Complexity : O(1)
# Space Complexity : O(n)

class MinStack:
    
    def __init__(self):
        self.arr = [] # To store stack elements
        self.minElement = 0 # To store the minimum element

    def push(self, val: int) -> None:
        # If the stack is empty
        if not self.arr:
            # Simply append the value and set it as the minimum element
            self.arr.append(val)
            self.minElement = val
        else:
            # If the value is greater than or equal to the current minimum
            if val >= self.minElement:
                # Append the value
                self.arr.append(val)
            # If the value is less than the current minimum
            else:
                # Append a modified value and update the minimum element
                self.arr.append(2 * val - self.minElement)
                self.minElement = val

    def pop(self) -> None:
        if not self.arr:
            return -1
        
        # If the top element is greater than or equal to the current minimum
        if self.arr[-1] >= self.minElement:
            # Pop it directly
            popped = self.arr.pop()
        # If the top element is less than the current minimum
        else:
            # Retrieve the current minimum and update the minimum element using the modified value
            popped = self.minElement
            self.minElement = 2 * self.minElement - self.arr.pop()
        
        return popped

    def top(self) -> int:
        if not self.arr:
            return -1
        
        # If the top element is greater than or equal to the current minimum
        if self.arr[-1] >= self.minElement:
            # Return it
            return self.arr[-1]
        # If the top element is less than the current minimum
        else:
            # Return the current minimum
            return self.minElement

    def getMin(self) -> int:
        if not self.arr:
            return -1
        
        # Return the current minimum element
        return self.minElement


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
