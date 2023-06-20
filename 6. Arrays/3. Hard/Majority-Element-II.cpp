// Majority Element II (Leetcode)
// Leetcode Link : https://leetcode.com/problems/majority-element-ii/description/

// Algorithm Used : Boyer-Moore Majority Voting Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1 = 0; // for tracking count of element1
        int count2 = 0; // for tracking count of element2
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        // finding the majority element(s)
        for(int i = 0; i < nums.size(); i++){
            if(count1 == 0 && nums[i] != element2){
                count1++;
                element1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != element1){
                count2++;
                element2 = nums[i];
            }
            else if(nums[i] == element1){
                count1++;
            }
            else if(nums[i] == element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        // checking the occurrence of the majority element(s) in nums[]
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element1) count1++;
            if(nums[i] == element2) count2++;
        }

        // checking if the majority element(s) occurs more than n/3 times or not
        int minimum = (int)(nums.size() / 3) + 1;
        if(count1 >= minimum) ans.push_back(element1);
        if(count2 >= minimum) ans.push_back(element2);

        return ans;
    }
};