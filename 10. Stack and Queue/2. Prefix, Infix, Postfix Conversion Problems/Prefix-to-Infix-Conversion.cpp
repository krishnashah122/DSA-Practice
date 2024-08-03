// Prefix to Infix Conversion (GFG)
// GFG Link : https://shorturl.at/TjNVb

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int n = pre_exp.size();
        stack<string> st;
        
        for(int i = n-1; i >= 0; i--){
            string ch = string(1, pre_exp[i]);
            // If the character is an operand, push it onto the stack
            if((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z")){
                st.push(ch);
            }
            // If the character is an operator
            else{
                // Pop the top two operands from the stack
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                // Form a new infix expression with the operator between the two operands
                string s = "(" + s1 + ch + s2 + ")";
                // Push the newly formed infix expression back onto the stack
                st.push(s);
            }
        }
        
        // Return the top of the stack as it is the final infix expression
        return st.top();
    }
};