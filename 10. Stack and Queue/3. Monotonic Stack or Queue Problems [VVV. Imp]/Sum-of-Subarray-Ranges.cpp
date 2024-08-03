// Sum of Subarray Ranges (Leetcode)
// Leetcode Link : https://leetcode.com/problems/sum-of-subarray-ranges/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    // Function to find the indices of the previous greater or equal element
    vector<int> PGEE(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            // Pop elements from the stack while they are less than or equal to the current element
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            // If stack is not empty, the top of the stack is the index of the previous greater or equal element
            // Otherwise, set the result to -1
            ans[i] = !st.empty() ? st.top() : -1;

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to find the indices of the next greater element
    vector<int> NGE(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            // Pop elements from the stack while they are less than the current element
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            // If stack is not empty, the top of the stack is the index of the next greater element
            // Otherwise, set the result to n
            ans[i] = !st.empty() ? st.top() : n;

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to find the indices of the previous smaller element
    vector<int> PSEE(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            // Pop elements from the stack while they are greater than or equal to the current element
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            // If stack is not empty, the top of the stack is the index of the previous smaller element
            // Otherwise, set the result to -1
            ans[i] = !st.empty() ? st.top() : -1;

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to find the indices of the next smaller element
    vector<int> NSE(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            // Pop elements from the stack while they are greater than the current element
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            // If stack is not empty, the top of the stack is the index of the next smaller element
            // Otherwise, set the result to n
            ans[i] = !st.empty() ? st.top() : n;

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<int> prevSEE = PSEE(nums);
        vector<int> nextSE = NSE(nums);
        vector<int> prevGEE = PGEE(nums);
        vector<int> nextGE = NGE(nums);
        long long totalMin = 0;
        long long totalMax = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long leftMin = i - prevSEE[i];  // Number of subarrays where nums[i] is the minimum
            long long rightMin = nextSE[i] - i;
            long long leftMax = i - prevGEE[i];  // Number of subarrays where nums[i] is the maximum
            long long rightMax = nextGE[i] - i;

            // Update the total sum for minimum and maximum values
            totalMin += (leftMin * rightMin * nums[i]);
            totalMax += (leftMax * rightMax * nums[i]);
        }

        // Return the difference between the sum of maximum and minimum values of all subarrays
        return (totalMax - totalMin);
    }
};
