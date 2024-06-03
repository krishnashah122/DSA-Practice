# Online Stock Span (Leetcode)
# Leetcode Link : https://leetcode.com/problems/online-stock-span/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        span = 1

        # Pop elements from the stack while the current price is greater or equal
        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]
        
        # Push the current price and span onto the stack
        self.stack.append((price, span))

        return span

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)