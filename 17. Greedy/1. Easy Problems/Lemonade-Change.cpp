// Lemonade Change (Leetcode)
// Leetcode Link : https://leetcode.com/problems/lemonade-change/description/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Create a hashmap to store the count of 5, 10, and 20 dollar bills
        unordered_map<int, int> mp = {
            {5, 0},
            {10, 0},
            {20, 0}
        };

        for(auto bill : bills){
            mp[bill]++; // Increase the count for the current bill
            if(bill == 10){
                // If the customer pays with a $10 bill, try to give a $5 bill as change
                if(mp[5]){
                    mp[5]--; // Give one $5 bill as change
                }else{
                    return false; // If no $5 bill is available, return false
                }
            }else if(bill == 20){
                // If the customer pays with a $20 bill
                if(mp[5] && mp[10]){
                    mp[5]--; // Give one $5 bill
                    mp[10]--; // Give one $10 bill
                }else if(mp[5] >= 3){
                    mp[5] -= 3; // If no $10 bill, give three $5 bills as change
                }else{
                    return false; // If not enough bills for change, return false
                }
            }
        }

        return true; // If change was given successfully to all customers, return true
    }
};