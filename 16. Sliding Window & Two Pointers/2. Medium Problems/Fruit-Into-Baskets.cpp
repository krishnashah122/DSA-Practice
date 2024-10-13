// Fruit Into Baskets (Leetcode & GFG)
// Leetcode Link : https://leetcode.com/problems/fruit-into-baskets/description/
// GFG Link : https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

// Time Complexity : O(n)
// Space Complexity : O(2) = O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        unordered_map<int, int> mp;
        int maxLen = 0;
        
        int left = 0;
        for(int right = 0; right < fruits.size(); right++){
            // Add the current fruit to the map and increase its count.
            mp[fruits[right]]++;
            
            // If the map size exceeds k (which means we have more than 2 types of fruits),
            // we need to shrink the window from the left.
            while(mp.size() > k){
                // Decrease the count of the fruit at the 'left' pointer.
                mp[fruits[left]]--;

                // If the count of that fruit becomes 0, remove it from the map.
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                
                // Move the left pointer to the right to shrink the window.
                left++;
            }
            
            // Calculate the length of the current valid window and update maxLen if it's larger.
            maxLen = max(maxLen, (right - left + 1));
        }
        
        return maxLen;
    }
};