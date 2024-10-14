// Expression Add Operators (Leetcode)
// Leetcode Link : https://leetcode.com/problems/expression-add-operators/description/

// Time Complexity : O(3^n)
// Space Complexity : O(n * 3^n)

class Solution {
public:
    // Recursive helper function to explore all possible expressions
    void solve(string num, int target, int index, long long prev, string expr, long long result, vector<string> &ans){
        // Base case: if we've processed the entire string
        if(index == num.size()) {
            // If the expression evaluates to the target, add expr to ans
            if(result == target) {
                ans.push_back(expr);
            }
            return;
        }

        string s;  // Current substring for the number being formed
        long long curr = 0;  // Current number value
        
        for(int i = index; i < num.size(); i++) {
            // Avoid numbers with leading zeros (except single digit '0')
            if(i > index && num[index] == '0') break;

            // Build the current number digit by digit
            s += num[i];
            curr = curr * 10 + (num[i] - '0');
            
            // If it's the first number, just initialize the expression
            if(index == 0) {
                solve(num, target, i + 1, curr, (expr + s), curr, ans);
            } else {
                // Try adding the '+' operator
                solve(num, target, i + 1, curr, (expr + "+" + s), result + curr, ans);
                // Try adding the '-' operator
                solve(num, target, i + 1, -curr, (expr + "-" + s), result - curr, ans);
                // Try adding the '*' operator
                solve(num, target, i + 1, prev * curr, (expr + "*" + s), result - prev + prev * curr, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, 0, "", 0, ans);
        return ans;
    }
};