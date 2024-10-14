// N Digit numbers with digits in increasing order (GFG)
// GFG Link : https://www.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1

// Time Complexity : O(9^n)
// Space Complexity : O(n * 9^n)

class Solution {
  public:
    void solve(int n, vector<int> &nums, vector<int> &ans){
        // Base case: if n becomes 0, form a number from 'nums'
        if(n == 0){
            int num = 0;
            for(int i = 0; i < nums.size(); i++){
                num = num*10 + nums[i];  // Create the number from digits
            }
            ans.push_back(num);  // Add the number to the result
        }
        
        // Try adding digits from 1 to 9
        for(int i = 1; i <= 9; i++){
            if(nums.size() == 0 || nums.back() < i){  // Ensure digits are in increasing order
                nums.push_back(i);  // Add the digit
                solve(n-1, nums, ans);  // Recurse for the remaining digits
                nums.pop_back();  // Backtrack
            }
        }
    }
    
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int> ans;
        vector<int> nums;
        
        // Special case for single-digit numbers
        if(n == 1){
            for(int i = 0; i <= 9; i++){
                ans.push_back(i); // Add digits 0 to 9 to result
            }
        }else{
            solve(n, nums, ans);
        }
        
        return ans;
    }
};