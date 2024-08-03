// Next Greater Element II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/next-greater-element-ii/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i = 2*n-1; i >= 0; i--){
            // Pop elements from the stack that are less than or equal to the current element
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }

            // If we are in the first half (i < n), set the answer
            if(i < n){
                // The top of the stack is the next greater element, or -1 if the stack is empty
                ans[i] = !st.empty() ? st.top() : -1;
            }

            // Push the current element onto the stack
            st.push(nums[i % n]);
        }

        return ans;
    }
};