// Sliding Window Maximum (Leetcode)
// Leetcode Link : https://leetcode.com/problems/sliding-window-maximum/description/

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maximums;
        list<int> lst;

        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            // If the window exceeds k, shrink the window
            if(k < (right-left+1)){
                // If the element leaving the window is the same as the maximum, remove it from the list
                if(nums[left] == lst.front()) lst.pop_front();
                left++; // Move the left boundary to the right
            }
            
            // While list is not empty and elements from the back of the list are <= the current element
            while(!lst.empty() && nums[right] > lst.back()){
                lst.pop_back(); // Remove it from the list
            }
            // Add the current element to the back of the list
            lst.push_back(nums[right]);

            // If the window size has reached k
            if(k == (right-left+1)){
                // The maximum of the current window is the front of the list
                maximums.push_back(lst.front());
            }
        }

        return maximums;
    }
};