// Infix to Postfix (GFG)
// GFG Link : https://shorturl.at/efdR0

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
  public:
    // Function to return the precedence of an operator
    int precedence(char ch){
        if(ch == '+' || ch == '-'){
            return 1;
        }else if(ch == '*' || ch == '/'){
            return 2;
        }else if(ch == '^'){
            return 3;
        }else{
            return -1;
        }
    }
    
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string postfix;
        
        for(char &ch : s){
            // If the character is an operand, add it to postfix
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
                postfix += ch;
            }
            // Handle parentheses
            else if(ch == '(' || ch == ')'){
                if(ch == '('){
                    st.push(ch); // Push '(' onto the stack
                }else{
                    // Pop from the stack to postfix until '(' is found
                    while(st.top() != '('){
                        postfix += st.top();
                        st.pop();
                    }
                    st.pop(); // Discard the '(' from the stack
                }
            }
            // Handle operators
            else{
                // Pop from the stack to postfix while operators in the stack have higher or equal precedence
                while(!st.empty() && precedence(ch) <= precedence(st.top())){
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch); // Push the current operator onto the stack
            }
        }
        
        // Pop any remaining operators from the stack to postfix
        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
    }
};