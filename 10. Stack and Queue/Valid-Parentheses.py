# Valid Parentheses (Leetcode)
# Leetcode Link : https://leetcode.com/problems/valid-parentheses/description/

# Time Complexity : O(n)
# Space Complexity : O(n)

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for ch in s:
            # If the character is an opening bracket
            if ch == '(' or ch == '{' or ch == '[':
                # Push the opening bracket onto the stack
                stack.append(ch)
            # If the character is a closing bracket
            else:
                # If the stack is empty, there is no matching opening bracket
                if len(stack) == 0:
                    return False
                
                # Pop the top element from the stack
                popped = stack.pop()
                # Check if the popped element matches the current closing bracket
                if popped == '(' and ch == ')':
                    continue
                elif popped == '{' and ch == '}':
                    continue
                elif popped == '[' and ch == ']':
                    continue
                # If the brackets do not match, return False
                else:
                    return False
        
        # After processing all characters, the stack should be empty if all brackets were matched
        if len(stack) != 0:
            return False
        
        # If the stack is empty, all brackets were matched correctly
        return True
