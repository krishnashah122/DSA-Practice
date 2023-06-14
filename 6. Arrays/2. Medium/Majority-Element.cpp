// Majority Element (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/majority-element/description/
// GFG Link : https://bit.ly/3SSpeA3

// Algorithm Used : Boyer-Moore Majority Vote Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // for tracking the count of element
        int element = 0; // for which element we are counting

        // finding the majority element
        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
                count++;
            }
            else if(nums[i] == element){
                count++;
            }
            else{ // if nums[i] != element
                count--;
            }
        }

        // checking if majority element occurs more than n/2 times or not
        count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                count++;
            }
        }

        if(count > n/2){
            return element;
        }
        else{
            return -1;
        }
    }
};