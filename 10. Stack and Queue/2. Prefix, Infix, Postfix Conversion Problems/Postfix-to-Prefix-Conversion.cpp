// Postfix to Prefix Conversion (GFG)
// GFG Link : https://shorturl.at/0hzT4

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        
        for(auto &c : post_exp){
            string ch = string(1, c);
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
                // Form a new prefix expression with the operator at the beginning
                string s = ch + s2 + s1;
                // Push the newly formed prefix expression back onto the stack
                st.push(s);
            }
        }
        
        // Return the top of the stack as it is the final prefix expression
        return st.top();
    }
};