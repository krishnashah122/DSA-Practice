// Sum of Subarray Minimums (Leetcode)
// Leetcode Link : https://leetcode.com/problems/sum-of-subarray-minimums/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    // Function to find the indices of the next smaller element for each element in the array
    vector<int> NSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            // Pop elements from the stack while they are greater than or equal to the current element
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            // If stack is not empty, the top of the stack is the index of the next smaller element
            // Otherwise, set the result to the size of the array (indicating no smaller element found)
            ans[i] = !st.empty() ? st.top() : n;
            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    // Function to find the indices of the previous smaller element for each element in the array
    vector<int> PSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            // Pop elements from the stack while they are greater than the current element
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            // If stack is not empty, the top of the stack is the index of the previous smaller element
            // Otherwise, set the result to -1 (indicating no smaller element found)
            ans[i] = !st.empty() ? st.top() : -1;
            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int MOD = (int) (1e9 + 7);
        vector<int> prevSEE = PSEE(arr);
        vector<int> nextSE = NSE(arr);
        int total = 0;

        for(int i = 0; i < arr.size(); i++){
            // Calculate the number of subarrays where arr[i] is the minimum
            int left = i - prevSEE[i];
            int right = nextSE[i] - i;
            // Update the total sum using modulo to handle large numbers
            total = (total + (left * right * 1LL * arr[i])) % MOD;
        }

        return total;
    }
};