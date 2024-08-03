// Remove K Digits (Leetcode)
// Leetcode Link : https://leetcode.com/problems/remove-k-digits/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        // If k equals the length of num, return "0".
        if(k == num.size()) return "0";

        string result;
        stack<char> st;

        for(char &ch : num){
            // While stack is not empty and the top of the stack is greater than the current character
            // and we still have digits to remove (k > 0), pop the stack
            while(!st.empty() && st.top() > ch && k > 0){
                st.pop();
                k--;
            }
            // Push the current character onto the stack
            st.push(ch);
        }

        // If we still need to remove some digits
        while(k > 0){
            st.pop();
            k--;
        }

        // Build the result string from the stack
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        // Remove any leading zeros from the result string
        while(result.size() != 0 && result.back() == '0'){
            result.pop_back();
        }

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());

        // Return the result if it's not empty, otherwise return "0"
        return (!result.empty() ? result : "0");
    }
};