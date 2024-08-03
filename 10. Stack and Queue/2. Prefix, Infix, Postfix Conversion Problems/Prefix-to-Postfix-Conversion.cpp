// Prefix to Postfix Conversion (GFG)
// GFG Link : https://shorturl.at/gFV3Y

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
  public:
    string preToPost(string pre_exp) {
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
                // Form a new postfix expression with the operator at the end
                string s = s1 + s2 + ch;
                // Push the newly formed postfix expression back onto the stack
                st.push(s);
            }
        }
        
        // Return the top of the stack as it is the final postfix expression
        return st.top();
    }
};